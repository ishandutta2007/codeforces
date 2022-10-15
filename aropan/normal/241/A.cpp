#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

const int MAXN = 1024;

int n, k;
int d[MAXN], a[MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &d[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	long long m = 0;
	long long x = 0;
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += d[i];
		x += a[i];
		m = max(m, (long long)a[i]);
		long long l = max((d[i] - x + m - 1) / m, 0LL);
		ans += l * k;
		x += l * m;
		x -= d[i];
	}
	cout << ans << endl;
	return 0;
}