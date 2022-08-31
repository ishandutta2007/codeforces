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
#include <bitset>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int N = 2e5 + 7;
const int M = 21;

vector <int> g[N];

vector <pair <int, int> > ev[N];
int sz[N];
int X[N];
int val[N];
int pal[M];
int tin[N];
int tout[N];
int res[N];
ll add[N];
ll ans[N];
int go[N];

int tt = 0;

void zhfs(int v, int pr, int cur)
{
    res[tt] = v;
    tin[v] = tt++;
    cur ^= X[v];
    val[v] = cur;
    sz[v] = 1;
    for (int to : g[v])
    {
        if (to != pr)
        {
            zhfs(to, v, cur);
            sz[v] += sz[to];
        }
    }
    tout[v] = tt;
}

int cnt[(1 << M)];

void dfs(int v, int pr, bool keep)
{
    int x = -1;
    sz[v] = 1;
    for (int to : g[v])
    {
        if (to != pr)
        {
            if (x == -1 || (sz[to] > sz[x]))
            {
                x = to;
            }
        }
    }
    go[v] = x;
    if (x == -1)
    {
        cnt[val[v]]++;
        ans[v] = 1;
    }
    else
    {
        ans[v] = 1;
        for (int to : g[v])
        {
            if (to != pr && to != x)
            {
                dfs(to, v, 0);
            }
        }
        dfs(x, v, 1);
        for (int to : g[v])
        {
            if (to != pr && to != x)
            {
                for (int i = tin[to]; i < tout[to]; i++)
                {
                    int num = res[i];
                    int kek = val[num];
                    for (int j = 0; j < M; j++)
                    {
                        int need = (kek ^ pal[j] ^ X[v]);
                        if (!cnt[need]) continue;
                        ev[v].push_back({to, need});
                        add[num] += cnt[need];
                        if (pr != -1)
                        {
                            add[pr] -= 2 * cnt[need];
                        }
                        ans[v] -= cnt[need];
                    }
                }
                for (int i = tin[to]; i < tout[to]; i++)
                {
                    cnt[val[res[i]]]++;
                }
            }
        }
        for (int i = 0; i < M; i++)
        {
            int need = (val[v] ^ pal[i] ^ X[v]);
            if (pr != -1)
            {
                add[pr] -= cnt[need];
            }
        }
        cnt[val[v]]++;
    }
    if (!keep) for (int i = tin[v]; i < tout[v]; i++) cnt[val[res[i]]]--;
}

ll events[(1 << 20)];

void prec(int v, int pr)
{
    add[v] += events[val[v]];
    vector <int> ord;
    if (go[v] != -1)
    {
        ord.push_back(go[v]);
    }
    for (int to : g[v])
    {
        if (to != pr && to != go[v])
        {
            ord.push_back(to);
        }
    }
    for (auto c : ev[v])
    {
        events[c.second]++;
    }
    int j = -1;
    for (int k = 0; k < M; k++)
    {
        int need = (val[v] ^ X[v] ^ pal[k]);
        events[need]++;
    }
    for (int to : ord)
    {
        while (j + 1 < (int) ev[v].size() && ev[v][j + 1].first == to)
        {
            events[ev[v][j + 1].second]--;
            j++;
        }
        prec(to, v);
        add[v] += add[to];
    }
    ans[v] += add[v];
    for (int k = 0; k < M; k++)
    {
        int need = (val[v] ^ X[v] ^ pal[k]);
        events[need]--;
    }
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i + 1 < M; i++)
    {
        pal[i] = (1 << i);
    }
    pal[M - 1] = 0;
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        X[i] = (1 << (s[i] - 'a'));
    }
    zhfs(0, -1, 0);
    dfs(0, -1, 0);
    prec(0, -1);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}