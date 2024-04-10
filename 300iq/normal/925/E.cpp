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
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize("Ofast")

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int N = 1e5 + 7;

vector <int> path[N];
bool del[N];
bool vis[N];
int terp[N];
int tin[N];
int tout[N];
int p[N];
int add[N];
int value[N];
vector <int> g[N];

/*

void dfs(int v, int pr)
{
    tin[v] = tt++;
    for (int to : g[v])
    {
        if (to != pr)
        {
            dfs(to, v);
        }
    }
    tout[v] = tt++;
}

*/

void zhfs(int v, int pr)
{
    add[v] = vis[v];
    for (int to : g[v])
    {
        if (to != pr)
        {
            zhfs(to, v);
            add[v] += add[to];
        }
    }
}

int bal_p[N];

vector <int> keep[N];
vector <int> jump_l[N];
vector <int> jump_r[N];
int ptr[N];

inline int get_p(int v)
{
    while (ptr[v] >= 0 && keep[v][ptr[v]] >= bal_p[v]) ptr[v] = jump_l[v][ptr[v]];
    while (ptr[v] + 1 < (int) keep[v].size() && keep[v][ptr[v] + 1] < bal_p[v]) ptr[v] = jump_r[v][ptr[v] + 1] - 1;
    int ret = ptr[v] + 1;
    if (del[path[v][0]] && vis[path[v][0]] && value[path[v][0]] < bal_p[v])
    {
        ret--;
    }
    return ret;
}

int ans = 0;

int par[N];

void add_vert(int v)
{
    ans -= get_p(v);
    vis[v] = false;
    ans += get_p(v);
    while (v != -1)
    {
        ans -= get_p(v);
        bal_p[v]--;
        ans += get_p(v);
        v = par[v];
    }
}

void del_vert(int v)
{
    ans -= get_p(v);
    vis[v] = true;
    ans += get_p(v);
    while (v != -1)
    {
        ans -= get_p(v);
        bal_p[v]++;
        ans += get_p(v);
        v = par[v];
    }
}

int it = 0;

int build_path(int v, int pr)
{
    vector <int> ans;
    for (int to : g[v])
    {
        if (to != pr)
        {
            int x = build_path(to, v);
            if (x != -1)
            {
                ans.push_back(x);
            }
        }
    }
    if (del[v] || (int) ans.size() >= 2)
    {
        for (int c : ans)
        {
            par[c] = v;
        }
        path[v].push_back(v);
        return v;
    }
    else
    {
        if ((int) ans.size() == 0)
        {
            return -1;
        }
        path[ans[0]].push_back(v);
        return ans[0];
    }
}

const int K = 1024;

int cnt[500000];
int ind[500000];
int p_ind[500000];

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 100000, m = 100000;
    cin >> n >> m;
    p[0] = -1;
    for (int i = 1; i < n; i++)
    {
        cin >> p[i];
        p[i]--;
        g[p[i]].push_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> terp[i];
    }
    vector <int> q(m);
    for (int i = 0; i < m; i++)
    {
        cin >> q[i];
    }
    for (int i = 0; i < m; i += K)
    {
        for (int x = 0; x < n; x++)
        {
            del[x] = 0;
            path[x].clear();
            keep[x].clear();
        }
        int en = min(m, i + K);
        for (int j = i; j < en; j++)
        {
            int v = abs(q[j]) - 1;
            del[v] = 1;
        }
        int x = build_path(0, -1);
        par[x] = -1;
        zhfs(0, -1);
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            value[i] = terp[i] - add[i];
            p_ind[i] = -1;
            if (!vis[i] && value[i] < 0)
            {
                ans++;
            }
        }
        for (int i = 0; i <= 2 * n + 1; i++) cnt[i] = 0;
        for (int i = 0; i < n; i++)
        {
            for (int c : path[i])
            {
                p_ind[c] = i;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (p_ind[i] != -1)
            {
                if (del[i] || !vis[i])
                {
                    cnt[value[i] + n + 1]++;
                }
            }
        }
        for (int i = 1; i <= 2 * n + 1; i++) cnt[i] += cnt[i - 1];
        int ret = cnt[2 * n + 1];
        for (int i = 0; i < n; i++)
        {
            if (p_ind[i] != -1)
            {
                if (del[i] || !vis[i])
                {
                    ind[cnt[value[i] + n]++] = i;
                }
            }
        }
        for (int i = 0; i < ret; i++)
        {
            keep[p_ind[ind[i]]].push_back(value[ind[i]]);
        }
        for (int i = 0; i < n; i++)
        {
            bal_p[i] = 0;
            ptr[i] = -1;
            jump_r[i].resize(keep[i].size());
            jump_l[i].resize(keep[i].size());
            jump_l[i].shrink_to_fit();
            jump_r[i].shrink_to_fit();
            if (keep[i].size())
            {
                {
                    int last = -1;
                    int val = -1;
                    for (int j = 0; j < (int) keep[i].size(); j++)
                    {
                        if (keep[i][j] == val)
                        {
                            jump_l[i][j] = last;
                        }
                        else
                        {
                            jump_l[i][j] = j - 1;
                            last = j;
                            val = keep[i][j];
                        }
                    }
                }
                {
                    int last = (int) keep[i].size();
                    int val = -1;
                    for (int j = (int) keep[i].size() - 1; j >= 0; j--)
                    {
                        if (keep[i][j] == val)
                        {
                            jump_r[i][j] = last;
                        }
                        else
                        {
                            jump_r[i][j] = j + 1;
                            last = j;
                            val = keep[i][j];
                        }
                    }
                }
            }
        }
        for (int j = i; j < en; j++)
        {
            int v = abs(q[j]) - 1;
            if (q[j] > 0)
            {
                del_vert(v);
            }
            else
            {
                add_vert(v);
            }
            cout << ans << ' ';
        }
    }
    cout << '\n';
}