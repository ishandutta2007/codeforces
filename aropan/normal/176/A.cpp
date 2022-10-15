#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>

using namespace std;


const int MAXN = 128;

int a[MAXN][MAXN], b[MAXN][MAXN], c[MAXN][MAXN];
int f[MAXN];
int n, m, k;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif

    scanf("%d %d %d\n", &n, &m, &k);
    for (int i = 0; i < n; i++)
    {
    	scanf("%*s\n");
    	for (int j = 0; j < m; j++)
    		scanf("%d %d %d\n", &a[i][j], &b[i][j], &c[i][j]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    	for (int j = 0; j < n; j++)
    	{
    		if (i == j) continue;
    		memset(f, 0, sizeof(f));
    		for (int l = 0; l < m; l++)
    		{
    			for (int x = k; x >= 0; x--)
    			{
    				for (int y = 1; y <= c[i][l]; y++)
    				{
    					if (y > x) break;
    					f[x] = max(f[x - y] + y * (b[j][l] - a[i][l]), f[x]);
    				}
    			}
/*
    			for (int x = 0; x <= k; x++)
    				printf(" %d", f[x]);
    			printf("\n");
//*/
    		}

    		for (int l = 0; l <= k; l++)
    			ans = max(f[l], ans);
        }
	printf("%d\n", ans);
    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}