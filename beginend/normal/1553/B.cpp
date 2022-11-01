#include<bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m, f[N][N], g[N][N];
char s[N], t[N];

bool check()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (f[i][j] == j && g[i][j] == m - j + 1) return 1;
	return 0;
}

int main() {
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%s", s + 1);
		scanf("%s", t + 1);
		n = strlen(s + 1);
		m = strlen(t + 1);
		for (int i = 1; i <= n + 1; i++)
			for (int j = 1; j <= m + 1; j++)
				f[i][j] = g[i][j] = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (s[i] == t[j]) f[i][j] = f[i - 1][j - 1] + 1;
		for (int i = 1; i <= n; i++)
			for (int j = m; j >= 1; j--)
				if (s[i] == t[j]) g[i][j] = g[i - 1][j + 1] + 1;
		if (check()) puts("YES");
		else puts("NO");
	}
	return 0;
}