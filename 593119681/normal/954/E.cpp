#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef long double LD;
#define N 200000 + 5
#define M 1000000 + 5

int n, t, F[N], A[N], T[N], q[N], Neg[N], Pos[N], Zero[N];

void Prepare()
{
	for (int i = 2; i <= n; i ++)
	{
		if (!F[i])
			F[i] = q[++ q[0]] = i;
		for (int j = 1; i * q[j] <= n && j <= q[0]; j ++)
		{
			F[i * q[j]] = q[j];
			if (i % q[j] == 0) break ;
		}
	}
}

bool cmp(const int& u, const int& v)
{
	return abs(T[u]) < abs(T[v]);
}

int main()
{
	scanf("%d%d", &n, &t);
	Prepare();
	for (int i = 1; i <= n; i ++)
		scanf("%d", A + i);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", T + i);
		T[i] -= t;
		if (T[i] < 0) Neg[++ Neg[0]] = i;
		else if (T[i] > 0) Pos[++ Pos[0]] = i;
		else Zero[++ Zero[0]] = i;
	}
	if (Neg[0] == n || Pos[0] == n) puts("0");
	else if (!Neg[0] || !Pos[0])
	{
		LL sum = 0;
		for (int i = 1; i <= Zero[0]; i ++)
			sum += A[Zero[i]];
		printf("%lld\n", sum);
	}
	else
	{
		sort(Neg + 1, Neg + Neg[0] + 1, cmp);
		sort(Pos + 1, Pos + Pos[0] + 1, cmp);
		LL sum = 0, neg = 0, pos = 0, tot;
		LD ret = 0.0, _neg = 0.0, _pos = 0.0;
		for (int i = 1; i <= Zero[0]; i ++)
			sum += A[Zero[i]];
		for (int i = 1; i <= Neg[0]; i ++)
			neg += A[Neg[i]], _neg += 1LL * A[Neg[i]] * T[Neg[i]];
		for (int i = 1; i <= Pos[0]; i ++)
			pos += A[Pos[i]], _pos += 1LL * A[Pos[i]] * T[Pos[i]];
		ret = sum + neg + pos;
		if (-_neg > _pos)
		{
			for (int i = Neg[0]; -_neg > _pos; i --)
			{
				LD a = min((LD) A[Neg[i]], (_neg + _pos) / T[Neg[i]]);
				_neg -= 1LL * a * T[Neg[i]];
				ret -= a;
			}
		}
		else if (_pos > -_neg)
		{
			for (int i = Pos[0]; _pos > -_neg; i --)
			{
				LD a = min((LD) A[Pos[i]], (_neg + _pos) / T[Pos[i]]);
				_pos -= 1LL * a * T[Pos[i]];
				ret -= a;
			}
		}
		printf("%.9f\n", (double) ret);
	}
	return 0;
}