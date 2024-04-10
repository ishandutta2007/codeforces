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
const int inf = 1e9 + 7;

set <int> g[N];
int deg[N];
ll cnt[N];
ll sum[N];
map <pair <int, int>, int> len;

struct tree
{
    tree *l, *r;
    int x;
    tree(int x): x(x), l(0), r(0)
    {
    }
    tree()
    {
    }
};

map <pair <int, int>, tree*> gt;
map <pair <int, int>, int> edge;
map <pair <int, int>, vector <int> > open;
map <pair <int, int>, vector <pair <pair <ll, ll>, pair <int, int> > > > ret;

tree *merge(tree *a, tree *b, int v)
{
    tree *now = new tree(v);
    now->l = a, now->r = b;
    return now;
}

void dfs(tree *t, vector <int> &arr)
{
    if (!t) return;
    dfs(t->l, arr);
    arr.push_back(t->x);
    dfs(t->r, arr);
}

ll smart(int n, int m, vector <pair <int, int> > e)
{
    for (int i = 0; i < n; i++)
    {
        g[i].clear();
        deg[i] = 0;
        sum[i] = 0;
        cnt[i] = 0;
    }
    for (auto c : e)
    {
        int a = c.first, b = c.second;
        a--, b--;
        deg[a]++, deg[b]++;
        g[a].insert(b);
        g[b].insert(a);
    }
    gt.clear(), edge.clear(), open.clear(), ret.clear();
    set <pair <int, int> > q;
    for (int i = 0; i < n; i++)
    {
        q.insert({deg[i], i});
        cnt[i] = 1;
    }
    ll ans = 0;
    while (!q.empty())
    {
        auto it = q.lower_bound(make_pair(1, -1));
        if (it != q.end() && it->first == 1)
        {
            int v = it->second;
            q.erase(it);
            int par = *g[v].begin();
            ans += cnt[v] * sum[par] + sum[v] * cnt[par] + cnt[par] * cnt[v];
            cnt[par] += cnt[v];
            sum[par] += sum[v] + cnt[v];
            q.erase({deg[par], par});
            deg[par]--;
            g[v].erase(par);
            g[par].erase(v);
            q.insert({deg[par], par});
        }
        else
        {
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int x : g[i])
        {
            gt[{i, x}] = 0;
            edge[{i, x}] = 1;
        }
    }
    while (!q.empty())
    {
        auto it = q.lower_bound(make_pair(2, -1));
        if (it != q.end() && it->first == 2)
        {
            int v = it->second;
            q.erase(it);
            int a = *g[v].begin();
            int b = *g[v].rbegin();
            if (g[a].count(b))
            {
                continue;
            }
            else
            {
                gt[{a, b}] = merge(gt[{a, v}], gt[{v, b}], v);
                gt[{b, a}] = merge(gt[{b, v}], gt[{v, a}], v);
                edge[{a, b}] = edge[{a, v}] + edge[{v, b}];
                edge[{b, a}] = edge[{b, v}] + edge[{v, a}];
                edge[{a, v}] = edge[{b, v}] = edge[{v, a}] = edge[{v, b}] = 0;
                gt[{a, v}] = gt[{b, v}] = gt[{v, a}] = gt[{v, b}] = 0;
                g[a].erase(v);
                g[v].erase(a);
                g[b].erase(v);
                g[v].erase(b);
                g[a].insert(b);
                g[b].insert(a);
            }
        }
        else
        {
            break;
        }
    }
    vector <int> verts;
    for (int i = 0; i < n; i++)
    {
        if (!g[i].empty())
        {
            verts.push_back(i);
        }
    }
    int sz = (int) verts.size();
    vector <vector <int> > dist(sz, vector <int> (sz, inf));
    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < sz; j++)
        {
            if (i == j)
            {
                dist[i][j] = 0;
            }
            if (g[verts[i]].count(verts[j]))
            {
                dist[i][j] = edge[{verts[i], verts[j]}];
            }
        }
    }
    for (int k = 0; k < sz; k++)
    {
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    map <pair <int, int>, int> len;
    for (int i = 0; i < sz; i++) for (int j = 0; j < sz; j++)
    {
        len[{verts[i], verts[j]}] = dist[i][j];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j : g[i])
        {
            if (i < j)
            {
                vector <int> arr;
                dfs(gt[{i, j}], arr);
                open[{i, j}] = arr;
                int dist_l = 1, dist_r = (int) open[{i, j}].size();
                //cout << i + 1 << ' ' << j + 1 << " = ";
                for (int x : open[{i, j}])
                {
                    ret[{i, j}].push_back({{cnt[x], sum[x]}, {dist_l, dist_r}});
                    dist_l++, dist_r--;
                //    cout << x + 1 << ',';
                }
                //cout << endl;
            }
        }
    }
    vector <pair <int, int> > edges;
    vector <ll> s_a, s_b;
    for (int i = 0; i < n; i++)
    {
        for (int j : g[i])
        {
            if (i < j) edges.push_back({i, j});
        }
    }
    for (auto c : edges)
    {
        ll _s_a = 0, _s_b = 0;
        for (auto p : ret[c])
        {
            _s_a += p.first.first;
            _s_b += p.first.second;
        }
        s_a.push_back(_s_a);
        s_b.push_back(_s_b);
    }
    map <pair <int, int>, vector <ll> > t_ab;
    map <pair <int, int>, vector <ll> > t_a;
    map <pair <int, int>, vector <ll> > t_sos;
    for (auto c : edges)
    {
        int i = c.first, j = c.second;
        auto f = ret[{i, j}];
        int val = len[{i, j}] + edge[{i, j}];
        int ptr = -1;
        ll suf_sm = 0;
        ll suf_ct = 0;
        for (int i = 0; i < (int) f.size(); i++)
        {
            suf_ct += f[i].first.first;
            suf_sm += f[i].first.second;
        }
        vector <ll> ab;
        vector <ll> a;
        ll _ab = 0, _a = 0;
        for (int i = 0; i < (int) f.size(); i++)
        {
            _ab += f[i].first.first * f[i].second.first;
            _a += f[i].first.first;
            ab.push_back(_ab);
            a.push_back(_a);
        }
        vector <ll> sos;
        ll value = 0;
        for (int i = (int) f.size() - 1; i >= 0; i--)
        {
            value += f[i].first.first * f[i].second.second;
            sos.push_back(value);
        }
        reverse(sos.begin(), sos.end());
        t_sos[c] = sos;
        auto get_ab = [&] (int l, int r)
        {
            if (l > r) return 0ll;
            if (!l) return ab[r];
            else return ab[r] - ab[l - 1];
        };
        auto get_a = [&] (int l, int r)
        {
            if (l > r) return 0ll;
            if (!l) return a[r];
            else return a[r] - a[l - 1];
        };
        t_ab[c] = ab;
        t_a[c] = a;
        for (int i = 0; i < (int) f.size(); i++)
        {
            while (ptr + 1 < (int) f.size() && f[ptr + 1].second.first - f[i].second.first <= val / 2)
            {
                ptr++;
            }
            suf_ct -= f[i].first.first;
            suf_sm -= f[i].first.second;
            ll cur_sum = get_ab(i + 1, ptr) - get_a(i + 1, ptr) * f[i].second.first;
            /*
            for (int x = i + 1; x <= ptr; x++)
            {
                cur_sum += f[x].first.first * f[x].second.first;
                cur_sum -= f[x].first.first * f[i].second.first;
            }
            */
            cur_sum += get_a(ptr + 1, (int) f.size() - 1) * (val + f[i].second.first) - get_ab(ptr + 1, (int) f.size() - 1);
            /*
            for (int x = ptr + 1; x < (int) f.size(); x++)
            {
                cur_sum += f[x].first.first * (val - f[x].second.first + f[i].second.first);
            }
            */
            ans += f[i].first.first * suf_sm + f[i].first.second * suf_ct + f[i].first.first * cur_sum;
        }
        for (auto v : f)
        {
            for (int ind = 0; ind < (int) edges.size(); ind++)
            {
                auto d = edges[ind];
                if (c <= d) continue;
                int a = d.first, b = d.second;
                ans += v.first.first * s_b[ind] + v.first.second * s_a[ind];
                int d_a = min(v.second.first + len[{i, a}], v.second.second + len[{j, a}]);
                int d_b = min(v.second.first + len[{i, b}], v.second.second + len[{j, b}]);
                int op = (int) ret[{a, b}].size() + 1;
                //x + a < (op - x) + b
                //x + a < op - x + b
                //2x + a < op + b
                //2x < op + b - a
                int x = (op + d_b - d_a) / 2 - 1;
                x = max(x, -1);
                x = min(x, (int) ret[{a, b}].size() - 1);
                ll kek = (x >= 0 ? t_ab[{a, b}][x] + t_a[{a, b}][x] * d_a : 0);
                /*
                for (int ind = 0; ind <= x; ind++)
                {
                    auto to = ret[{a, b}][ind];
                    kek += to.first.first * (to.second.first + d_a);
                }
                */
                if (x != (int) ret[{a, b}].size() - 1)
                {
                    kek += t_a[{a, b}].back() * d_b;
                    if (x >= 0) kek -= t_a[{a, b}][x] * d_b;
                    kek += t_sos[{a, b}][x + 1];
                }
                /*
                for (int ind = x + 1; ind < (int) ret[{a, b}].size(); ind++)
                {
                    auto to = ret[{a, b}][ind];
                    kek += to.first.first * (to.second.second + d_b);
                }
                */
                ans += v.first.first * kek;
            }
            for (int go : verts)
            {
                int ok = min(v.second.first + len[{i, go}], v.second.second + len[{j, go}]);
                ans += v.first.first * cnt[go] * ok + v.first.first * sum[go] + v.first.second * cnt[go];
            }
        }
    }
    for (int x : verts)
    {
        for (int y : verts)
        {
            if (x < y)
            {
                ans += len[{x, y}] * cnt[x] * cnt[y] + sum[x] * cnt[y] + cnt[x] * sum[y];
            }
        }
    }
    return ans;
}

