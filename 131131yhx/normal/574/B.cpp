#include<cstdio>
#include<cstring>
#define Inf 100000001

bool bo[4001][4001];
int x[4001], y[4001], val[4001];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    memset(bo, 0, sizeof(bo));
    for(int i = 1; i <= n; i++) val[i] = -2;
    for(int i = 1; i <= m; i++)
    {
        scanf("%d%d", &x[i], &y[i]);
        bo[x[i]][y[i]] = bo[y[i]][x[i]] = 1;
        val[x[i]]++;
        val[y[i]]++;
    }
    int ans = Inf;
    for(int i = 1; i <= m; i++)
        for(int j = i+1; j <= m; j++)
        {
            if(x[i] == x[j] && bo[y[i]][y[j]] && val[x[i]] + val[y[i]] + val[y[j]] < ans) 
                ans = val[x[i]] + val[y[i]] + val[y[j]];
            if(x[i] == y[j] && bo[y[i]][x[j]] && val[x[i]] + val[y[i]] + val[x[j]] < ans)
                ans = val[x[i]] + val[y[i]] + val[x[j]];
            if(y[i] == x[j] && bo[x[i]][y[j]] && val[y[i]] + val[x[i]] + val[y[j]] < ans)
                ans = val[y[i]] + val[x[i]] + val[y[j]];
            if(y[i] == y[j] && bo[x[i]][x[j]] && val[y[i]] + val[x[i]] + val[x[j]] < ans)
                ans = val[y[i]] + val[x[i]] + val[x[j]];
        }
    if(ans == Inf) printf("-1\n"); else printf("%d\n", ans);
    return 0;
}