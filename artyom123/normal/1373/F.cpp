#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 1e9 + 1;

struct edge{
    int c, f, link, to;
    edge(){}
    edge(int _c, int _f, int _link, int _to) {
        c = _c;
        f = _f;
        link = _link;
        to = _to;
    }
};

int t;

vector<vector<edge>> g;
vector<int> usd;

int dfs(int v, int curf) {
    usd[v] = 1;
    if (v == t) {
        return curf;
    }
    for (auto &e : g[v]) {
        if (!usd[e.to] && e.f < e.c) {
            int delta = dfs(e.to, min(curf, e.c - e.f));
            if (delta != 0) {
                e.f += delta;
                g[e.to][e.link].f -= delta;
                return delta;
            }
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (auto &c : a) cin >> c;
        for (auto &c : b) cin >> c;
        int left = -1, right = min(b[0], a[0]) + 1;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            vector<int> lol = b;
            lol[0] -= mid;
            bool f = true;
            for (int i = 1; i < n - 1; i++) {
                int kek = min(a[i], lol[i - 1]);
                lol[i - 1] -= kek;
                if (lol[i] < a[i] - kek) {
                    f = false;
                    continue;
                }
                lol[i] -= (a[i] - kek);
            }
            if (f) left = mid;
            else right = mid;
        }
        if (left == -1) {
            cout << "NO\n";
            continue;
        }
        a[0] -= left;
        b[0] -= left;
        bool f = true;
        for (int i = 1; i < n - 1; i++) {
            int kek = min(a[i], b[i - 1]);
            b[i - 1] -= kek;
            if (b[i] < a[i] - kek) {
                f = false;
                continue;
            }
            b[i] -= (a[i] - kek);
        }
        a[n - 1] -= min(a[n - 1], b[n - 2]);
        if (b[n - 1] < a[0] + a[n - 1]) f = false;
        if (f) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}