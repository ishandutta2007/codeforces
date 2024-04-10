#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define M 1002

int o[M][M], d1[M][M], d2[M][M], d3[M][M], d4[M][M];

void read(int& x)
{
    x = 0;
    char ch = getchar();
    while(ch < '0') ch = getchar();
    while(ch >= '0') x = x * 10 + ch - '0', ch = getchar();
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            read(o[i][j]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            d1[i][j] = max(d1[i-1][j] , d1[i][j-1]) + o[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = m; j >= 1; j--)
            d2[i][j] = max(d2[i-1][j] , d2[i][j+1]) + o[i][j];
    for(int i = n; i >= 1; i--)
        for(int j = 1; j <= m; j++)
            d3[i][j] = max(d3[i+1][j] , d3[i][j-1]) + o[i][j];
    for(int i = n; i >= 1; i--)
        for(int j = m; j >= 1; j--)
            d4[i][j] = max(d4[i+1][j] , d4[i][j+1]) + o[i][j];
    int ans = 0;
    for(int i = 2; i < n; i++)
        for(int j = 2; j < m; j++)
            ans = max(ans, max(d1[i][j-1] + d2[i-1][j] + d3[i+1][j] + d4[i][j+1],
                               d1[i-1][j] + d2[i][j+1] + d3[i][j-1] + d4[i+1][j]));
    printf("%d\n", ans);
    return 0;
}