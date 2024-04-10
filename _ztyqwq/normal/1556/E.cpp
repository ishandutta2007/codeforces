#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int a[100005], b[100005], s[100005];
int stmx[100005][21], stmn[100005][21];
int logn;
inline void Initst(int n)
{
	for(int i = 1; i <= n; i++)
		stmn[i][0] = stmx[i][0] = s[i];
	logn = log2(n);
	for(int j = 1; j <= logn; j++)
		for(int i = 1; i <= n - (1 << j) + 1 ; i++)
			stmx[i][j] = max(stmx[i][j - 1], stmx[i + (1 << (j - 1))][j - 1]);
	for(int j = 1; j <= logn; j++)
		for(int i = 1; i <= n - (1 << j) + 1; i++)
			stmn[i][j] = min(stmn[i][j - 1], stmn[i + (1 << (j - 1))][j - 1]);
}
int getMax(int l, int r)
{
	int lim = log2(r - l + 1);
	return max(stmx[l][lim], stmx[r - (1 << lim) + 1][lim]);
}
int getMin(int l, int r)
{
	int lim = log2(r - l + 1);
	return min(stmn[l][lim], stmn[r - (1 << lim) + 1][lim]);
}
signed main()
{
	int n, m;
	scanf("%lld %lld", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &b[i]), a[i] -= b[i];
	for(int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	Initst(n);
	while(m--)
	{
		int u, v;
		scanf("%lld %lld", &u, &v);
		int mx = getMax(u, v), mn = getMin(u, v);
		if(s[u - 1] < mx || s[u - 1] != s[v])
			printf("-1\n");
		else
			printf("%lld\n", s[u - 1] - mn);
	}
	return 0;
}