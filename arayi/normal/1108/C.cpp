#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector>
#include <ctime>
#include <set>
#include <iomanip>
#include <ctime>
#define fr first
#define sc second
#define lli long long int
using namespace std;
string s;
int main()
{
	int n;
	cin >> n;
	cin >> s;
	int dzev;
	//1 - R G B
	dzev = 1;
	int sum = 0, min;
	for (int i = 0; i < s.length(); i++)
	{
		if (i % 3 == 0 && s[i] != 'R')
			sum++;
		else if (i % 3 == 1 && s[i] != 'G')
			sum++;
		else if (i % 3 == 2 && s[i] != 'B')
			sum++;
	}
	min = sum;
	//2 - R B G
	sum = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (i % 3 == 0 && s[i] != 'R')
			sum++;
		else if (i % 3 == 1 && s[i] != 'B')
			sum++;
		else if (i % 3 == 2 && s[i] != 'G')
			sum++;
	}
	if (sum < min)
	{
		min = sum;
		dzev = 2;
	}
	//3 - B R G
	sum = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (i % 3 == 0 && s[i] != 'B')
			sum++;
		else if (i % 3 == 1 && s[i] != 'R')
			sum++;
		else if (i % 3 == 2 && s[i] != 'G')
			sum++;
	}
	if (sum < min)
	{
		min = sum;
		dzev = 3;
	}
	//4 - B G R
	sum = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (i % 3 == 0 && s[i] != 'B')
			sum++;
		else if (i % 3 == 1 && s[i] != 'G')
			sum++;
		else if (i % 3 == 2 && s[i] != 'R')
			sum++;
	}
	if (sum < min)
	{
		min = sum;
		dzev = 4;
	}
	//5 - G R B
	sum = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (i % 3 == 0 && s[i] != 'G')
			sum++;
		else if (i % 3 == 1 && s[i] != 'R')
			sum++;
		else if (i % 3 == 2 && s[i] != 'B')
			sum++;
	}
	if (sum < min)
	{
		min = sum;
		dzev = 5;
	}
	//6 - G B R
	sum = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (i % 3 == 0 && s[i] != 'G')
			sum++;
		else if (i % 3 == 1 && s[i] != 'B')
			sum++;
		else if (i % 3 == 2 && s[i] != 'R')
			sum++;
	}
	if (sum < min)
	{
		min = sum;
		dzev = 6;
	}
	cout << min << endl;
	if (dzev == 1)
	{
		for (int i = 0; i < s.length(); i++)
		{
			if (i % 3 == 0)
				cout << "R";
			else if (i % 3 == 1)
				cout << "G";
			else if (i % 3 == 2)
				cout << "B";
		}
	}
	if (dzev == 2)
	{
		for (int i = 0; i < s.length(); i++)
		{
			if (i % 3 == 0)
				cout << "R";
			else if (i % 3 == 1)
				cout << "B";
			else if (i % 3 == 2)
				cout << "G";
		}
	}
	if (dzev == 3)
	{
		for (int i = 0; i < s.length(); i++)
		{
			if (i % 3 == 0)
				cout << "B";
			else if (i % 3 == 1)
				cout << "R";
			else if (i % 3 == 2)
				cout << "G";
		}
	}
	if (dzev == 4)
	{
		for (int i = 0; i < s.length(); i++)
		{
			if (i % 3 == 0)
				cout << "B";
			else if (i % 3 == 1)
				cout << "G";
			else if (i % 3 == 2)
				cout << "R";
		}
	}
	if (dzev == 5)
	{
		for (int i = 0; i < s.length(); i++)
		{
			if (i % 3 == 0)
				cout << "G";
			else if (i % 3 == 1)
				cout << "R";
			else if (i % 3 == 2)
				cout << "B";
		}
	}
	if (dzev == 6)
	{
		for (int i = 0; i < s.length(); i++)
		{
			if (i % 3 == 0)
				cout << "G";
			else if (i % 3 == 1)
				cout << "B";
			else if (i % 3 == 2)
				cout << "R";
		}
	}
	return 0;
}