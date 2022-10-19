#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 22;

int n, m;
bool c[(1 << N)];

bool cc[2][(1 << N)];
void dfs(int u, int x)
{
    if (cc[u][x])
        return;
    cc[u][x] = true;
    if (u == 1)
    {
        dfs(0, x);
    }
    else
    {
        int xx = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!(x & (1 << i)))
            {
                xx |= (1 << i);
                dfs(0, (x | (1 << i)));
            }
        }
        if (c[xx])
            dfs(1, xx);
    }
}

void solv()
{
    scanf("%d%d", &n, &m);
    while (m--)
    {
        int x;
        scanf("%d", &x);
        c[x] = true;
    }
    int ans = 0;
    for (int x = 0; x < (1 << n); ++x)
    {
        if (c[x])
        {
            if (!cc[1][x])
            {
                ++ans;
                dfs(1, x);
            }
        }
    }
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}