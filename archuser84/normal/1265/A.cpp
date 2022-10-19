#include <iostream>
#include <string>
#define Loop int loop = 0; loop < t; loop++
#define LoopN int i = 0; i < n; i++
using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

char goodC(char a, char b)
{
	char ans = 'a';
	while (ans == a || ans == b)
		ans++;
	return ans;
}

int main()
{
	char s[1000][100010];
	int t;
	bool imp[1000] = { 0 };
	cin >> t;
	for (Loop)
	{
		cin >> s[loop];
		int size = strlen(s[loop]);
		if (size > 1)
		{
			if (s[loop][0] == '?')
				s[loop][0] = goodC(0, s[loop][1]);
			if (s[loop][0] == s[loop][1])
				imp[loop] = 1;
			else for (int i = 1; i < size - 1; i++)
			{
				if (s[loop][i] == '?')
					s[loop][i] = goodC(s[loop][i - 1], s[loop][i + 1]);
				else if (s[loop][i] == s[loop][i + 1])
				{
					imp[loop] = 1;
					break;
				}
			}
			if (s[loop][size - 1] == '?')
				s[loop][size - 1] = goodC(0, s[loop][size - 2]);
		}
		else if (s[loop][0] == '?')
			s[loop][0] = 'a';
	}
	for (Loop)
	{
		if (!imp[loop])
			cout << s[loop] << '\n';
		else
			cout << "-1\n";
	}
}