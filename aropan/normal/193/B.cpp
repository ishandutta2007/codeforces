#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;


const int MAXN = 32;
const long long INF = (long long)1e+18;

int n, u, r;
int a[MAXN], b[MAXN], k[MAXN], p[MAXN];
long long ans;

void dfs(int m, bool f)
{
	if ((m & 1) == 0)
	{
		long long res = 0;
		for (int i = 1; i <= n; i++)
			res += a[i] * (long long)k[i];
		ans = max(ans, res);
	}
	if (m == 0) return;

	if (f)
	{
		for (int i = 1; i <= n; i++)
			a[i] ^= b[i];
		dfs(m - 1, false);
		for (int i = 1; i <= n; i++)
			a[i] ^= b[i];
	}

	int c[MAXN];
	for (int i = 1; i <= n; i++)
		c[i] = a[i];
	for (int i = 1; i <= n; i++)
		a[i] = c[p[i]] + r;
	dfs(m - 1, true);
	for (int i = 1; i <= n; i++)
		a[i] = c[i];
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif

    scanf("%d %d %d", &n, &u, &r);
    for (int i = 1; i <= n; i++)
    	scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
    	scanf("%d", &b[i]);
    for (int i = 1; i <= n; i++)
    	scanf("%d", &k[i]);
    for (int i = 1; i <= n; i++)
    	scanf("%d", &p[i]);
    ans = -INF;

    dfs(u, true);
    cout << ans << endl;

    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}