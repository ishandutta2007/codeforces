#include<bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, s[35][35];
char a[N], b[N];

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		memset(s, 0, sizeof(s));
		scanf("%d", &n);
		scanf("%s%s", a + 1, b + 1);
		bool flag = 0;
		for (int i = 1; i <= n; i++)
			if (a[i] > b[i]) {flag = 1; break;}
			else if (a[i] < b[i]) s[a[i] - 'a'][b[i] - 'a']++;
		int ans = 0;
		for (int i = 0; i < 20; i++)
		{
			int p = -1;
			for (int j = i + 1; j < 20; j++)
				if (s[i][j]) {p = j; break;}
			if (p == -1) continue;
			ans++;
			for (int j = p + 1; j < 20; j++)
				s[p][j] += s[i][j];
		}
		if (flag) printf("%d\n", -1);
		else printf("%d\n", ans);
	}
	return 0;
}