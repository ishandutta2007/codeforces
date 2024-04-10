#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int a[401][401];
int s[401][401];
int vall[401], valr[401];
inline int Get1(int a, int b, int c, int d)
{
	return s[c][d] - s[a - 1][d] - s[c][b - 1] + s[a - 1][b - 1];
}
inline int Get0(int a, int b, int c, int d)
{
	return (c - a + 1) * (d - b + 1) - Get1(a, b, c, d);
}
signed main()
{
	int t;
	scanf("%lld", &t);
	while(t--)
	{
		int n, m;
		scanf("%lld %lld", &n, &m);
		for(int i = 1; i <= n; i++)
		{
			string s;
			cin >> s;
			for(int j = 1; j <= m; j++)
				a[i][j] = s[j - 1] - '0';
		}
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + a[i][j];
		int ans = 1145141919810ll;
		for(int a = 1; a <= n; a++)
			for(int b = a + 4; b <= n; b++)
			{
				for(int x = 1; x <= m; x++)
				{
					valr[x] = Get0(a, 1, a, x - 1) + Get0(b, 1, b, x - 1) + Get0(a + 1, x, b - 1, x) + Get1(a + 1, 1, b - 1, x - 1);
					vall[x] = -Get0(a, 1, a, x) - Get0(b, 1, b, x) + Get0(a + 1, x, b - 1, x) - Get1(a + 1, 1, b - 1, x);
				}
				int mn = 1145141919810ll;
				for(int i = 4; i <= m; i++)
				{
					mn = min(mn, vall[i - 3]);
					ans = min(ans, valr[i] + mn);
				}
			}
		printf("%lld\n", ans);
	}
	return 0;
}