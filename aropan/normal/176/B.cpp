#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1024;
const int MOD = 1000000007;

char a[MAXN], b[MAXN];
int f[MAXN];
int n, m;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif

    scanf("%s\n%s\n%d", a, b, &m);
    n = strlen(a);
    f[0] = 1;
    for (int i = 0; i < m; i++)
	{
		int s = 0;
		for (int j = 0; j < n; j++)
		{
			s += f[j];
			if (s >= MOD) s -= MOD;
		}

		for (int j = 0; j < n; j++)
		{
			f[j] = s - f[j];
			if (f[j] < 0) f[j] += MOD;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(a, b) == 0)
		{
			ans += f[i];
			if (ans >= MOD) ans -= MOD;
		}

		a[n] = a[0];
		memmove(a, a + 1, n + 2);
	}
	printf("%d\n", ans);
    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}