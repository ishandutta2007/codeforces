#include <cstdio>
#include <cstring>

using namespace std;


const int MAXN = 222;

int f[MAXN][MAXN];
char s[MAXN];
int k, a, b, n;

int dfs(int n, int k)
{
    if (n == 0) return 0;
    dfs(n - f[n][k], k - 1);
    for (int i = n - f[n][k]; i < n; i++)
        printf("%c", s[i]);
    printf("\n");
    return 0;
}

int main()
{
/*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//*/
    scanf("%d %d %d\n", &k, &a, &b);
    gets(s);
    n = strlen(s);
    
    f[0][0] = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = a; j <= b; j++)
        {
            if (i - j < 0) break;
            int x = i - j;
            for (int z = 0; z < k; z++)
                if (f[x][z])
                    f[i][z + 1] = i - x;
        }
    }
    if (f[n][k] == 0)
    {
        puts("No solution");
        return 0;
    }
    dfs(n, k);
    return 0;
}