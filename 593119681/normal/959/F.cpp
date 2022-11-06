#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100000 + 5
#define Mod 1000000007

int n, m, sz, A[N], Pow[N], Ans[N], S[N];

struct Query
{
	int l, x, id;
	Query(int _l = 0, int _x = 0, int _id = 0)
	{
		l = _l, x = _x, id = _id;
	}
	bool operator < (const Query& a) const
	{
		return l < a.l;
	}
}Q[N];

int Get(int x)
{
	for (int i = 1; i <= sz; i ++)
		x = min(x, x ^ S[i]);
	return x;
}

void Add(int x)
{
	S[++ sz] = x;
	for (int i = sz; i > 1; i --)
	{
		if (S[i] > S[i - 1])
			swap(S[i], S[i - 1]);
		else break ;
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	Pow[0] = 1;
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", A + i);
		Pow[i] = Pow[i - 1] * 2 % Mod;
	}
	for (int i = 1, l, x; i <= m; i ++)
	{
		scanf("%d%d", &l, &x);
		Q[i] = Query(l, x, i);
	}
	sort(Q + 1, Q + m + 1);
	for (int i = 1, t = 1; i <= n; i ++)
	{
		int x = Get(A[i]);
		if (x) Add(x);
		for (; t <= m && Q[t].l == i; t ++)
			Ans[Q[t].id] = Get(Q[t].x) ? 0 : Pow[i - sz];
	}
	for (int i = 1; i <= m; i ++)
		printf("%d\n", Ans[i]);
	return 0;
}