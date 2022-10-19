#include <iostream>
#include <string>
#include <string.h>
#define Loop int loop = 0; loop < t; loop++
#define LoopN int i = 0; i < n; i++
using namespace std;

int my_min(int a, int b)
{
	return a < b ? a : b;
}

int my_max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	string s[20000];
	int t;
	cin >> t;
	for (Loop)
	{
		cin >> s[loop];
	}
	for (Loop)
	{
		int d[4] = { 0 };
		for (int i = 0; i < s[loop].length(); i++)
		{
			switch (s[loop].at(i))
			{
			case 'U':d[0]++; break;
			case 'D':d[1]++; break;
			case 'L':d[2]++; break;
			case 'R':d[3]++; break;
			}
		}
		if (my_min(d[0], d[1]) == 0 && my_min(d[2], d[3]) == 0)
			cout << 0 << "\n\n";
		else if (my_min(d[0], d[1]) == 0)
			cout << 2 << "\nRL\n";
		else if (my_min(d[2], d[3]) == 0)
			cout << 2 << "\nUD\n";
		else
		{
			cout << 2 * (my_min(d[0], d[1]) + my_min(d[2], d[3])) << '\n';
			for (int i = 0; i < my_min(d[0], d[1]); i++)
				cout << 'U';
			for (int i = 0; i < my_min(d[2], d[3]); i++)
				cout << 'R';
			for (int i = 0; i < my_min(d[0], d[1]); i++)
				cout << 'D';
			for (int i = 0; i < my_min(d[2], d[3]); i++)
				cout << 'L';
			cout << '\n';
		}
	}
}