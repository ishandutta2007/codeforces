//MYCOP -> smieci
/*









*/

#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <iomanip>
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC target("avx,tune=native")

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int N = 5e5 + 7;

int z[N];
vector <int> g[N];

struct kek
{
    ll arr[3][2];
};

kek up[N];
kek dp[N];

kek tmp;

kek merge(const kek &a, const kek &b, bool can_add)
{
    auto c = tmp;
    int n = 3;
    for (int cur = 0; cur < n; cur++)
    {
        for (int x = 0; x < 2; x++)
        {
            if (!x && cur == 0) continue;
            if (x && cur == 2) continue;
            for (int there = 0; there < n; there++)
            {
                for (int y = 0; y < 2; y++)
                {
                    if (y && there == 2) continue;
                    if (!y && there == 0) continue;
                    if (!can_add)
                    {
                        if (!x || !y)
                        {
                            int have = cur + there - 1;
                            if (have >= 0 && have < n)
                            {
                                c.arr[have][(x | y)] += a.arr[cur][x] * b.arr[there][y];
                            }
                        }
                    }
                    else
                    {
                        if (!x && !y)
                        {
                            int have = cur + there - 2;
                            if (have >= 0 && have < n)
                            {
                                c.arr[have][1] += a.arr[cur][x] * b.arr[there][y];
                            }
                        }
                        int have = cur + there;
                        if (have < n)
                        {
                            c.arr[have][x] += a.arr[cur][x] * b.arr[there][y];
                        }
                    }
                }
            }
        }
    }
    return c;
}


void dfs(int v, int pr)
{
    dp[v] = tmp;
    dp[v].arr[1][0] = 1;
    z[v] = 1;
    for (int to : g[v])
    {
        if (to != pr)
        {
            dfs(to, v);
            dp[v] = merge(dp[v], dp[to], true);
            z[v] += z[to];
        }
    }
}

ll ans = 0;

int n;

void up_dfs(int v, int pr)
{
    auto res = tmp;
    res.arr[1][0] = 1;
    vector <kek> f;
    for (int to : g[v])
    {
        f.push_back(res);
        if (to != pr)
        {
            res = merge(res, dp[to], true);
        }
    }
    reverse(g[v].begin(), g[v].end());
    reverse(f.begin(), f.end());
    int sz = 0;
    res = tmp;
    res.arr[1][0] = 1;
    for (int to : g[v])
    {
        if (to != pr)
        {
            auto cur = merge(res, f[sz], false);
            if (pr != -1)
            {
                cur = merge(cur, up[pr], true);
            }
            up[v] = cur;
            up_dfs(to, v);
            for (int x = 0; x < 2; x++)
            {
                for (int y = 0; y < 2; y++)
                {
                    ans += up[v].arr[1][x] * dp[to].arr[1][y];
                    ans += up[v].arr[0][x] * dp[to].arr[0][y] * z[to] * (n - z[to]);
                }
            }
            res = merge(res, dp[to], true);
        }
        sz++;
    }
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    for (int i = 0; i < 3; i++) for (int j = 0; j < 2; j++) tmp.arr[i][j] = 0;
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, -1);
    up_dfs(0, -1);
    printf("%lld\n", ans);
}