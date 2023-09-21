/*
Создайте структуру, содержащую имя и оценку учащегося (по шкале от 0 до 100). Спросите у
пользователя, сколько учеников он хочет ввести. Динамически выделите массив для хранения всех
студентов. Затем попросите пользователя ввести для каждого студента его имя и оценку. Как
только пользователь ввел все имена и оценки, отсортируйте список оценок студентов по убыванию
(сначала самый высокий бал). Затем выведите все имена и оценки в отсортированном виде.

Для следующего ввода:

Andre
74
Max
85
Anton
12
Josh
17
Sasha
90

Вывод должен быть следующим:

Sasha got a grade of 90
Max got a grade of 85
Andre got a grade of 74
Josh got a grade of 17
Anton got a grade of 12
*/
#include<iostream>
#include<string>

struct Students
{
	std::string name;
	int points;
};

void SortNames(Students *students, int length)
{
	for (int i{ 0 }; i < length; ++i)
	{
		int maxpoints = i;
		for (int j = i + 1; j < length; ++j)
		{
			if (students[maxpoints].points < students[j].points)
				maxpoints = j;
		}
		std::swap(students[i], students[maxpoints]);
	}
}



int main()
{
	setlocale(LC_ALL, "");
	std::cout << "Сколько учеников вы хотите ввести? ";
	int kolvo{ 0 };
	std::cin >> kolvo;
	Students* students = new Students[kolvo];
	for (int i{ 0 }; i < kolvo; ++i)
	{
		std::cout << "Enter name " << i + 1 << ":";
		std::cin >> students[i].name;
		do
		{
			std::cout << "Enter points " << i + 1 << ":";
			std::cin >> students[i].points;
		} while (!(students[i].points >= 0 && students[i].points <= 100));
	}

	SortNames(students, kolvo);

	for (int i{ 0 }; i < kolvo; ++i)
		std::cout << students[i].name << " got a grade of "<< students[i].points<<std::endl;
	
}