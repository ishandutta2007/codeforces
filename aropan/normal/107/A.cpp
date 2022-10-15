#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1111;

int n, m;
int next[MAXN], v[MAXN], prev[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        next[x] = y;
        v[x] = z;
        prev[y] = x;
    }

    int k = 0;
    for (int i = 1; i <= n; i++)
        if (next[i] && prev[i] == 0)
            k++;
    printf("%d\n", k);

    for (int i = 1; i <= n; i++)
        if (next[i] && prev[i] == 0)
        {
            int x = i, res = (int)2e+9;
            while (next[x])
            {
                res = min(res, v[x]);
                x = next[x];
            }
            printf("%d %d %d\n", i, x, res);
        }
    return 0;
}