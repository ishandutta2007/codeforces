#include <cstdio>
#include <algorithm>
using namespace std;
#define N 200000 + 5
#define M 524288 + 5
#define E 20000000 + 5
#define Mod 998244353
#define ls(x) x << 1
#define rs(x) x << 1 | 1

int n, q, tot, _tot, Root[N], L[E], R[E];
bool Flag[E];

struct Result
{
	bool Min, Max;
	Result() : Result(0, 0) {}
	Result(bool Min, bool Max) : Min(Min), Max(Max) {}
	Result operator + (Result&& a)
	{
		return Result(min(Min, a.Min), max(Max, a.Max));
	}
}H[E];

struct SegTree
{
	int cnt, del_a, del_b;	
}h[M];

inline int Inc(int u, int v)
{
	return u + v - (u + v >= Mod ? Mod : 0);
}

void apply(int &x)
{
	if (!x) x = ++ _tot;
	Flag[x] = 1;
	H[x].Min = H[x].Max = 1;
}

void apply(int x, int l, int r, int op, int k)
{
	if (op == 0)
	{
		h[x].cnt = Inc(h[x].cnt, 1LL * (r - l + 1) * k % Mod);
		h[x].del_a = Inc(h[x].del_a, k);
	}
	else
	{
		h[x].cnt = 1LL * h[x].cnt * k % Mod;
		h[x].del_a = 1LL * h[x].del_a * k % Mod;
		h[x].del_b = 1LL * h[x].del_b * k % Mod;
	}
}

void push(int x, int l, int r)
{
	int mid = l + r >> 1;
	if (h[x].del_b != 1)
	{
		apply(ls(x), l, mid, 1, h[x].del_b);
		apply(rs(x), mid + 1, r, 1, h[x].del_b);
		h[x].del_b = 1;
	}
	if (h[x].del_a)
	{
		apply(ls(x), l, mid, 0, h[x].del_a);
		apply(rs(x), mid + 1, r, 0, h[x].del_a);
		h[x].del_a = 0;
	}
}

void push(int x)
{
	if (Flag[x])
	{
		apply(L[x]);
		apply(R[x]);
		Flag[x] = 0;
	}
}

void Modify(int &x, int l, int r, int s, int t)
{
	if (!x) x = ++ _tot;
	if (l == s && r == t)
	{
		apply(x);
		return ;
	}
	push(x);
	int mid = l + r >> 1;
	if (t <= mid) Modify(L[x], l, mid, s, t);
	else if (s > mid) Modify(R[x], mid + 1, r, s, t);
	else Modify(L[x], l, mid, s, mid), Modify(R[x], mid + 1, r, mid + 1, t);
	H[x].Min = min(H[L[x]].Min, H[R[x]].Min);
	H[x].Max = max(H[L[x]].Max, H[R[x]].Max);
}

void Modify(int x, int l, int r, int s, int t, int op, int k)
{
	if (!x) h[++ tot] = h[x], x = tot;
	if (l == s && r == t)
	{
		apply(x, l, r, op, k);
		return ;
	}
	push(x, l, r);
	int mid = l + r >> 1;
	if (t <= mid) Modify(ls(x), l, mid, s, t, op, k);
	else if (s > mid) Modify(rs(x), mid + 1, r, s, t, op, k);
	else Modify(ls(x), l, mid, s, mid, op, k), Modify(rs(x), mid + 1, r, mid + 1, t, op, k);
	h[x].cnt = Inc(h[ls(x)].cnt, h[rs(x)].cnt);
}

Result Query(int x, int l, int r, int s, int t)
{
	if (l == s && r == t) return Result(H[x].Min, H[x].Max);
	push(x);
	int mid = l + r >> 1;
	if (t <= mid) return Query(L[x], l, mid, s, t);
	else if (s > mid) return Query(R[x], mid + 1, r, s, t);
	else return Query(L[x], l, mid, s, mid) + Query(R[x], mid + 1, r, mid + 1, t);
}

Result Query(int x, int l, int r, int s, int t, int op, int &rec)
{
	if (l == r)
	{
		rec = l;
		return Result(H[x].Min, H[x].Max);
	}
	push(x);
	int mid = l + r >> 1;
	if (l == s && r == t)
	{
		if (!op)
		{
			if (H[L[x]].Min > H[R[x]].Min)
				return Query(R[x], mid + 1, r, mid + 1, t, op, rec);
			else return Query(L[x], l, mid, s, mid, op, rec);
		}
		else
		{
			if (H[L[x]].Max < H[R[x]].Max)
				return Query(R[x], mid + 1, r, mid + 1, t, op, rec);
			else return Query(L[x], l, mid, s, mid, op, rec);
		}
	}
	if (t <= mid) Query(L[x], l, mid, s, t, op, rec);
	else if (s > mid) Query(R[x], mid + 1, r, s, t, op, rec);
	else
	{
		int rec_1 = 0, rec_2 = 0;
		Result tmp_1 = Query(L[x], l, mid, s, mid, op, rec_1);
		Result tmp_2 = Query(R[x], mid + 1, r, mid + 1, t, op, rec_2);
		if ((!op && tmp_1.Min > tmp_2.Min) || (op && tmp_1.Max < tmp_2.Max))
		{
			rec = rec_2;
			return tmp_2;
		}
		else
		{
			rec = rec_1;
			return tmp_1;
		}
	}
}

int _Query(int x, int l, int r, int s, int t)
{
	if (!x) return 0;
	if (l == s && r == t) return h[x].cnt;
	push(x, l, r);
	int mid = l + r >> 1;
	if (t <= mid) return _Query(ls(x), l, mid, s, t);
	else if (s > mid) return _Query(rs(x), mid + 1, r, s, t);
	else return Inc(_Query(ls(x), l, mid, s, mid), _Query(rs(x), mid + 1, r, mid + 1, t));
}

int main()
{
	h[0].del_b = 1;
	scanf("%d%d", &n, &q);
	for (int i = 1, op; i <= q; i ++)
	{
		scanf("%d", &op);
		if (op == 1)
		{
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			Result res = Query(Root[x], 1, n, l, r);
			if (res.Max == 0)
			{
				Modify(Root[x], 1, n, l, r);
				Modify(1, 1, n, l, r, 0, 1);
			}
			else if (res.Min == 1)
			{
				Modify(1, 1, n, l, r, 1, 2);
			}
			else
			{
				res = Query(Root[x], 1, n, l, l);
				for (int st = l, op = res.Min, ed; st <= r; st = ed, op ^= 1)
				{
					Query(Root[x], 1, n, st, r, op ^ 1, ed);
					if (st == ed) ed = r + 1;
					Modify(1, 1, n, st, ed - 1, op, op + 1);
					if (!op) Modify(Root[x], 1, n, st, ed - 1);
				}
			}
		}
		else
		{
			int l, r;
			scanf("%d%d", &l, &r);
			int res = _Query(1, 1, n, l, r);
			printf("%d\n", res);
		}
	}
	return 0;
}