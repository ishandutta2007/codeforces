#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
int a[N];

int c[N];

int k;
void dfs(int x)
{
    c[x] = k;
    if (!c[a[x]])
    {
        dfs(a[x]);
    }
}

int q[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        c[i] = 0;
    k = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i])
        {
            ++k;
            dfs(i);
        }
    }
    for (int i = 1; i <= k; ++i)
        q[i] = 0;
    for (int i = 1; i <= n; ++i)
        q[c[i]]++;
    for (int i = 1; i <= n; ++i)
        printf("%d ", q[c[i]]);
    printf("\n");
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        solv();
    }
    return 0;
}