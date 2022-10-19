#include <iostream>
#include <string.h>
#define Loop int loop = 0; loop < t; ++loop
#define LoopN int i = 0; i < n; ++i
using namespace std;

int main()
{
	int t;
	char s[1500][6000];
	char c[1500][6000];
	cin >> t;
	for (Loop)
	{
		cin >> s[loop] >> c[loop];
		int sizeS = strlen(s[loop]);
		int sizeC = strlen(c[loop]);
		if (strcmp(s[loop], c[loop]) >= 0)
		{
			for (int i = 0; i < sizeS - 1; i++)
			{
				int min = i + 1;
				for (int j = i + 2; j < sizeS; j++)
				{
					if (s[loop][j] <= s[loop][min])
						min = j;
				}
				if (s[loop][min] < s[loop][i])
				{
					char h = s[loop][i];
					s[loop][i] = s[loop][min];
					s[loop][min] = h;
					break;
				}
			}
			if (strcmp(s[loop], c[loop]) >= 0)
				strcpy(s[loop], "---");
		}
	}

	for (Loop)
	{
		cout << s[loop] << '\n';
	}
}