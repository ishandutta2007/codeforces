#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
string xs, ys;
int n, m;
inline int ndupd(int nd, int x)
{
	if(nd == 0)
		return x + 1;
	else if(nd == 1 && x == 1)
		return 3;
	else if(nd == 2 && x == 0)
		return 3;
	else
		return nd;
}
int f[1002][1002][2][4];
int dfs(int u, int v, int pre, int nd) // pre: pre turn  nd: we've already gone (0: none 1: x gone 2: y gone 3: both)
{
	// f[u][v][st][nd] =  x  uy  v l1 = u, l2 = vr1 >= l1, r2 >= l2  f 
	//  0f[u][v] += f[u + 1][v] if x[u] != pre pre  x[u - 1]  y[v - 1]  f[u][v] +=  0  f[u][v] += [ 1 ]
	//  1 
	if(u > n && v > m)
		return 0;
	if(f[u][v][pre][nd] != -1)
		return f[u][v][pre][nd];
	char prec = (pre == 0 ? xs[u - 1] : ys[v - 1]);
	if(pre == 2)
		prec = '#';
	int ans = 0;
	if(u <= n && xs[u] != prec)
	{
		ans += dfs(u + 1, v, 0, ndupd(nd, 0));
		if(nd == 2 || nd == 3)
			ans++;
	}
	if(v <= m && ys[v] != prec)
	{
		ans += dfs(u, v + 1, 1, ndupd(nd, 1));
		if(nd == 1 || nd == 3)
			ans++;
	}
	return f[u][v][pre][nd] = ans % mod;
}
int main()
{
	memset(f, -1, sizeof(f));
	cin >> xs >> ys;
	n = xs.size(), m = ys.size();
	xs = "#" + xs, ys = "#" + ys;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			for(int pre = 0; pre <= 2; pre++)
				for(int nd = 0; nd <= 3; nd++)
					dfs(i, j, pre, nd);
	int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			ans = (ans + f[i][j][2][0]) % mod;
	printf("%d\n", ans);
	return 0;
}