ll stup(int n, int m, vector <pair <int, int> > e)
{
    for (int i = 0; i < n; i++)
    {
        g[i].clear();
        deg[i] = 0;
    }
    for (auto c : e)
    {
        int a = c.first, b = c.second;
        a--, b--;
        deg[a]++, deg[b]++;
        g[a].insert(b);
        g[b].insert(a);
    }
    vector <int> verts;
    for (int i = 0; i < n; i++)
    {
        verts.push_back(i);
    }
    int sz = (int) verts.size();
    vector <vector <int> > dist(sz, vector <int> (sz, inf));
    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < sz; j++)
        {
            if (i == j)
            {
                dist[i][j] = 0;
            }
            if (g[verts[i]].count(verts[j]))
            {
                dist[i][j] = 1;
            }
        }
    }
    for (int k = 0; k < sz; k++)
    {
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < sz; i++) for (int j = 0; j < sz; j++)
    {
        ans += dist[i][j];
    }
    return ans / 2;
}

vector <pair <int, int> > gen(int n, int m)
{
    vector <pair <int, int> > e;
    set <pair <int, int> > q;
    for (int i = 1; i < n; i++)
    {
        e.push_back({rnd() % i, i});
        q.insert(e.back());
    }
    vector <pair <int, int> > musorka;
    m -= (n - 1);
    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) if (!q.count({i, j})) musorka.push_back({i, j});
    shuffle(musorka.begin(), musorka.end(), rnd);
    musorka.resize(m);
    for (auto c : musorka)
    {
        e.push_back(c);
    }
    for (auto &c : e) c.first++, c.second++;
    return e;
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONPC
    int n, m;
    cin >> n >> m;
    vector <pair <int, int> > e;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        e.push_back({a, b});
    }
    cout << smart(n, m, e) << '\n';
    return 0;
#else
    int test_cnt = 0;
    while (true)
    {
        int n = rnd() % 10 + 2;
        int all = n * (n - 1) / 2;
        all -= (n - 1);
        int m = (n - 1) + rnd() % (all + 1);
        vector <pair <int, int> > e = gen(n, m);
        if (smart(n, m, e) != stup(n, m, e))
        {
            cout << "WA" << test_cnt << endl;
            cout << n << ' ' << m << '\n';
            for (auto c : e)
            {
                cout << c.first << ' ' << c.second << '\n';
            }
            return 0;
        }
        else
        {
            if (test_cnt % 100 == 0)
                cout << "OK" << test_cnt << endl;
        }
        test_cnt++;
    }
#endif
}