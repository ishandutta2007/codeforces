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
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>

using namespace std;

typedef long long ll;

#ifdef ONPC
    mt19937 rnd(228);
#else
    mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int N = 1e5 + 7;
const int K = 200 + 1;
const int M = 1e9 + 7;

inline int add(int a, int b)
{
    a += b;
    if (a >= M) a -= M;
    if (a < 0) a += M;
    return a;
}

inline int mul(int a, int b)
{
    return (a * (ll) b) % M;
}

int dp[N][K][2][2];
int sz[N];
vector <int> g[N];

int cur[K][2][2];
int ncur[K][2][2];

int k;

void dfs(int v, int pr)
{
    sz[v] = 1;
    for (int to : g[v])
    {
        if (to != pr)
        {
            dfs(to, v);
            sz[v] += sz[to];
        }
    }
    for (int i = 0; i <= k; i++)
    {
        for (int t = 0; t < 2; t++)
        {
            for (int x = 0; x < 2; x++)
            {
                cur[i][t][x] = 0;
            }
        }
    }
    cur[0][0][0] = cur[0][1][0] = 1;
    int me = 1;
    for (int to : g[v])
    {
        if (to != pr)
        {
            for (int i = 0; i <= k; i++)
            {
                for (int x = 0; x < 2; x++)
                {
                    for (int y = 0; y < 2; y++)
                    {
                        ncur[i][x][y] = 0;
                    }
                }
            }
            for (int i = 0; i <= me && i <= k; i++)
            {
                for (int have = bool(i); have < 2; have++)
                {
                    for (int need = 0; need < 2; need++)
                    {
                        if (!cur[i][have][need]) continue;
                        for (int j = 0; j <= sz[to] && i + j <= k; j++)
                        {
                            for (int he_have = bool(j); he_have < 2; he_have++)
                            {
                                for (int he_need = 0; he_need < 2; he_need++)
                                {
                                    int new_have = (have | he_have);
                                    int new_need = ((need && !he_have) || (he_need && !have));
                                    ncur[i + j][new_have][new_need] = add(ncur[i + j][new_have][new_need], mul(cur[i][have][need], dp[to][j][he_have][he_need]));
                                    if (he_have && i + j + 1 <= k)
                                    {
                                        int new_need = ((need && !he_have) || (1 && !have));
                                        ncur[i + j + 1][new_have][new_need] = add(ncur[i + j + 1][new_have][new_need], mul(cur[i][have][need], dp[to][j][he_have][he_need]));
                                    }
                                }
                            }
                        }
                    }
                }
            }
            me += sz[to];
            for (int i = 0; i <= k; i++)
            {
                for (int x = 0; x < 2; x++)
                {
                    for (int y = 0; y < 2; y++)
                    {
                        cur[i][x][y] = ncur[i][x][y];
                    }
                }
            }
        }
    }
    for (int i = 0; i <= k; i++)
    {
        for (int x = 0; x < 2; x++)
        {
            for (int y = 0; y < 2; y++)
            {
                dp[v][i][x][y] = cur[i][x][y];
            }
        }
    }
}

int comb[K][K];

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n >> k;
    comb[0][0] = 1;
    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            comb[i + 1][j] = add(comb[i + 1][j], mul(comb[i][j], j));
            comb[i + 1][j + 1] = add(comb[i + 1][j + 1], mul(comb[i][j], j + 1));
        }
    }
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, -1);
    int ans = 0;
    for (int i = 0; i <= k; i++)
    {
        for (int have = 0; have < 2; have++)
        {
       //     for (int need = 0; need < 2; need++)
            int need = 0;
            {
                ans = add(ans, mul(dp[0][i][have][need], comb[k][i]));
            }
        }
    }
    cout << ans << '\n';
}