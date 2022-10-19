#include <iostream>
#include <string>
#define Loop int loop = 0; loop < t; loop++
#define LoopN int i = 0; i < n; i++
using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int t;
	string s[10000];
	cin >> t;
	for (Loop)
		cin >> s[loop];

	for (Loop)
	{
		int n = 0;
		int ind[50000];
		int size = s[loop].length();
		for (int i = 0; i < size - 2; i++)
		{
			if (s[loop].at(i) == 'o' && s[loop].at(i + 1) == 'n' && s[loop].at(i + 2) == 'e')
			{
				ind[n++] = i + 2;
				i += 2;
			}
			else if (s[loop].at(i) == 't' && s[loop].at(i + 1) == 'w' && s[loop].at(i + 2) == 'o')
			{
				if (i < size-4 && (s[loop].at(i + 3) == 'n' && s[loop].at(i + 4) == 'e'))
				{
					ind[n++] = i + 3;
					i += 4;
				}
				else
				{
					ind[n++] = i + 2;
					i += 2;
				}
			}
		}

		cout << n << '\n';
		for (LoopN)
			cout << ind[i] << ' ';
		cout << '\n';
	}
}