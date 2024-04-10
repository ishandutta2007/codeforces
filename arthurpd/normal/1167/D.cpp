#include <bits/stdc++.h>
using namespace std;

#define MAXN 512345

int h[MAXN];

int main(void)
{
	int n;
	string s;
	cin >> n >> s;
	int x = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(')
		{
			x++;
			h[i] = x;
		}
		else
		{
			h[i] = x;
			x--;
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d", h[i] % 2);
	printf("\n");
}