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
const int K = 20;

vector <int> g[N];
int st[N][K];
int tin[N], tout[N];
int h[N];
int tt = 0;

void dfs(int v, int pr)
{
    tin[v] = tt++;
    st[v][0] = pr;
    for (int i = 1; i < K; i++) st[v][i] = st[st[v][i - 1]][i - 1];
    for (int to : g[v])
    {
        if (to != pr)
        {
            h[to] = h[v] + 1;
            dfs(to, v);
        }
    }
    tout[v] = tt++;
}

bool par(int a, int b)
{
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b)
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

int arr[N];
pair <int, int> t[4 * N];

void upd(int v, int l, int r, int i, int x)
{
    if (r - l == 1)
    {
        t[v] = {x, i};
    }
    else
    {
        int m = (l + r) / 2;
        if (i < m)
        {
            upd(v * 2 + 1, l, m, i, x);
        }
        else
        {
            upd(v * 2 + 2, m, r, i, x);
        }
        t[v] = min(t[v * 2 + 1], t[v * 2 + 2]);
    }
}

pair <int, int> get(int v, int l, int r, int tl, int tr)
{
    if (tl >= r || tr <= l)
    {
        return {1e9, -1};
    }
    if (tl >= l && tr <= r)
    {
        return t[v];
    }
    else
    {
        int tm = (tl + tr) / 2;
        return min(get(v * 2 + 1, l, r, tl, tm), get(v * 2 + 2, l, r, tm, tr));
    }
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        int p;
        cin >> p;
        p--;
        g[p].push_back(i);
    }
    dfs(0, 0);
    for (int i = 0; i + 1 < n; i++)
    {
        arr[i] = h[lca(i, i + 1)];
        upd(0, 0, n - 1, i, arr[i]);
    }
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (l == r - 1)
        {
            if (h[l] > h[r])
            {
                cout << r + 1 << ' ' << h[l] << '\n';
            }
            else
            {
                cout << l + 1 << ' ' << h[r] << '\n';
            }
        }
        else
        {
            int ind = get(0, l, r, 0, n - 1).second;
            int ret = -1;
            int pep = 0;
            for (int who = max(l, ind - 1); who <= min(r, ind + 1); who++)
            {
                int ans = 1e9;
                if (l < who - 1)
                {
                    ans = min(ans, get(0, l, who - 1, 0, n - 1).first);
                }
                if (who + 1 < r)
                {
                    ans = min(ans, get(0, who + 1, r, 0, n - 1).first);
                }
                if (who - 1 >= l && who + 1 <= r)
                {
                    ans = min(ans, h[lca(who - 1, who + 1)]);
                }
                if (ans > ret)
                {
                    ret = ans;
                    pep = who;
                }
            }
            cout << pep + 1 << ' ' << ret << '\n';
        }
    }
}