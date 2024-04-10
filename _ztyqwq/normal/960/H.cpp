#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int n, m, q, C;
int a[50010], v[50010];
struct Edge
{
	int to, nxt;
}e[100010];
int ecnt = 0, head[50010];
inline void addedge(int from, int to)
{
	e[ecnt].to = to;
	e[ecnt].nxt = head[from];
	head[from] = ecnt++;
}
int fa[50010], dep[50010], sz[50010], hson[50010];
int newid[50010], oldid[50010], id_cnt = 0, tp[50010];
void dfs1(int u)
{
	sz[u] = 1;
	for(int i = head[u]; i != -1; i = e[i].nxt)
	{
		int v = e[i].to;
		if(v == fa[u])
			continue;
		fa[v] = u;
		dep[v] = dep[u] + 1;
		dfs1(v);
		sz[u] += sz[v];
		if(sz[v] > sz[hson[u]])
			hson[u] = v;
	}
}
void dfs2(int u)
{
	newid[u] = ++id_cnt;
	oldid[id_cnt] = u;
	if(!hson[u])
		return;
	tp[hson[u]] = tp[u];
	dfs2(hson[u]);
	for(int i = head[u]; i != -1; i = e[i].nxt)
	{
		int v = e[i].to;
		if(v == fa[u] || v == hson[u])
			continue;
		tp[v] = v;
		dfs2(v);
	}
}
struct SEG
{
	int s[200010], tg[200010];
	inline void pushup(int u)
	{
		s[u] = (s[u << 1] + s[u << 1 | 1]);
	}
	inline void pushdown(int u, int l, int r)
	{
		if(!tg[u])
			return;
		int mid = (l + r) >> 1;
		s[u << 1] = (s[u << 1] + (ll)tg[u] * (mid - l + 1));
		tg[u << 1] = (tg[u << 1] + tg[u]);
		s[u << 1 | 1] = (s[u << 1 | 1] + (ll)tg[u] * (r - mid));
		tg[u << 1 | 1] = (tg[u << 1 | 1] + tg[u]);
		tg[u] = 0;
	}
	void Build(int u, int l, int r)
	{
		if(l == r)
		{
			s[u] = tg[u] = 0;
			return;
		}
		int mid = (l + r) >> 1;
		Build(u << 1, l, mid);
		Build(u << 1 | 1, mid + 1, r);
		pushup(u);
	}
	void Modify(int u, int l, int r, int L, int R, int ad)
	{
		if(R < l || r < L)
			return;
		if(L <= l && r <= R)
		{
			s[u] = (s[u] + (ll)ad * (r - l + 1));
			tg[u] = (tg[u] + ad);
			return;
		}
		pushdown(u, l, r);
		int mid = (l + r) >> 1;
		Modify(u << 1, l, mid, L, R, ad);
		Modify(u << 1 | 1, mid + 1, r, L, R, ad);
		pushup(u);
	}
	int Ask(int u, int l, int r, int L, int R)
	{
		if(R < l || r < L)
			return 0;
		if(L <= l && r <= R)
			return s[u];
		pushdown(u, l, r);
		int mid = (l + r) >> 1, ans = 0;
		ans = Ask(u << 1, l, mid, L, R);
		ans = (ans + Ask(u << 1 | 1, mid + 1, r, L, R));
		pushup(u);
		return ans;
	}
}S;
int SUM1, SUM2;
inline int GET(int u)
{
	int ans = 0;
	while(u)
	{
		int v = tp[u], uu = newid[u], vv = newid[v];
		ans = (ans + S.Ask(1, 1, n, vv, uu));
		u = fa[v];
	}
	return ans;
}
inline void ADD(int u, int ad)
{
	SUM1 = (SUM1 + dep[u] * ad);
	SUM2 = ((SUM2 + GET(u) * ad * 2 + dep[u] * ad * ad));
	while(u)
	{
		int v = tp[u], uu = newid[u], vv = newid[v];
		S.Modify(1, 1, n, vv, uu, ad);
		u = fa[v];
	}
}
struct Query
{
	int op, tp, tm;
	int pt, ad;
};
vector<Query> qs[50010];
int qans[50010];
signed main()
{
	memset(head, -1, sizeof(head));
	scanf("%lld %lld %lld %lld", &n, &m, &q, &C);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		qs[a[i]].push_back({1, a[i], 0, i, 1});
	}
	for(int i = 2; i <= n; i++)
	{
		int par;
		scanf("%lld", &par);
		addedge(i, par);
		addedge(par, i);
	}
	for(int i = 1; i <= m; i++)
		scanf("%lld", &v[i]);
	fa[1] = sz[0] = 0;
	dep[1] = 1;
	dfs1(1);
	tp[1] = 1;
	dfs2(1);
	for(int TIME = 1; TIME <= q; TIME++)
	{
		Query u;
		scanf("%lld", &u.op);
		u.tm = TIME;
		if(u.op == 1)
		{
			int p, v;
			scanf("%lld %lld", &p, &v);
			u.pt = p;
			u.tp = a[p], u.ad = -1;
			qs[u.tp].push_back(u);
			u.tp = v, u.ad = 1;
			qs[u.tp].push_back(u);
			a[p] = v;
		}
		else
		{
			scanf("%lld", &u.tp);
			qs[u.tp].push_back(u);
		}
	}
	memset(qans, -1, sizeof(qans));
	for(int i = 1; i <= m; i++)
	{
		SUM1 = SUM2 = 0;
		for(auto Q: qs[i])
		{
			if(Q.op == 1)
				ADD(Q.pt, Q.ad);
			else
			{
				ll s1 = SUM1, s2 = SUM2, ans = 0;
				ans = ((s2 * v[i] * v[i] - 2 * s1 * C * v[i] + (ll)C * C * n));
				qans[Q.tm] = ans;
			}
		}
		for(auto Q: qs[i])
			if(Q.op == 1)
				ADD(Q.pt, -Q.ad);
	}
	for(int i = 1; i <= q; i++)
		if(qans[i] != -1)
			printf("%.12lf\n", qans[i] * 1.0 / n);
	return 0;
}