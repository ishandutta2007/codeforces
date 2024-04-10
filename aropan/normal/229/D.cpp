#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

const int MAXN = 5007;
const int INF = (int)1e+9 + 7;

int a[MAXN];
int s[MAXN];
int f[MAXN][MAXN];
int n;

void mini(int &x, const int d) { if (d < x) x = d; }

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i];
	}
	
	for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j <= n + 1; j++)
			f[i][j] = INF;
			
	f[1][1] = 0;
	for (int i = 1; i <= n; i++)
	{
		int k = i;
		for (int j = i; j <= n; j++)
			if (f[i][j] < INF)
			{
				mini(f[i][j + 1], f[i][j] + 1);
				while (k <= n && s[k] - s[j] < s[j] - s[i - 1]) k++;
				if (k <= n)
					mini(f[j + 1][k], f[i][j] + k - j - 1);
			}
	}
	int ans = INF;
	for (int i = 1; i <= n; i++)
		ans = min(ans, f[i][n]);
	printf("%d\n", ans);
	return 0;
}