#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
struct SEG
{
	int mn[800001], tg[800001];
	inline void pushup(int p)
	{
		mn[p] = min(mn[p << 1], mn[p << 1 | 1]);
	}
	inline void pushdown(int p)
	{
		if(tg[p])
		{
			mn[p << 1] += tg[p];
			tg[p << 1] += tg[p];
			mn[p << 1 | 1] += tg[p];
			tg[p << 1 | 1] += tg[p];
			tg[p] = 0;
		}
	}
	inline void Build(int p, int l, int r)
	{
		if(l == r)
		{
			mn[p] = INF, tg[p] = 0;
			return;
		}
		int mid = (l + r) >> 1;
		Build(p << 1, l, mid);
		Build(p << 1 | 1, mid + 1, r);
		pushup(p);
		tg[p] = 0;
	}
	inline void Modify(int p, int l, int r, int L, int R, int a)
	{
		if(r < L || R < l)
			return;
		if(L <= l && r <= R)
		{
			mn[p] += a;
			tg[p] += a;
			return;
		}
		pushdown(p);
		int mid = (l + r) >> 1;
		Modify(p << 1, l, mid, L, R, a);
		Modify(p << 1 | 1, mid + 1, r, L, R, a);
		pushup(p);
	}
	inline int GetMin(int p, int l, int r, int L, int R)
	{
		if(r < L || R < l)
			return INF;
		if(L <= l && r <= R)
			return mn[p];
		pushdown(p);
		int mid = (l + r) >> 1;
		int res = min(GetMin(p << 1, l, mid, L, R), GetMin(p << 1 | 1, mid + 1, r, L, R));
		pushup(p);
		return res;
	}
} S;
int a[200001], b[200001];
bool vis[200001];
int main()
{
	int testcase;
	scanf("%d", &testcase);
	while(testcase--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]), b[a[i]] = i;
		for(int i = 1; i <= n; i++)
			vis[i] = false;
		int ans = 0, rm = n;
		S.Build(1, 1, n);
		for(int i = n; i > 1; i--)
		{
			// set i (aka a[b[i]]) to 1
			int u = b[i];
			S.Modify(1, 1, n, u + 1, n, -2);
			S.Modify(1, 1, n, u, u, u - INF);
			vis[u] = true;
			while(vis[rm])
				rm--;
			int mn = S.GetMin(1, 1, n, 1, rm);
			if(mn % 2 == 0)
				mn--;
			ans = max(ans, i - mn);
		}
		printf("%d\n", ans);
	}
	return 0;
}