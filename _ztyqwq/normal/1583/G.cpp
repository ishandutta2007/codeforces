#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
typedef long long ll;
#define int ll
struct Interval
{
	int a, b, ind;
	bool operator < (const Interval& ano) const
	{
		return b < ano.b;
	}
}a[200010];
bool used[200010];
set<int> st;
struct SEG
{
	#define lc(u) u << 1
	#define rc(u) u << 1 | 1
	int sum[1600010], tg1[1600010], tg2[1600010];
	inline void pushup(int u)
	{
		sum[u] = (sum[lc(u)] + sum[rc(u)]) % mod;
	}
	inline void pushdown(int u, int l, int r)
	{
		int mid = (l + r) >> 1;
		if(tg1[u])
		{
			tg1[lc(u)] = tg1[u], tg2[lc(u)] = 0;
			sum[lc(u)] = tg1[u] * (mid - l + 1) % mod;
			tg1[rc(u)] = tg1[u], tg2[rc(u)] = 0;
			sum[rc(u)] = tg1[u] * (r - mid) % mod;
			tg1[u] = 0;
		}
		if(tg2[u])
		{
			tg2[lc(u)] = (tg2[lc(u)] + tg2[u]) % mod;
			sum[lc(u)] = (sum[lc(u)] + (mid - l + 1) * tg2[u]) % mod;
			tg2[rc(u)] = (tg2[rc(u)] + tg2[u]) % mod;
			sum[rc(u)] = (sum[rc(u)] + (r - mid) * tg2[u]) % mod;
			tg2[u] = 0;
		}
	}
	void Build(int u, int l, int r)
	{
		if(l == r)
		{
			sum[u] = tg1[u] = tg2[u] = 0;
			return;
		}
		int mid = (l + r) >> 1;
		Build(lc(u), l, mid);
		Build(rc(u), mid + 1, r);
		pushup(u);
	}
	void Add(int u, int l, int r, int L, int R, int ad)
	{
		if(r < L || R < l)
			return;
		if(L <= l && r <= R)
		{
			tg2[u] = (tg2[u] + ad) % mod;
			sum[u] = (sum[u] + (r - l + 1) * ad) % mod;
			return;
		}
		pushdown(u, l, r);
		int mid = (l + r) >> 1;
		Add(lc(u), l, mid, L, R, ad);
		Add(rc(u), mid + 1, r, L, R, ad);
		pushup(u);
	}
	void Assign(int u, int l, int r, int L, int R, int as)
	{
		if(r < L || R < l)
			return;
		if(L <= l && r <= R)
		{
			tg1[u] = as, tg2[u] = 0;
			sum[u] = (r - l + 1) * as % mod;
			return;
		}
		pushdown(u, l, r);
		int mid = (l + r) >> 1;
		Assign(lc(u), l, mid, L, R, as);
		Assign(rc(u), mid + 1, r, L, R, as);
		pushup(u);
	}
	int Query(int u, int l, int r, int L, int R)
	{
		if(r < L || R < l)
			return 0;
		if(L <= l && r <= R)
			return sum[u];
		pushdown(u, l, r);
		int mid = (l + r) >> 1, ans = 0;
		ans = Query(lc(u), l, mid, L, R);
		ans = (ans + Query(rc(u), mid + 1, r, L, R)) % mod;
		pushup(u);
		return ans;
	}
}S1, S2;
signed main()
{
	int n;
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++)
		scanf("%lld %lld", &a[i].a, &a[i].b), a[i].ind = i;
	sort(a + 1, a + n + 1);
	int T;
	scanf("%lld", &T);
	while(T--)
	{
		int x;
		scanf("%lld", &x);
		used[x] = true;
	}
	S1.Build(1, 1, n << 1), S2.Build(1, 1, n << 1);
	st.insert(2 * n);
	for(int i = 1; i <= n; i++)
	{
		int pos = *(st.lower_bound(a[i].a));
		int s1 = S1.Query(1, 1, n << 1, pos, pos), s2 = s1 - S2.Query(1, 1, n << 1, pos, pos);
		S1.Assign(1, 1, n << 1, a[i].a, a[i].a, (s1 * 2 + 1) % mod);
		if(used[a[i].ind])
			S2.Assign(1, 1, n << 1, a[i].a, a[i].a, (s1 - s2 + mod) % mod); // s1 + s2 + 1
		else
			S2.Assign(1, 1, n << 1, a[i].a, a[i].a, (s1 * 2 + 1 - s2 + mod) % mod); // s2
		if(used[a[i].ind])
			S2.Assign(1, 1, n << 1, 1, a[i].a - 1, mod - s2 - 1);
		S1.Add(1, 1, n << 1, 1, a[i].a - 1, (s1 + 1) % mod);
		S2.Add(1, 1, n << 1, 1, a[i].a - 1, (s1 + 1) % mod);
		st.insert(a[i].a);
	}
	printf("%lld\n", (S1.Query(1, 1, n << 1, 1, 1) - S2.Query(1, 1, n << 1, 1, 1) + mod) % mod);
	return 0;
}