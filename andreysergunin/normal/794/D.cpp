#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <complex>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
mt19937 rr(random_device{}());

struct City {
    int id;
    vector<int> to;
    void push_back(int x) {
        to.push_back(x);
    }
    int &operator [] (int k) {
        return to[k];
    }
};

bool operator < (const City &a, const City &b) {
    return a.to < b.to;
}

vector<vector<int>> g, h;

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<City> c(n);
    h.resize(n);

    vector<pair<int, int>> e;
    vector<int> d(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        c[u].push_back(v);
        c[v].push_back(u);
        e.push_back({u, v});
        e.push_back({v, u});
        ++d[u];
        ++d[v];
    }
    for (int i = 0; i < n; ++i) {
        c[i].push_back(i);
        c[i].id = i;
    }
    for (int i = 0; i < n; ++i) {
        sort(all(c[i].to));
    }
    sort(all(c));

    vector<int> type(n);

    for (int i = 1; i < n; ++i) {
        type[c[i].id] = type[c[i - 1].id];
        if (c[i].to != c[i - 1].to) {
            ++type[c[i].id];
        }
    }

    int k = type[c[n - 1].id] + 1;

    g.resize(k);

    for (int i = 0; i < sz(e); ++i) {
        if (type[e[i].first] != type[e[i].second])
            g[type[e[i].first]].push_back(type[e[i].second]);
    }

    for (int i = 0; i < k; ++i) {
        sort(all(g[i]));
        g[i].resize(unique(all(g[i])) - g[i].begin());
    }

    // for (int i = 0; i < k; ++i) {
    //     for (int u : g[i])
    //         cout << u << " ";
    //     cout << endl;
    // }

    // for (int i = 0; i < n; ++i)
    //     cout << type[i] << " ";
    // cout << endl;

    int st = -1;
    for (int i = 0; i < k; ++i) {
        if (sz(g[i]) > 2) {
            cout << "NO" << endl;
            return 0;
        }
        if (sz(g[i]) <= 1) {
            st = i;
        }
    }
    if (st == -1) {
        cout << "NO" << endl;
        return 0;
    }

    vector<int> col(k);

    int cur = st;
    int cl = 0;
    for (int i = 0; i < k; ++i) {
        // cout << cur << endl;
        col[cur] = ++cl;
        int nxt = 0;
        for (int u : g[cur]) {
            if (!col[u])
                nxt = u;
        }
        cur = nxt;
    }

    // for (int i = 0; i < k; ++i)
    //     cout << col[i] << " ";
    // cout << endl;

    // for (int i = 0; i < n; ++i)
    //     cout << col[type[i]] << " ";
    // cout << endl;

    vector<int> s(k + 1);
    for (int i = 0; i < n; ++i) {
        ++s[col[type[i]]];
    }

    // for (int i = 1; i <= k; ++i)
    //     cout << s[i] << " ";
    // cout << endl;

    for (int i = 0; i < n; ++i) {
        int t = col[type[i]];
        int x = d[i];
        int y = s[t] - 1;
        if (t > 1)
            y += s[t - 1];
        if (t < k)
            y += s[t + 1];
        // cout << i << " " << x << " " << y << endl;
        if (x != y) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
        cout << col[type[i]] << " ";
    }
    cout << endl;

}