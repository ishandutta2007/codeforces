#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main()
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	string s[n];
	for(int i = 0; i < n; i++)
		cin >> s[i];
	int pr[n + 1][m + 1];
	memset(pr, 0, sizeof(pr));
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			if(i < n)
				pr[i][j] += s[i - 1][j - 1] == '.' && s[i][j - 1] == '.';
			if(j < m) 
				pr[i][j] += s[i - 1][j - 1] == '.' && s[i - 1][j] == '.';
			pr[i][j] += pr[i - 1][j];
			pr[i][j] += pr[i][j - 1];
			pr[i][j] -= pr[i - 1][j - 1];
		}
	int q;
	cin >> q;
	while(q--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int ans = 0;
		ans += pr[c - 1][d - 1] - pr[c - 1][b - 1] - pr[a - 1][d - 1] + pr[a - 1][b - 1];
		for(int i = a; i < c; i++)
			ans += s[i - 1][d - 1] == '.' && s[i][d - 1] == '.';
		for(int i = b; i < d; i++)
			ans += s[c - 1][i - 1] == '.' && s[c - 1][i] == '.';
		cout << ans << "\n";
	}
}