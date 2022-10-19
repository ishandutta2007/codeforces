#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES\n": "NO\n")
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
using namespace std;

using namespace std;

void dfs_order(int u, int p, vector<vector<int>> const& g, vector<int> & order) {
    for (auto v : g[u]) {
        if (v != p) {
            dfs_order(v, u, g, order);
        }
    }
    order.push_back(u);
}

void get_order(map<pair<int, int>, vector<int>> const& in, int n, vector<int> & order) {
    vector<vector<int>> g(n);
    for (auto e : in) {
        auto vs = e.second;

        if (vs.size() == 2) {
            g[vs[0]].push_back(vs[1]);
            g[vs[1]].push_back(vs[0]);
        }
    }

    dfs_order(0, -1, g, order);
}

void dfs_polygon(int u, vector<vector<int>> const& g, vector<bool> & used, vector<int> & res) {
    if (used[u]) {
        return;
    }
    used[u] = true;
    res.push_back(u);
    for (auto e : g[u]) {
        dfs_polygon(e, g, used, res);
    }
}

void get_polygon(map<pair<int, int>, vector<int>> const& in, int n, vector<int> & polygon) {
    vector<vector<int>> g(n);
    for (auto e : in) {
        if (e.second.size() == 1) {
            auto edge = e.first;
            g[edge.first].push_back(edge.second);
            g[edge.second].push_back(edge.first);
        }
    }

    vector<bool> used(n);
    dfs_polygon(0, g, used, polygon);
}

void get_polygon(vector<vector<int>> const& in, int n, vector<int> const& order, vector<int> & polygon) {
    vector<pair<int, int>> listp(n, { -1, -1 });
    auto last = in[order.back()];
    for (int i = 0; i < 3; i++) {
        listp[last[i]] = { last[(i + 1) % 3], last[(i + 2) % 3] };
    }

    for (int i = (int)order.size() - 2; i >= 0; i--) {
        auto x = in[order[i]];

        int j = 0;
        while (listp[x[j]] != pair<int, int>{-1, -1}) {
            j++;
        }

        int x1 = x[j], x2 = x[(j + 1) % 3], x3 = x[(j + 2) % 3];
        if (listp[x2].second != x3) {
            swap(x2, x3);
        }

        listp[x1] = { x2, x3 };
        listp[x2].second = x1;
        listp[x3].first = x1;
    }

    polygon.push_back(0);

    int now = listp[0].second;
    while (now != 0) {
        polygon.push_back(now);
        now = listp[now].second;
    }
}

void out(vector<int> const& v) {
    for (auto e : v) {
        cout << e + 1 << ' ';
    }
    cout << endl;
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> in(n - 2, vector<int>(3));
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> in[i][j];
            in[i][j]--;
        }
        sort(in[i].begin(), in[i].end());
    }

    map<pair<int, int>, vector<int>> mp;
    for (int i = 0; i < n - 2; i++) {
        auto tri = in[i];
        for (int j = 0; j < 2; j++) {
            for (int k = j + 1; k < 3; k++) {
                mp[{tri[j], tri[k]}].push_back(i);
            }
        }
    }

    vector<int> order;
    get_order(mp, n, order);

    vector<int> polygon;
    get_polygon(in, n, order, polygon);
    // get_polygon(mp, n, polygon);  // another solution

    out(polygon);
    out(order);
}

int main() {
    int t;
    cin >> t;

    for (int t_num = 1; t_num <= t; t_num++) {
        solve();
    }

    return 0;
}