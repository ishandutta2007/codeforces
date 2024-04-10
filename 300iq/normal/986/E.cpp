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

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int N = 1e7 + 1;
const int MD = 1e9 + 7;

inline int add(int a, int b)
{
    a += b;
    if (a >= MD) a -= MD;
    if (a < 0) a += MD;
    return a;
}

inline int mul(int a, int b)
{
    return (a * (ll) b) % MD;
}

int lp[N];
int a[N];
vector <pair <int, int> > kek[N];
vector <pair <int, int> > quers[N];

const int M = 1e5 + 7;
const int K = 18;

int s[M], t[M], lca[M], ans[M];
vector <int> g[M];
int tin[M], tout[M];
int st[M][K];
int mem[M];
int nuok[M][2];

int tt = 0;

void zhfs(int v, int pr)
{
    if (v != 0)
        mem[v] = pr;
    else
        mem[v] = -1;
    tin[v] = tt++;
    st[v][0] = pr;
    for (int i = 1; i < K; i++)
    {
        st[v][i] = st[st[v][i - 1]][i - 1];
    }
    for (int to : g[v])
    {
        if (to != pr)
        {
            zhfs(to, v);
        }
    }
    tout[v] = tt;
}

bool par(int a, int b)
{
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int get_lca(int a, int b)
{
    if (par(a, b)) return a;
    for (int i = K - 1; i >= 0; i--)
    {
        if (!par(st[a][i], b))
        {
            a = st[a][i];
        }
    }
    return st[a][0];
}

int fenw[N][2];

void inc(int x, int y, int t)
{
    for (; x < N; x = (x | (x + 1)))
    {
        fenw[x][t] += y;
    }
}

int get(int x, int t)
{
    int ans = 0;
    for (; x >= 0; x = (x & (x + 1)) - 1)
    {
        ans += fenw[x][t];
    }
    return ans;
}

void add(int l, int r, int t, int x)
{
    inc(r, -x, t);
    inc(l, x, t);
}

inline int pw(int a, int n)
{
    int res = 1;
    while (n)
    {
        if (n % 2 == 0)
        {
            a = mul(a, a);
            n /= 2;
        }
        else
        {
            res = mul(res, a);
            n--;
        }
    }
    return res;
}

int get_sum(int a, int b, int c, int t)
{
    int ans = get(tin[a], t) + get(tin[b], t);
    if (mem[c] != -1)
    {
        ans -= 2 * get(tin[mem[c]], t);
    }
    ans -= nuok[c][t];
    return ans;
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 2; i < N; i++)
    {
        if (lp[i] == 0)
        {
            for (int j = i; j < N; j += i)
            {
                if (lp[j] == 0)
                {
                    lp[j] = i;
                }
            }
        }
    }
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        int x = a[i];
        while (x != 1)
        {
            int t = lp[x];
            int deg = 0;
            while (x % t == 0)
            {
                deg++;
                x /= t;
            }
            kek[t].push_back({i, deg});
        }
    }
    zhfs(0, 0);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int u, v, x;
        cin >> u >> v >> x;
        u--, v--;
        ans[i] = 1;
        while (x != 1)
        {
            int t = lp[x];
            int deg = 0;
            while (x % t == 0)
            {
                deg++;
                x /= t;
            }
            quers[t].push_back({i, deg});
        }
        s[i] = u, t[i] = v;
        lca[i] = get_lca(s[i], t[i]);
    }
    for (int i = 2; i < N; i++)
    {
        if (!quers[i].empty())
        {
            sort(kek[i].begin(), kek[i].end(), [] (pair <int, int> a, pair <int, int> b)
            {
                return a.second < b.second;
            });
            sort(quers[i].begin(), quers[i].end(), [] (pair <int, int> a, pair <int, int> b)
            {
                return a.second < b.second;
            });
            for (auto c : kek[i])
            {
                add(tin[c.first], tout[c.first], 0, 1);
                nuok[c.first][0]++;
            }
            int j = -1;
            for (auto d : quers[i])
            {
                while (j + 1 < (int) kek[i].size() && kek[i][j + 1].second <= d.second)
                {
                    j++;
                    nuok[kek[i][j].first][0]--;
                    nuok[kek[i][j].first][1] += kek[i][j].second;
                    add(tin[kek[i][j].first], tout[kek[i][j].first], 0, -1);
                    add(tin[kek[i][j].first], tout[kek[i][j].first], 1, kek[i][j].second);
                }
                int ind = d.first;
                int a = s[ind], b = t[ind], c = lca[ind];
                int sum = get_sum(a, b, c, 1) + get_sum(a, b, c, 0) * d.second;
                ans[ind] = mul(ans[ind], pw(i, sum));
            }
            for (auto c : kek[i])
            {
                nuok[c.first][0]--;
                add(tin[c.first], tout[c.first], 0, -1);
            }
            for (int x = 0; x <= j; x++)
            {
                nuok[kek[i][x].first][0]++;
                nuok[kek[i][x].first][1] -= kek[i][x].second;
                add(tin[kek[i][x].first], tout[kek[i][x].first], 0, 1);
                add(tin[kek[i][x].first], tout[kek[i][x].first], 1, -kek[i][x].second);
            }
        }
    }
    for (int i = 0; i < q; i++)
    {
        cout << ans[i] << '\n';
    }
}