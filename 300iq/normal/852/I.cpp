
/*
    !  !!!
   
   
   
   
   
   
   
   
   
   
   
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

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int N = 1e5 + 7;

int a[N];
int t[N];
int cnt[N][2];
int dist[N];
bool used[N];

vector <pair <int, int> > need[N];
vector <int> g[N];
int best[N];
ll result[N];
int par[N];

ll ans = 0;

inline void add(int x, int t)
{
    ans += cnt[x][t ^ 1];
    cnt[x][t]++;
}

inline void del(int x, int t)
{
    ans -= cnt[x][t ^ 1];
    cnt[x][t]--;
}

inline void calc_par(int v, int pr)
{
    par[v] = pr;
    for (int to : g[v])
    {
        if (to != pr)
        {
            calc_par(to, v);
        }
    }
}

inline void dfs(int root, int v, int pr)
{
    add(a[v], t[v]);
    used[v] = true;
    for (auto q : need[v])
    {
        if (best[q.first] == root)
        {
            int cur = q.first; 
            bool gg = false;
            while (cur != -1)
            {
                if (!used[cur])
                {
                    add(a[cur], t[cur]);
                }
                else
                {
                    if (gg)
                    {
                        del(a[cur], t[cur]);
                    }
                    else
                    {
                        gg = true;
                    }
                }
                cur = par[cur];
            }
            gg = false;
            result[q.second] = ans;
            cur = q.first; 
            while (cur != -1)
            {
                if (!used[cur])
                {
                    del(a[cur], t[cur]);
                }
                else
                {
                    if (gg)
                    {
                        add(a[cur], t[cur]);
                    }
                    else
                    {
                        gg = true;
                    }
                }
                cur = par[cur];
            }
        }
    }
    for (int to : g[v])
    {
        if (to != pr)
        {
            dfs(root, to, v);
        }
    }
    del(a[v], t[v]);
    used[v] = false;
}

inline void go(int v, int pr, vector <int> &a)
{
    a.push_back(v);
    for (int to : g[v])
    {
        if (to != pr)
        {
            go(to, v, a);
            a.push_back(v);
        }
    }
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t[i]);
    }
    vector <int> arr;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        arr.push_back(a[i]);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        a[i] = lower_bound(arr.begin(), arr.end(), a[i]) - arr.begin();
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector <int> ch;
    go(0, 0, ch);
    vector <int> root;
    queue <int> qu;
    int m = (int) ch.size();
    int k = 2468;
    for (int i = 0; i < m; i += k)
    {
        root.push_back(ch[i]);
    }
    for (int i = 0; i < n; i++)
    {
        best[i] = -1;
    }
    for (int v : root) best[v] = v, qu.push(v);
    while (!qu.empty())
    {
        int v = qu.front();
        qu.pop();
        for (int to : g[v])
        {
            if (best[to] == -1)
            {
                best[to] = best[v];
                dist[to] = dist[v] + 1;
                qu.push(to);
            }
        }
    }
    int q;
    scanf("%d", &q);
    vector <int> cnt(n);
    for (int i = 0; i < q; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        if (dist[a] < dist[b])
        {
            swap(a, b);
        }
        need[a].push_back({b, i});
        cnt[best[b]]++;
    }
    vector <bool> real(n);
    for (int v : root)
    {
        if (!cnt[v] || real[v]) continue;
        real[v] = true;
        calc_par(v, -1);
        dfs(v, v, -1);
    }
    for (int i = 0; i < q; i++)
    {
        printf("%lld\n", result[i]);
    }
}