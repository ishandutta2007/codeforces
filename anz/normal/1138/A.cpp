#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

int n;
int sushi[100001];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> sushi[i];

	int start = 0;
	int result = 0;
	int i = 0;
	int first = sushi[i];

	int counter = 1;
	while (++i < n)
	{
		if (sushi[i] == first)
			counter++;
		else
			break;
	}
	while (i < n)
	{
		int another = 1;
		while (++i < n)
		{
			if (sushi[i] != first)
				another++;
			else
			{
				first = 3 - first;
				break;
			}	
		}

		if (counter <= another)
		{
			if (result < counter * 2)
				result = counter * 2;
		}
		else
		{
			if (result < another * 2)
				result = another * 2;
		}

		counter = another;
	}
	cout << result;
}