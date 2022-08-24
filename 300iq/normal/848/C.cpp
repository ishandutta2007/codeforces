
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
#define next abacaba_next
#define prev abacaba_prev

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int N = 1e5 + 7;

set <int> cur[N];
int prev[N];
int next[N];
vector <int> t[4 * N];
vector <ll> f[4 * N];
int n;

struct q
{
    int t, a, b;
};

void add(int v, int l, int r, int i, int x)
{
    if (r - l == 1)
    {
        t[v].push_back(x);
    }
    else
    {
        int m = (l + r) / 2;
        if (i < m)
        {
            add(v * 2 + 1, l, m, i, x);
        }
        else
        {
            add(v * 2 + 2, m, r, i, x);
        }
        t[v].push_back(x);
    }
}

void build(int v, int l, int r)
{
    if (r - l == 1)
    {
        sort(t[v].begin(), t[v].end());
        t[v].resize(unique(t[v].begin(), t[v].end()) - t[v].begin());
        f[v].resize(t[v].size());
    }
    else
    {
        int m = (l + r) / 2;
        sort(t[v].begin(), t[v].end());
        t[v].resize(unique(t[v].begin(), t[v].end()) - t[v].begin());
        f[v].resize(t[v].size());
        build(v * 2 + 1, l, m);
        build(v * 2 + 2, m, r);
    }
}

void del(int x, int y, int w)
{
    return;
}

void add(int x, int y, int w)
{
    add(0, 0, n, x, y);
}

void upd(int v, int l, int r, int i, int x, int z)
{
    int ind = lower_bound(t[v].begin(), t[v].end(), x) - t[v].begin();
    for (; ind < (int) f[v].size(); ind = (ind | (ind + 1)))
    {
        f[v][ind] += z;
    }
    if (r - l != 1)
    {
        int m = (l + r) / 2;
        if (i < m)
        {
            upd(v * 2 + 1, l, m, i, x, z);
        }
        else
        {
            upd(v * 2 + 2, m, r, i, x, z);
        }
    }
}

ll get(int v, int l, int r, int tl, int tr, int up)
{
    if (tl >= r || tr <= l)
    {
        return 0; 
    }
    if (tl >= l && tr <= r)
    {
        int cur = lower_bound(t[v].begin(), t[v].end(), up) - t[v].begin();
        ll ans = 0;
        for (int ind = (int) f[v].size() - 1; ind >= 0; ind = (ind & (ind + 1)) - 1)
        {
            ans += f[v][ind];
        }
        cur--;
        for (int ind = cur; ind >= 0; ind = (ind & (ind + 1)) - 1)
        {
            ans -= f[v][ind];
        }
        return ans;
    }
    else
    {
        int tm = (tl + tr) / 2;
        return get(v * 2 + 1, l, r, tl, tm, up) + get(v * 2 + 2, l, r, tm, tr, up);
    }
}

void real_del(int x, int y, int w)
{
    upd(0, 0, n, x, y, -w);
}

void real_add(int x, int y, int w)
{
    upd(0, 0, n, x, y, w);
}

ll real_get(int l, int r)
{
    return get(0, l, r + 1, 0, n, l);
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int m;
    scanf("%d%d", &n, &m);
    vector <int> a(n), b(n);
    for (int i = 0; i < n; i++) prev[i] = -1, next[i] = -1;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
        a[i]--;
        if (!cur[a[i]].empty())
        {
            prev[i] = *cur[a[i]].rbegin();
            next[*cur[a[i]].rbegin()] = i;
            add(i, prev[i], i - prev[i]);
        }
        else
        {
            prev[i] = -1;
        }
        cur[a[i]].insert(i);
    }
    vector <q> e;
    for (int i = 0; i < m; i++)
    {
        int t;
        scanf("%d", &t);
        if (t == 1)
        {
            int p, x;
            scanf("%d%d", &p, &x);
            p--, x--;
            e.push_back({t, p, x});
            if (prev[p] != -1)
            {
                del(p, prev[p], p - prev[p]);
            }
            int pr = prev[p];
            int go = next[p];
            if (pr != -1 && go != -1)
            {
                del(go, prev[go], go - prev[go]);
                next[pr] = go;
                prev[go] = pr;
                add(go, prev[go], go - prev[go]);
            }
            else if (pr == -1)
            {
                del(go, prev[go], go - prev[go]);
                prev[go] = -1;
            }
            else if (go == -1)
            {
                next[pr] = -1;
            }
            cur[a[p]].erase(p);
            a[p] = x;
            cur[x].insert(p);
            prev[p] = -1;
            next[p] = -1;
            auto it = cur[x].lower_bound(p);
            if (it != cur[x].begin())
            {
                auto was = it;
                was--;
                int ind = *was;
                prev[p] = ind;
                next[ind] = p;
                add(p, prev[p], p - prev[p]);
            }
            if (it != --cur[x].end())
            {
                auto was = it;
                was++;
                int ind = *was;
                if (prev[ind] != -1)
                {
                    del(ind, prev[ind], ind - prev[ind]);
                }
                prev[ind] = p;
                next[p] = ind;
                add(ind, prev[ind], ind - prev[ind]);
            }
        }
        else
        {
            int l, r;
            scanf("%d%d", &l, &r);
            l--, r--;
            e.push_back({t, l, r});
        }
    }
    build(0, 0, n);
    for (int i = 0; i < n; i++) cur[i].clear(), prev[i] = next[i] = -1;
    for (int i = 0; i < n; i++)
    {
        a[i] = b[i];
        a[i]--;
        if (!cur[a[i]].empty())
        {
            prev[i] = *cur[a[i]].rbegin();
            next[*cur[a[i]].rbegin()] = i;
            real_add(i, prev[i], i - prev[i]);
        }
        else
        {
            prev[i] = -1;
        }
        cur[a[i]].insert(i);
    }
    for (auto c : e)
    {
        int t = c.t;
        if (t == 1)
        {
            int p = c.a, x = c.b;
            if (prev[p] != -1)
            {
                real_del(p, prev[p], p - prev[p]);
            }
            int pr = prev[p];
            int go = next[p];
            if (pr != -1 && go != -1)
            {
                real_del(go, prev[go], go - prev[go]);
                next[pr] = go;
                prev[go] = pr;
                real_add(go, prev[go], go - prev[go]);
            }
            else if (pr == -1)
            {
                real_del(go, prev[go], go - prev[go]);
                prev[go] = -1;
            }
            else if (go == -1)
            {
                next[pr] = -1;
            }
            cur[a[p]].erase(p);
            a[p] = x;
            cur[x].insert(p);
            prev[p] = -1;
            next[p] = -1;
            auto it = cur[x].lower_bound(p);
            if (it != cur[x].begin())
            {
                auto was = it;
                was--;
                int ind = *was;
                prev[p] = ind;
                next[ind] = p;
                real_add(p, prev[p], p - prev[p]);
            }
            if (it != --cur[x].end())
            {
                auto was = it;
                was++;
                int ind = *was;
                if (prev[ind] != -1)
                {
                    real_del(ind, prev[ind], ind - prev[ind]);
                }
                prev[ind] = p;
                next[p] = ind;
                real_add(ind, prev[ind], ind - prev[ind]);
            }
        }
        else
        {
            int l = c.a, r = c.b;
            printf("%lld\n", real_get(l, r));
        }
    }
}