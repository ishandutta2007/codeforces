#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;
const int MAXL = 3003;
const int MAXN = 101;

int f[MAXL][MAXN][2];
int a[MAXN], b[MAXN];
int n, m;

void add(int &x, int d)
{
	x += d;
	if (x >= MOD) x -= MOD;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    	scanf("%d %d", &a[i], &b[i]);

    for (int i = 0; i < n; i++)
    {
    	f[a[i]][i][0] = 1;
		f[b[i]][i][1] = 1;
    }

    for (int i = 1; i < m; i++)
    	for (int j = 0; j < n; j++)
    		for (int t = 0; t < 2 - (int)(a[j] == b[j]); t++)
    			if (f[i][j][t])
    			{
    				for (int k = 0; k < n; k++)
    				{
    					if (k == j) continue;
    					int v = t == 0? b[j] : a[j];
    					if (v == a[k] && i + a[k] <= m) add(f[i + a[k]][k][0], f[i][j][t]);
    					if (v == b[k] && i + b[k] <= m) add(f[i + b[k]][k][1], f[i][j][t]);
    				}
    			}
    int ans = 0;
    for (int j = 0; j < n; j++)
    	for (int t = 0; t < 2 - (int)(a[j] == b[j]); t++)
    		add(ans, f[m][j][t]);
    printf("%d\n", ans);
    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}