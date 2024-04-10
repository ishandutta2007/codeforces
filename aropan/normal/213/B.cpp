#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

using namespace std;


const int MOD = 1000000007;
const int MAXN = 107;


long long f[MAXN];
int n;
int a[10];
long long F[MAXN][MAXN];
long long C[MAXN][MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	
	scanf("%d", &n);
	int m = 0;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
		m += a[i];
	}
	if (m > n)
	{
		puts("0");
		return 0;
	}
	
//*	
	if (m == 0)
	{
		long long res = 1;
		for (int i = 1; i <= n; i++)
			(res *= 10) %= MOD;
		cout << (res - 1 + MOD) % MOD << endl;
		return 0;
	}
//*/	
	for (int i = 0; i < MAXN; i++)
		C[i][0] = 1;

	for (int i = 1; i < MAXN; i++)
		for (int j = 1; j <= i; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
			
	long long res = 0;
	F[10][0] = 1;
	for (int i = 10; i >= 1; i--)
		for (int j = 0; j <= n; j++)
			if (F[i][j])
				for (int x = a[i - 1]; x + j <= n; x++)
					(F[i - 1][x + j] += F[i][j] * C[x + j - (int)(i == 1 && x > 0)][x]) %= MOD;
	for (int i = 0; i <= n; i++)
		(res += F[0][i]) %= MOD;
	cout << res << endl;
	return 0;
}