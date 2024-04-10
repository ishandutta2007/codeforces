#include <bits/stdc++.h>
using namespace std;
 
#define fo(i, x, y) for (int i = (x); i <= (y); ++i)
#define fd(i, x, y) for (int i = (x); i >= (y); --i)
 
typedef long long ll;
 
const int maxn = 100 + 5;
 
int n, m;
int a[maxn][maxn];
 
int getint()
{
	char ch;
	int res = 0, p;
	while (!isdigit(ch = getchar()) && (ch ^ '-'));
	p = ch == '-'? ch = getchar(), -1 : 1;
	while (isdigit(ch))
		res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return res * p;
}
 
int main()
{
	int T = getint();
	while (T--)
	{
		n = getint(); m = getint();
		fo(i, 1, n)
			fo(j, 1, m) a[i][j] = getint();
		ll ans = 0;
		fo(i, 1, n / 2)
			fo(j, 1, m / 2)
			{
				ll t1 = a[i][j], t2 = a[i][m - j + 1], t3 = a[n - i + 1][j], t4 = a[n - i + 1][m - j + 1];
				ll t = abs(t2 - t1) + abs(t3 - t1) + abs(t4 - t1);
				t = min(t, abs(t1 - t2) + abs(t3 - t2) + abs(t4 - t2));
				t = min(t, abs(t1 - t3) + abs(t2 - t3) + abs(t4 - t3));
				t = min(t, abs(t1 - t4) + abs(t2 - t4) + abs(t3 - t4));
				ans += t;
			}
		if (n & 1)
			fo(j, 1, m / 2)
				ans += abs(a[n / 2 + 1][j] - a[n / 2 + 1][m - j + 1]);
		if (m & 1)
			fo(i, 1, n / 2)
				ans += abs(a[i][m / 2 + 1] - a[n - i + 1][m / 2 + 1]);
		printf("%lld\n", ans);
	}
	return 0;
}