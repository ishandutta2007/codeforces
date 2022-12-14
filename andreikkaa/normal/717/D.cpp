#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct matrix
{
	int n;
	double a[207][207];
	matrix()
	{
		n = 0;
	}
	matrix(int _n)
	{
		n = _n;
		for (int i = 0; i < 207; i++)
		{
			for (int j = 0; j < 207; j++)
			{
				a[i][j] = 0;
			}
			a[i][i] = 1;
		}
	}
};
matrix operator*(matrix a, matrix b)
{
	matrix res;
	res.n = a.n;
	int n = a.n;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			for (int k = 0; k <= n; k++)
			{
				res.a[i][j] = res.a[i][j] + a.a[i][k] * b.a[k][j];
				//cerr << i << " " << k << " " << j << endl;
			}
		}
	}
	return res;
}
matrix matPow(matrix a, int x)
{
	if (x == 1) return a;
	if (x % 2 == 0)
	{
		matrix res = matPow(a, x / 2);
		return res * res;
	}
	else
	{
		matrix res = matPow(a, x - 1);
		return res * a;
	}
}
double p[107];
int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i <= k; i++)
	{
		scanf("%lf", &p[i]);
	}
	matrix go;
	go.n = 2 * k;
	for (int i = 0; i <= 2 * k; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			if ((i ^ j) <= 2 * k)
			{
				go.a[i][i ^ j] += p[j];
				//cerr << i << " " << (i ^ j) << " " << p[j] << endl;
			}
		}
	}
	go = matPow(go, n);
	printf("%.10lf\n", 1 - go.a[0][0]);
}