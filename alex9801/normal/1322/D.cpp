#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int arr[2050];
int cst[2050];
int pro[4050];
int mem[2050][2050];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    for(int i = 1; i <= n; i++)
        scanf("%d", &cst[i]);
    for(int i = 1; i <= n + m; i++)
        scanf("%d", &pro[i]);

    for(int i = 0; i <= m + 11; i++)
    {
        mem[i][0] = 0;
        for(int k = 1; k <= n; k++)
            mem[i][k] = -INF;
    }

    for(int i = n; i >= 1; i--)
    {
        int x = arr[i];
        for(int k = n; k >= 1; k--)
            mem[x][k] = max(mem[x][k], mem[x][k - 1] - cst[i] + pro[x]);

        int t = n;
        for(int j = x + 1; j <= m + 11; j++)
        {
            for(int k = 0; k <= t; k++)
                mem[j][k / 2] = max(mem[j][k / 2], mem[j - 1][k] + (k / 2) * pro[j]);
            t /= 2;
        }
    }

    printf("%d\n", mem[m + 11][0]);
    return 0;
}