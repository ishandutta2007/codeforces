/*
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
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const ll is_query = -(1LL << 62);

struct Line {
    ll m, b;
    mutable function<const Line *()> succ;

    bool operator<(const Line &rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const Line *s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};

struct HullDynamic : public multiset<Line> {
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;
        return (x->b - y->b) * (long double) (z->m - y->m) >= (y->b - z->b) * (long double) (y->m - x->m);
    }

    void insert_line(ll m, ll b) {
        auto y = insert({m, b});
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) {
            erase(y);
            return;
        }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }

    ll eval(ll x) {
        auto l = *lower_bound((Line) {x, is_query});
        return l.m * x + l.b;
    }
};


const int N = 1e5 + 7;

int a[N], b[N];
vector <int> g[N];
HullDynamic s[N];
int sz[N];
int who[N];
ll ans[N];
int tin[N], tout[N];
int res[N];

int tt = 0;

void dfs(int v, int pr)
{
    tin[v] = tt++;
    res[tin[v]] = v;
    int x = -1;
    sz[v] = 1;
    for (int to : g[v])
    {
        if (to != pr)
        {
            dfs(to, v);
            sz[v] += sz[to];
            if (x == -1 || sz[to] > sz[x])
            {
                x = to;
            }
        }
    }
    if (x == -1)
    {
        s[v].insert_line(-b[v], 0);
        ans[v] = 0;
        who[v] = v;
    }
    else
    {
        who[v] = who[x];
        for (int to : g[v])
        {
            if (to != x)
            {
                for (int i = tin[to]; i < tout[to]; i++)
                {
                    s[who[v]].insert_line(-b[res[i]], -ans[res[i]]);
                }
            }
        }
        ans[v] = -s[who[v]].eval(a[v]);
        s[who[v]].insert_line(-b[v], -ans[v]);
    }
    tout[v] = tt;
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}