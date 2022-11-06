#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 200000 + 5
#define M 524288 + 5
#define Mod 1000000007
#define ls(x) x << 1
#define rs(x) x << 1 | 1

int n, q, Pos[N], W[N], Tree[N];
LL SegTree[M];

inline int Inc(int u, int v)
{
	return u + v - (u + v >= Mod ? Mod : 0);
}

void Add(int x, int k)
{
	for (; x <= n; x += (x & -x))
		Tree[x] = Inc(Tree[x], k);
}

int Calc(int x)
{
	int res = 0;
	for (; x; x -= (x & -x))
		res = Inc(res, Tree[x]);
	return res;
}

void update(int x)
{
	SegTree[x] = SegTree[ls(x)] + SegTree[rs(x)];
}

void Build(int x, int l, int r)
{
	if (l == r)
	{
		SegTree[x] = W[l];
		return ;
	}
	int mid = l + r >> 1;
	Build(ls(x), l, mid);
	Build(rs(x), mid + 1, r);
	update(x);
}

void Modify(int x, int l, int r, int t, int k)
{
	if (l == r)
	{
		SegTree[x] = k;
		return ;
	}
	int mid = l + r >> 1;
	if (t <= mid)
		Modify(ls(x), l, mid, t, k);
	else Modify(rs(x), mid + 1, r, t, k);
	update(x);
}

LL Query(int x, int l, int r, int s, int t)
{
	if (l == s && r == t)
		return SegTree[x];
	int mid = l + r >> 1;
	if (t <= mid) return Query(ls(x), l, mid, s, t);
	else if (s > mid) return Query(rs(x), mid + 1, r, s, t);
	else return Query(ls(x), l, mid, s, mid) + Query(rs(x), mid + 1, r, mid + 1, t);
}

int Find(int x, int l, int r, LL lim)
{
	if (l == r) return l;
	int mid = l + r >> 1;
	if (SegTree[ls(x)] <= lim)
		return Find(rs(x), mid + 1, r, lim - SegTree[ls(x)]);
	else return Find(ls(x), l, mid, lim);
}

int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", Pos + i);
		Pos[i] -= i - 1;
	}
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", W + i);
		Add(i, 1LL * Pos[i] * W[i] % Mod);
	}
	Build(1, 1, n);
	for (int a, b; q; q --)
	{
		scanf("%d%d", &a, &b);
		if (a < 0)
		{
			a = -a;
			Modify(1, 1, n, a, b);
			Add(a, 1LL * Pos[a] * Inc(b, Mod - W[a]) % Mod);
			W[a] = b;
		}
		else
		{
			int l = a, r = b;
			if (l == r)
			{
				puts("0");
				continue ;
			}
			LL sum_l = l == 1 ? 0LL : Query(1, 1, n, 1, l - 1);
			LL sum_r = Query(1, 1, n, 1, r);
			LL mid = sum_l + sum_r >> 1;
			int pos = Find(1, 1, n, mid), ppos = Pos[pos];
			int res_l = Inc(Calc(pos - 1), Mod - Calc(l - 1));
			int res_r = Inc(Calc(r), Mod - Calc(pos));
			int w_l = l >= pos ? 0 : (Query(1, 1, n, l, pos - 1) % Mod);
			int w_r = pos >= r ? 0 : (Query(1, 1, n, pos + 1, r) % Mod);
			int ans = Inc((1LL * ppos * w_l - res_l + res_r - 1LL * ppos * w_r) % Mod, Mod);
			printf("%d\n", ans);
		}
	}
	return 0;
}