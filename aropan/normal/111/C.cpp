#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXM = 44;
const int MAXN = 7;
const int MAXK = 729;
const int INF = (int)1e+9;

int f[MAXM][MAXK];
int c[MAXK];
int a[MAXN], b[MAXN];
int n, m, k;

int maxi(int &x, int y)
{
	if (x < y) x = y;
	return 0;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    scanf("%d %d", &n, &m);

    if (n > m)
    	swap(n, m);

    k = 1;
    for (int i = 0; i < n; i++)
    	k *= 3;

    for (int i = 1; i < (1 << n); i++)
    	c[i] = c[i >> 1] + (i & 1);


    for (int i = 0; i <= m; i++)
    	for (int j = 0; j < k; j++)
    		f[i][j] = -INF;

    f[0][k - 1] = 0;
    for (int i = 0; i < m; i++)
    	for (int j = 0; j < k; j++)
    		if (f[i][j] >= 0)
         	{
         		int x = j;
         		for (int l = 0; l < n; l++)
         		{
         			a[l] = x % 3;
         			x /= 3;
         		}
/*
         		printf("%d: ", i, j);
         		for (int l = 0; l < n; l++) printf("%d", a[l]);
         		printf(" = %d\n", f[i][j]);
//*/  
         		for (int t = 0; t < (1 << n); t++)
         		{
         			for (int l = 0; l < n; l++)
         				b[l] = (t & (1 << l)) >> l;

         			for (int l = 0; l < n; l++)
         			{
         				if (b[l]) continue;
         				if (l && b[l - 1] == 1 || l < n && b[l + 1] == 1 || a[l] == 1) b[l] = 2;
         			}

         			bool flag = true;
         			for (int l = 0; l < n && flag; l++)
         				flag = a[l] || b[l] == 1;

         			if (!flag) continue;

         			int x = 0;
         			for (int l = n - 1; l >= 0; l--)
         				x = x * 3 + b[l];

         			maxi(f[i + 1][x], f[i][j] + n - c[t]);
/*
         			printf(" ");
         		    for (int l = 0; l < n; l++) printf("%d", b[l]);
         		    printf("\n");
//*/
         		}
         	}
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
    	int x = i;
    	bool flag = true;
    	for (int j = 0; j < n && flag; j++)
    	{
    		flag = x % 3 != 0;
    		x /= 3;
    	}
    	if (flag)
    		ans = max(ans, f[m][i]);
    }
    printf("%d\n", ans);
    return 0;
}