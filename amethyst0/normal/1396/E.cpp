#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <limits.h>
#include <fstream>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
#define uint unsigned int
#define mp make_pair

const int maxn = (int)1e5 + 10;

vector <int> ed[maxn];
int sz[maxn];

void dfs(int v, int p) {
    sz[v] = 1;

    for (int u : ed[v]) {
        if (u != p) {
            dfs(u, v);
            sz[v] += sz[u];
        }
    }
}

int h[maxn];
vector <pair <pii, int> > g[maxn];
ll sum = 0;
set <int> vert[maxn];
int tt = -1;
int tin[maxn], tout[maxn];

void build(int v, int p, int pr, int hh) {
    tt++;
    tin[v] = tt;
    vert[pr].insert(v);
    sum += hh;
    h[v] = hh;
    sz[v] = 1;

    vector <int> a;

    for (int u : ed[v]) {
        if (u == p) {
            continue;
        }

        build(u, v, pr, hh + 1);
        sz[v] += sz[u];
        if (sz[u] & 1) {
            a.push_back(u);
        }
    }

    while ((int)a.size() >= 2) {
        int x = a.back();
        a.pop_back();
        int y = a.back();
        a.pop_back();
        g[pr].push_back(mp(mp(x, y), hh));
    }

    if (!a.empty()) {
        g[pr].push_back(mp(mp(a.back(), v), hh));
    }
    tout[v] = tt;
}

bool is_anc(int x, int y) {
    return tin[x] <= tin[y] && tout[y] <= tout[x];
}

int main() {
    int n;
    ll k;
    cin >> n >> k;

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x--;
        y--;
        ed[x].push_back(y);
        ed[y].push_back(x);
    }

    dfs(0, -1);

    int v = 0;

    while (true) {
        bool ok = true;

        for (int u : ed[v]) {
            if (sz[u] < sz[v] && 2 * sz[u] > n) {
                v = u;
                ok = false;
                break;
            }
        }

        if (ok) {
            break;
        }
    }

    for (int u : ed[v]) {
        build(u, v, u, 1);
        reverse(all(g[u]));
    }

    if (k > sum) {
        cout << "NO\n" << '\n';
        return 0;
    }

    set <pii> s;

    for (int u : ed[v]) {
        s.insert(mp(sz[u], u));
    }

    vector <pii> res;

    if ((k - sum) & 1) {
        cout << "NO\n" << '\n';
        return 0;
    }

    while (!s.empty() && sum != k) {
        int u = s.rbegin()->second;
        s.erase(*s.rbegin());
        if (sz[u] == 1) {
            cout << "NO\n" << '\n';
            return 0;
        }

        if (sum - 2 * g[u].back().second >= k) {
            sum -= 2 * g[u].back().second;
            sz[u] -= 2;
            s.insert(mp(sz[u], u));
            res.push_back(g[u].back().first);
            vert[u].erase(g[u].back().first.first);
            vert[u].erase(g[u].back().first.second);
            g[u].pop_back();
            continue;
        }

        int x = g[u].back().first.first;
        int y = -1;

        for (int z : vert[u]) {
            if (sum - 2 * h[z] == k && is_anc(z, x)) {
                y = z;
                break;
            }
        }

        assert(y != -1);
        res.push_back(mp(x, y));
        vert[u].erase(x);
        vert[u].erase(y);
        break;
    }

    cout << "YES\n";

    s.clear();

    for (int u : ed[v]) {
        if (vert[u].size()) {
            s.insert(mp(vert[u].size(), u));
        }
    }

    while ((int)s.size() > 1) {
        int x = s.rbegin()->second;
        s.erase(*s.rbegin());
        int y = s.rbegin()->second;
        s.erase(*s.rbegin());
        int a = *vert[x].begin();
        vert[x].erase(a);
        int b = *vert[y].begin();
        vert[y].erase(b);
        res.push_back(mp(a, b));
        if (vert[x].size()) {
            s.insert(mp(vert[x].size(), x));
        }

        if (vert[y].size()) {
            s.insert(mp(vert[y].size(), y));
        }
    }

    int x = s.begin()->second;
    assert((int)vert[x].size() == 1);
    res.push_back(mp(v, *vert[x].begin()));
    for (pii f : res) {
        printf("%d %d\n", f.first + 1, f.second + 1);
    }
}