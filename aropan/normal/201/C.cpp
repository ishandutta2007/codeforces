#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

const int MAXN = 100007;

long long a[MAXN], b[MAXN], x[MAXN];
long long f[MAXN], g[MAXN];
int n;
long long cnt;
long long ans;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	scanf("%d", &n);
	n--;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
		a[i] = x[i] - (int)(x[i] % 2 == 1);
		b[i] = x[i] - (int)(x[i] % 2 == 0);
	}
	
	f[n] = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		f[i] = f[i + 1] + a[i];
		if (x[i] == 1) f[i] = 0;
	}
	
	for (int i = 0; i < n; i++)
	{
		if (i) a[i] += a[i - 1];
		if (x[i] == 1) a[i] = 0;
	}
	
	long long res = 0;
	for (int i = 0, j = 0; i < n; i = j)
	{
		while (j < n && (x[j] % 2 == 1)) res += b[j], j++;
		i = j;
		if (i == n) break;
		long long cnt = 0;
		while (j < n && (x[j] % 2 == 0)) res += b[j], cnt += b[j], j++;
		//cout << res << " " << (j - i) << " " << f[j] << endl;
		ans = max(ans, (j - i) + res + f[j]);
		res = max(res, (i > 0? a[i - 1] : 0) + (j - i) + cnt);
	}
		
	ans = max(ans, res);
	cout << ans << endl;
	return 0;
}