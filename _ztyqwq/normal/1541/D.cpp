#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int mod = 1000000007;
inline int fastpow(int a, int n)
{
	int ans = 1;
	while(n)
	{
		if(n & 1)
			ans = ans * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ans;
}
inline int inv(int x)
{
	return fastpow(x, mod - 2);
}
int inv2 = inv(2);
int n;
struct Edge
{
	int to, nxt;
}e[401];
int head[201], ecnt = 0;
inline void addedge(int from, int to)
{
	e[ecnt].to = to;
	e[ecnt].nxt = head[from];
	head[from] = ecnt++;
}
int fa[201], dep[201], sz[201];
void InitTree(int u)
{
	sz[u] = 1;
	for(int i = head[u]; i != -1; i = e[i].nxt)
	{
		int v = e[i].to;
		if(v == fa[u])
			continue;
		fa[v] = u;
		dep[v] = dep[u] + 1;
		InitTree(v);
		sz[u] += sz[v];
	}
}
int logn;
int st[201][10];
inline void Initst()
{
	logn = ceil(log2(n));
	for(int i = 1; i <= n; i++)
		st[i][0] = i;
	for(int i = 1; i <= logn; i++)
		for(int j = 1; j <= n; j++)
			st[j][i] = st[fa[st[j][i - 1]]][i - 1];
}
inline void up(int &u, int &v)
{
	if(dep[u] > dep[v])
		swap(u, v);
	int d = dep[v] - dep[u];
	for(int i = logn; i >= 0; i--)
		if(d >= (1 << i))
			v = fa[st[v][i]], d -= (1 << i);
}
inline int LCA(int u, int v)
{
	up(u, v);
	for(int i = logn; i >= 0; i--)
		if(st[u][i] != st[v][i])
			u = fa[st[u][i]], v = fa[st[v][i]];
	return u;
}
int pro[201][201];
inline void InitProb()
{
	for(int i = 1; i <= n; i++)
		pro[i][0] = 0, pro[0][i] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			pro[i][j] = (pro[i - 1][j] + pro[i][j - 1]) * inv2 % mod;
}
signed main()
{
	memset(head, -1, sizeof(head));
	scanf("%lld", &n);
	for(int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%lld %lld", &u, &v);
		addedge(u, v);
		addedge(v, u);
	}
	fa[1] = 1, dep[1] = 0;
	InitTree(1);
	Initst();
	InitProb();
	int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
		{
			int tot = 0;
			int lca = LCA(i, j);
			if(lca == i)
			{
				tot = sz[j];
				int len = dep[j] - dep[i], pre, u, cnt;
				for(pre = j, u = fa[j], cnt = 1; u != i; pre = u, u = fa[u], cnt++)
					tot = (tot + pro[cnt][len - cnt] * (sz[u] - sz[pre])) % mod;
			}
			else if(lca == j)
			{
				int len = dep[i] - dep[j], pre, u, cnt;
				for(pre = i, u = fa[i], cnt = 1; u != j; pre = u, u = fa[u], cnt++)
					tot = (tot + pro[len - cnt][cnt] * (sz[u] - sz[pre])) % mod;
				tot = (tot + n - sz[pre]) % mod;
			}
			else
			{
				tot = sz[j];
				int leni = dep[i] - dep[lca], lenj = dep[j] - dep[lca];
				int pre, u, cnt;
				for(pre = i, u = fa[i], cnt = 1; u != lca; pre = u, u = fa[u], cnt++)
					tot = (tot + pro[leni - cnt + lenj][cnt] * (sz[u] - sz[pre])) % mod;
				int soni = pre;
				for(pre = j, u = fa[j], cnt = 1; u != lca; pre = u, u = fa[u], cnt++)
					tot = (tot + pro[cnt][lenj - cnt + leni] * (sz[u] - sz[pre])) % mod;
				int sonj = pre;
				tot = (tot + pro[lenj][leni] * (n - sz[soni] - sz[sonj])) % mod;
			}
			ans = (ans + tot) % mod;
		}
	ans = ans * inv(n) % mod;
	printf("%lld\n", ans);
	return 0;
}