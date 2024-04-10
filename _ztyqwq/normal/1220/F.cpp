#include <bits/stdc++.h>
using namespace std;
int a[200010], b[200010], tmp[200010];
set<int> st;
int l[200010], r[200010];
struct DKE
{
	int a[200010];
	int st[200010][20], n, logn;
	inline void stInit()
	{
		for(int i = 1; i <= n; i++)
			st[i][0] = i;
		logn = ceil(log2(n));
		for(int i = 1; i <= logn; i++)
			for(int j = 1; j <= n; j++)
			{
				int u = st[j][i - 1], v = st[min(j + (1 << (i - 1)), n)][i - 1];
				st[j][i] = (a[u] < a[v]) ? u : v;
			}
	}
	inline int GetMin(int l, int r)
	{
		int k = log2(r - l + 1);
		int u = st[l][k], v = st[r - (1 << k) + 1][k];
		return (a[u] < a[v]) ? u : v;
	}
	int dep[200010];
	inline void dfs(int l, int r, int mid)
	{
		if(l < mid)
		{
			int lm = GetMin(l, mid - 1);
			dep[lm] = dep[mid] + 1;
			dfs(l, mid - 1, lm);
		}
		if(mid < r)
		{
			int rm = GetMin(mid + 1, r);
			dep[rm] = dep[mid] + 1;
			dfs(mid + 1, r, rm);
		}
	}
	inline void Get(int *A, int N)
	{
		n = N;
		for(int i = 1; i <= n; i++)
			a[i] = A[i];
		stInit();
		memset(dep, 0, sizeof(dep));
		dfs(1, n, GetMin(1, n));
	}
}L, R;
struct SEG
{
	int mx[800010], tg[800010];
	#define lc(u) (u << 1)
	#define rc(u) (u << 1 | 1)
	inline void pushup(int u)
	{
		mx[u] = max(mx[lc(u)], mx[rc(u)]);
	}
	inline void pushdown(int u)
	{
		if(tg[u])
		{
			mx[lc(u)] += tg[u], tg[lc(u)] += tg[u];
			mx[rc(u)] += tg[u], tg[rc(u)] += tg[u];
			tg[u] = 0;
		}
	}
	inline void Build(int *a, int u, int l, int r)
	{
		if(l == r)
		{
			mx[u] = a[l], tg[u] = 0;
			return;
		}
		int mid = (l + r) >> 1;
		Build(a, lc(u), l, mid);
		Build(a, rc(u), mid + 1, r);
		pushup(u);
	}
	inline void Modify(int u, int l, int r, int L, int R, int a)
	{
		if(r < L || R < l)
			return;
		if(L <= l && r <= R)
		{
			mx[u] += a, tg[u] += a;
			return;
		}
		pushdown(u);
		int mid = (l + r) >> 1;
		Modify(lc(u), l, mid, L, R, a);
		Modify(rc(u), mid + 1, r, L, R, a);
		pushup(u);
	}
	inline int GetMax(int u, int l, int r, int L, int R)
	{
		if(r < L || R < l)
			return 0;
		if(L <= l && r <= R)
			return mx[u];
		pushdown(u);
		int mid = (l + r) >> 1;
		int ans = max(GetMax(lc(u), l, mid, L, R), GetMax(rc(u), mid + 1, r, L, R));
		pushup(u);
		return ans;
	}
}LS, RS;
int lans[200010], rans[200010];
int ans[200010];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]), b[a[i]] = i;
	int u = b[1];
	for(int i = 1; i <= n; i++)
		tmp[(i - u + n - 1) % n + 1] = a[i];
	for(int i = 1; i <= n; i++)
		a[i] = tmp[i], b[a[i]] = i;
	st.insert(n + 1);
	for(int i = 1; i <= n; i++)
	{
		int u = b[i];
		r[u] = *st.lower_bound(u);
		st.insert(u);
	}
	L.Get(a, n);
	LS.Build(L.dep, 1, 1, n);
	for(int i = 1; i <= n; i++)
	{
		lans[n + 1 - i] = LS.GetMax(1, 1, n, i, n);
		LS.Modify(1, 1, n, i, r[i] - 1, -1);
	}
	for(int i = n; i >= 2; i--)
		a[i] = a[i - 1];
	a[1] = 1;
	for(int i = 1; i <= n; i++)
		b[a[i]] = i;
	st.clear();
	st.insert(0);
	for(int i = 1; i <= n; i++)
	{
		int u = b[i];
		l[u] = -(*st.lower_bound(-u));
		st.insert(-u);
	}
	R.Get(a, n);
	RS.Build(R.dep, 1, 1, n);
	for(int i = n; i >= 1; i--)
	{
		rans[n + 1 - i] = RS.GetMax(1, 1, n, 1, i);
		RS.Modify(1, 1, n, l[i] + 1, i, -1);
	}
	for(int i = 1; i <= n; i++)
		ans[i] = max(lans[i], rans[i]) + 1;
	int pos = 0, mn = ans[u];
	for(int i = 1; i < n; i++)
	{
		int v = (u - i + n - 1) % n + 1;
		if(ans[v] < mn)
			pos = i, mn = ans[v];
	}
	printf("%d %d\n", mn, pos);
	return 0;
}