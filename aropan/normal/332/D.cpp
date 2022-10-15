#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

int main()
{
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	
	
	int n, k;
	scanf("%d %d", &n, &k);
	long double c[n + 1][n + 1];
	memset(c, 0, sizeof(c));
	for (int i = 0; i <= n; i++)
		c[i][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	
	int a[n][n];
	for (int i = 0; i < n; i++)
	{
		a[i][i] = -1;
		for (int j = i + 1; j < n; j++)
		{
			scanf("%d", &a[i][j]);
			a[j][i] = a[i][j];
		}
	}
	
	long double ans = 0, d = 0;
	for (int i = 0; i < n; i++)
	{
		int m = 0;
		for (int j = 0; j < n; j++)
			m += a[i][j] >= 0;
			
		if (m >= k)
		{
			d += c[m][k];
			for (int j = 0; j < n; j++)
				if (a[i][j] >= 0)
					ans += a[i][j] * c[m - 1][k - 1];
		}
	}
	cout << (long long)(ans / d + 1e-9) << endl;
	return 0;
}