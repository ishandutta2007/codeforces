#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

const int MAXN = 105;
const int MAXS = 105;

long long f[MAXN][MAXS];
int n, m;
int a[MAXN];

long double F[MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	F[0] = log(1);
	for (int i = 1; i < MAXN; i++)
		F[i] = F[i - 1] + log(i);
	int s = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		s += a[i];
	}
	scanf("%d", &m);
	if (m >= s)
	{
		printf("%d\n", n);
		return 0;
	}
/*		
	int p[n];
	for (int i = 0; i < n; i++)
		p[i] = i;
		
	int res = 0;
	do
	{
		int s = 0;
		for (int i = 0; i < n; i++)
		{
			s += a[p[i]];
			if (s > m)
			{
				res += i;
				break;
			}
		}
	} while (next_permutation(p, p + n));
	cout << exp(log(res) - F[n]) << endl;
//*/	
	
	long double ans = 0;
	for (int l = 0; l < n; l++)
	{
		memset(f, 0, sizeof(f));
		f[0][0] = 1;
		for (int i = 0; i < n; i++)
		{
			if (i == l) continue;
			
			int x = a[i];
			for (int j = MAXN - 1; j >= 1; j--)
				for (int k = m + x; k >= x; k--)
					f[j][k] += f[j - 1][k - x];
		}
		for (int i = 0; i <= n; i++)
			for (int j = max(m - a[l] + 1, 0); j <= m; j++)
				if (f[i][j])
					ans += exp(log(f[i][j]) + F[i] - F[n] + F[n - i - 1] + log(i));
	}
	cout.precision(10);
	cout << fixed << ans << endl;
	return 0;
}