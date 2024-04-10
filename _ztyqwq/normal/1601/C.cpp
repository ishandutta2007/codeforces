#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<int, int> a[1000010];
int b[1000010];
struct SEG
{
	int mn[4000100], mnpos[4000100];
	int tg[4000100];
	
	#define lc(u) (u << 1)
	#define rc(u) (u << 1 | 1)
	inline void BBuild(int n)
	{
		for(int i = 1; i <= ((n + 10) << 2); i++)
			mn[i] = mnpos[i] = tg[i] = 0;
	}
	inline void pushup(int u)
	{
		if(mn[lc(u)] < mn[rc(u)])
			mn[u] = mn[lc(u)], mnpos[u] = mnpos[lc(u)];
		else
			mn[u] = mn[rc(u)], mnpos[u] = mnpos[rc(u)];
	}
	inline void pushdown(int u)
	{
		if(tg[u])
		{
			tg[lc(u)] += tg[u];
			mn[lc(u)] += tg[u];
			tg[rc(u)] += tg[u];
			mn[rc(u)] += tg[u];
			tg[u] = 0;
		}
	}
	inline void Build(int u, int l, int r)
	{
		if(l == r)
		{
			tg[u] = mn[u] = 0;
			mnpos[u] = l;
			return;
		}
		int mid = (l + r) >> 1;
		Build(lc(u), l, mid);
		Build(rc(u), mid + 1, r);
		pushup(u);
	}
	inline void Modify(int u, int l, int r, int L, int R, int ad)
	{
		// if(l == 0 && r == 5)

		// cout << "MODIFY " << u << ' ' << l << ' ' << r << ' ' << L << ' ' << R << ' ' << ad << endl;
		if(r < L || R < l)
			return;
		if(L <= l && r <= R)
		{
			tg[u] += ad;
			mn[u] += ad;
			return;
		}
		pushdown(u);
		int mid = (l + r) >> 1;
		Modify(lc(u), l, mid, L, R, ad);
		Modify(rc(u), mid + 1, r, L, R, ad);
		pushup(u);
	}
	inline void Query(int u, int l, int r, int L, int R, int &m, int &p)
	{
		if(r < L || R < l)
		{
			m = 0, p = 0x7fffffff;
			return;
		}
		if(L <= l && r <= R)
		{
			m = mn[u], p = mnpos[u];
			return;
		}
		pushdown(u);
		int mid = (l + r) >> 1;
		int m1, p1, m2, p2;
		Query(lc(u), l, mid, L, R, m1, p1);
		Query(rc(u), mid + 1, r, L, R, m2, p2);
		if(m1 < m2)
			m = m1, p = p1;
		else
			m = m2, p = p2;
		pushup(u);
	}
}S;
int c[1000010];
inline int lowbit(int x)
{
	return x & -x;
}
inline void Mod(int u, int x, int n)
{
	for(int i = u; i <= n; i += lowbit(i))
		c[i] += x;
}
inline int Que(int u)
{
	int res = 0;
	for(int i = u; i; i -= lowbit(i))
		res += c[i];
	return res;
}
inline int read()
{
	char c;
	while((c = getchar()) < '0' || c > '9');
	int x = c - '0';
	while((c = getchar()) >= '0' && c <= '9')
		x = x * 10 + c - '0';
	return x;
}
int main()
{
	int t = read();
	while(t--)
	{
		int n = read(), m = read();
		for(int i = 1; i <= n; i++)
			a[i].first = read(), a[i].second = i;
		for(int i = 1; i <= m; i++)
			b[i] = read();
		sort(a + 1, a + n + 1);
		sort(b + 1, b + m + 1);
		S.BBuild(n);
		S.Build(1, 0, n);
		for(int i = 1; i <= n; i++)
			c[i] = 0;
		ll ori = 0;
		for(int i = 1; i <= n; i++)
		{
			// cout << "M " << a[i].second << endl;
			Mod(a[i].second, 1, n);
			ori += Que(n) - Que(a[i].second);
			// cout << Que(n) << ' ' << Que(a[i].second) << endl;
			S.Modify(1, 0, n, a[i].second, n, 1);
		}
		// cout << "o = " << ori << endl;
		// cout << "BUILT" << endl;
		int pos = 0;
		ll ans = 0;
		for(int i = 1; i <= m; i++)
		{
			while(pos < n && a[pos + 1].first < b[i])
			{
				pos++;
				S.Modify(1, 0, n, a[pos].second, n, -1);
				S.Modify(1, 0, n, 0, a[pos].second - 1, 1);
			}
			int ppos = pos;
			while(ppos < n && a[ppos + 1].first == b[i])
			{
				ppos++;
				S.Modify(1, 0, n, a[ppos].second, n, -1);
			}
			int where, val;
			S.Query(1, 0, n, 0, n, val, where);
			// cout << i << " INSERT in " << where << " val += " << val << endl;
			ans += val;
			int CNT = 1;
			while(i < m && b[i + 1] == b[i])
			{
				i++;
				ans += val;
				CNT++;
			}
			if(where)
				S.Modify(1, 0, n, 0, where - 1, CNT);
			while(pos < n && a[pos + 1].first == b[i])
			{
				pos++;
				S.Modify(1, 0, n, 0, a[pos].second - 1, 1);
			}
		}
		printf("%lld\n", ori + ans);
	}
	return 0;
}