#include <iostream>
#include <string.h>
#define Loop int loop = 0; loop < t; ++loop
#define LoopN int i = 0; i < n; ++i
#define LoopM int j = 0; j < m; ++j
using namespace std;

bool eq(int a[26], int b[26])
{
	for (int i = 0; i < 26; i++)
	{
		if (a[i] != b[i])
			return 0;
	}
	return 1;
}

int main()
{
	int t;
	cin >> t;
	for (Loop)
	{
		char p[200];
		char h[200];
		cin >> p;
		cin >> h;
		int s = strlen(p);
		int S = strlen(h);
		if (S < s)
			cout << "NO\n";
		else
		{
			int A[26] = { 0 };
			int a[26] = { 0 };
			for (int i = 0; i < s; ++i)
			{
				++A[p[i] - 'a'];
				++a[h[i] - 'a'];
			}
			if (eq(a, A))
				cout << "YES\n";
			else
			{
				int i;
				for (i = 1; i < S - s + 1; ++i)
				{
					--a[h[i - 1] - 'a'];
					++a[h[i + s - 1] - 'a'];
					if (eq(a, A))
					{
						cout << "YES\n";
						break;
					}
				}
				if (i == S - s + 1)
					cout << "NO\n";
			}
		}
	}
}