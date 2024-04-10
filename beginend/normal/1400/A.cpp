#include<bits/stdc++.h>
using namespace std;

const int N = 105;

int n, s[N][2], ans[N];
char str[N];

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		scanf("%s", str + 1);
		memset(s, 0, sizeof(s));
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < n; j++)
				s[j][str[i + j] - '0']++;
		for (int i = 0; i < n; i++)
			if (s[i][0]) ans[i] = 0;
			else ans[i] = 1;
		for (int i = 0; i < n; i++) putchar(ans[i] + '0');
		puts("");
	}
	return 0;
}