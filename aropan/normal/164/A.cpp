#include <cstdio>
#include <cmath>
#include <queue>
#include <ctime>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 100007;
const int MAXM = 200007;

int next[MAXM], dest[MAXM];
int last[MAXN];

int rnext[MAXM], rdest[MAXM];
int rlast[MAXN];
int t[MAXN];
int f[MAXN], g[MAXN];
int n, m;
queue <int> q;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &t[i]);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);

        dest[i] = y;
        next[i] = last[x];
        last[x] = i;

        rdest[i] = x;
        rnext[i] = rlast[y];
        rlast[y] = i;
    }

    for (int i = 1; i <= n; i++)
        if (t[i] == 1)
        {
            f[i] = true;
            q.push(i);
        }
    while (q.size())
    {
        int x = q.front();
        q.pop();
        for (int i = last[x]; i; i = next[i])
            if (!f[dest[i]])
            {
                f[dest[i]] = true;
                q.push(dest[i]);
            }
    }
    
    for (int i = 1; i <= n; i++)
        if (t[i] == 2)
        {
            g[i] = true;
            q.push(i);
        }
    while (q.size())
    {
        int x = q.front();
        q.pop();
        if (t[x] == 1) continue;
        for (int i = rlast[x]; i; i = rnext[i])
            if (!g[rdest[i]])
            {
                g[rdest[i]] = true;
                q.push(rdest[i]);
            }
    }

    for (int i = 1; i <= n; i++)
        printf("%d\n", f[i] && g[i]);
    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}