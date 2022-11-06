#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 100000 + 5
#define mp make_pair

int n, w, sz, c[2], X[N], V[N], L[N], R[N], Le[2][N], Ri[2][N], Ord[N], Tree[N << 1], C_l[N << 1], C_r[N << 1];
LL ans;

struct Frac
{
	int fz, fm;
	Frac(int _fz = 0, int _fm = 1)
	{
		fz = abs(_fz), fm = abs(_fm);
	}
	bool operator < (const Frac& a) const
	{
		return 1LL * fz * a.fm < 1LL * fm * a.fz;
	}
	bool operator == (const Frac& a) const
	{
		return 1LL * fz * a.fm == 1LL * fm * a.fz;
	}
}T[N << 1];

struct Segment
{
	Frac l, r;
	Segment (Frac _l = Frac(0, 1), Frac _r = Frac(0, 1))
	{
		l = _l < _r ? _l : _r;
		r = _r < _l ? _l : _r;
	}
}E[2][N];

int Query(int x)
{
	int res = 0;
	for (; x <= sz; x += (x & -x))
		res += Tree[x];
	return res;
}

void Modify(int x, int k)
{
	for (; x; x -= (x & -x))
		Tree[x] += k;
}

LL Calc(int op)
{
	for (int i = 1; i <= c[op]; i ++)
		T[i * 2 - 1] = E[op][i].l, T[i * 2] = E[op][i].r;
	sort(T + 1, T + 2 * c[op] + 1);
	sz = unique(T + 1, T + 2 * c[op] + 1) - T - 1;
	for (int i = 1; i <= c[op]; i ++)
	{
		L[i] = lower_bound(T + 1, T + sz + 1, E[op][i].l) - T;
		R[i] = lower_bound(T + 1, T + sz + 1, E[op][i].r) - T;
		Ord[i] = i;
	}
	sort(Ord + 1, Ord + c[op] + 1, [&](int u, int v){
		return mp(L[u], -R[u]) < mp(L[v], -R[v]);
	});
	for (int i = 1; i <= sz; i ++)
		Tree[i] = 0;
	LL res = 0;
	for (int i = 1; i <= c[op]; i ++)
	{
		int _i = Ord[i];
		res += Query(R[_i]);
		Modify(R[_i], 1);
	}
	return res;
}

LL Calc()
{
	for (int i = 0, t = 0; i < 2; i ++)
		for (int j = 1; j <= c[i]; j ++)
			T[++ t] = E[i][j].l, T[++ t] = E[i][j].r;
	sort(T + 1, T + 2 * n + 1);
	sz = unique(T + 1, T + 2 * n + 1) - T - 1;
	for (int i = 0; i < 2; i ++)
		for (int j = 1; j <= c[i]; j ++)
		{
			Le[i][j] = lower_bound(T + 1, T + sz + 1, E[i][j].l) - T;
			Ri[i][j] = lower_bound(T + 1, T + sz + 1, E[i][j].r) - T;
			if (!i) C_l[Le[i][j]] ++, C_r[Ri[i][j]] ++;
		}
	for (int i = 2; i <= sz; i ++)
		C_r[i] += C_r[i - 1];
	for (int i = sz - 1; i; i --)
		C_l[i] += C_l[i + 1];
	LL res = 0;
	for (int j = 1; j <= c[1]; j ++)
		res += c[0] - C_r[Le[1][j] - 1] - C_l[Ri[1][j] + 1];
	return res;
}

int main()
{
	scanf("%d%d", &n, &w);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d%d", X + i, V + i);
		bool op = X[i] > 0;
		E[op][++ c[op]] = Segment(Frac(X[i], V[i] - w), Frac(X[i], V[i] + w));
	}
	ans = Calc(0) + Calc(1) + Calc();
	printf("%lld\n", ans);
	return 0;
}