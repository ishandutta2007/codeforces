#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, q, M = 50;
unordered_map<int, int> mp;
int mp_cnt = 0;
inline int GetCnt(int x)
{
	if(mp.find(x) == mp.end())
		mp[x] = ++mp_cnt;
	return mp[x];
}
inline int lowbit(int x)
{
	return x & -x;
}
mt19937 rnd(19260817);
inline int Rand()
{
	return rnd() % 998244353;
}
int H[600010];
struct LOWBIT
{
	ll c[300010];
	inline void Modify(int u, int x)
	{
		for(int i = u; i <= n; i += lowbit(i))
			c[i] += x;
	}
	inline ll Sum(int u)
	{
		ll ans = 0;
		for(int i = u; i; i -= lowbit(i))
			ans += c[i];
		return ans;
	}
	inline ll Sum(int l, int r)
	{
		return Sum(r) - Sum(l - 1);
	}
	inline void re()
	{
		memset(c, 0, sizeof(c));
	}
}f;
int a[300010], b[300010];
struct Query
{
	int op, l, r, x;
	bool ans;
	Query(): ans(true) {}
}qs[300010];
int main()
{
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		a[i] = GetCnt(a[i]);
	}
	for(int i = 1; i <= q; i++)
	{
		scanf("%d", &qs[i].op);
		if(qs[i].op == 1)
		{
			scanf("%d %d", &qs[i].l, &qs[i].x);
			qs[i].x = GetCnt(qs[i].x);
		}
		else
			scanf("%d %d %d", &qs[i].l, &qs[i].r, &qs[i].x);
	}
	for(int _ = 1; _ <= M; _++)
	{
		for(int i = 1; i <= n + q; i++)
			H[i] = Rand();
		f.re();
		for(int i = 1; i <= n; i++)
			b[i] = a[i], f.Modify(i, H[a[i]]);
		for(int i = 1; i <= q; i++)
		{
			if(qs[i].op == 1)
			{
				int u = qs[i].l, x = qs[i].x;
				f.Modify(u, H[x] - H[b[u]]);
				b[u] = x;
			}
			else
			{
				if(!qs[i].ans)
					continue;
				ll tot = f.Sum(qs[i].l, qs[i].r);
				if(tot % qs[i].x)
					qs[i].ans = false;
			}
		}
	}
	for(int i = 1; i <= q; i++)
		if(qs[i].op == 2)
		{
			if(qs[i].ans)
				printf("YES\n");
			else
				printf("NO\n");
		}
	return 0;
}