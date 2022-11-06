#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 10000 + 5
#define Mod 1000000007

int n, Ord_l[N], Ord_r[N], X[N], S[3];
LL m, L[N], R[N];

struct Matrix
{
	int r, c;
	int num[3][3];
	Matrix operator * (const Matrix& a)
	{
		Matrix res;
		res.r = r, res.c = a.c;
		for (int i = 0; i < res.r; i ++)
			for (int j = 0; j < res.c; j ++)
			{
				LL tmp = 0;
				for (int k = 0; k < c; k ++)
					tmp += 1LL * num[i][k] * a.num[k][j];
				res.num[i][j] = tmp % Mod;
			}
		return res;
	}
}f, g, A[8];

bool cmp_l(int u, int v)
{
	return L[u] < L[v];
}

bool cmp_r(int u, int v)
{
	return R[u] < R[v];
}

void Prepare()
{
	f.r = 1, f.c = 3, f.num[0][1] = 1;
	for (int i = 0; i < 8; i ++)
	{
		A[i].r = A[i].c = 3;
		for (int j = 0; j < 3; j ++)
			for (int k = 0; k < 3; k ++)
				A[i].num[j][k] = ((i >> k) + 1 & 1) & (abs(j - k) <= 1);
	}
}

void Modify(int a, int op, int &status)
{
	if (S[a]) status -= (1 << a);
	S[a] += op;
	if (S[a]) status += (1 << a);
}

void Power(LL t, int status)
{
	for (g = A[status]; t; t >>= 1)
	{
		if (t & 1) f = f * g;
		g = g * g;
	}
}

int main()
{
	Prepare();
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d%lld%lld", X + i, L + i, R + i);
		X[i] --, R[i] ++;
		Ord_l[i] = Ord_r[i] = i;
	}
	sort(Ord_l + 1, Ord_l + n + 1, cmp_l);
	sort(Ord_r + 1, Ord_r + n + 1, cmp_r);
	LL cur = 2;
	for (int t_l = 1, t_r = 1, status = 0; t_l <= n || t_r <= n; )
	{
		if (t_l <= n && (t_r > n || L[Ord_l[t_l]] < R[Ord_r[t_r]]))
		{
			LL tmp = L[Ord_l[t_l]];
			Power(tmp - cur, status);
			cur = tmp;
			for (; t_l <= n && L[Ord_l[t_l]] == cur; t_l ++)
				Modify(X[Ord_l[t_l]], 1, status);
		}
		else
		{
			LL tmp = R[Ord_r[t_r]];
			Power(tmp - cur, status);
			cur = tmp;
			for (; t_r <= n && R[Ord_r[t_r]] == cur; t_r ++)
				Modify(X[Ord_r[t_r]], -1, status);
		}
	}
	Power(m + 1 - cur, 0);
	printf("%d\n", f.num[0][1]);
	return 0;
}