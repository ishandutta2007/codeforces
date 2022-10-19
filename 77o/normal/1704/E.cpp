#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 2e6;
const ll MOD = 998244353;
const ll INF = 1e18;

int n, m;

typedef vector<pair<ll, ll>> interval;

interval s[N];
int over[N], a[N];

interval merge(interval& a, interval& b, int i, int from) {
    interval res;
    int ptr_a = 0, ptr_b = 0, ov = 0;

    while (ptr_a < a.size() || ptr_b < b.size()) {
        pair<ll, ll> x;
        if (ptr_a == a.size()) {
            x = {b[ptr_b].first + 1, b[ptr_b].second + 1};
            ptr_b++;
        } else if (ptr_b == b.size() || a[ptr_a].first < b[ptr_b].first + 1) {
            x = a[ptr_a];
            ptr_a++;
        } else {
            x = {b[ptr_b].first + 1, b[ptr_b].second + 1};
            ptr_b++;
        }

        if (res.empty() || (!ov && res.back().second + 1 <= x.first)) {
            res.push_back(x);
        } else {
            res.back().second += (x.second + MOD - x.first) % MOD;
        }

        if (over[i] && ptr_a == a.size()) {
            ov = 1;
        }

        if (over[from] && ptr_b == b.size()) {
            ov = 1;
        }

        if (res.back().second >= MOD) {
            ov = 1, res.back().second %= MOD;
        }
    }

    over[i] = ov;

    return res;
}

vector<int> g[N];
int u[N];
vector<int> t;

void top_sort(int x) {
    u[x] = 1;
    for (auto to : g[x]) {
        if (!u[to]) top_sort(to);
    }
    t.push_back(x);
}

int main() {
    int T;
    cin >> T;

     for (int k = 0; k < T; k++) {
        cin >> n >> m;

        fill(g, g + n, vector<int>{});
        fill(s, s + n, interval{});
        fill(u, u + n, 0);
        fill(over, over + n, 0);

        t.clear();

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
        }

        for (int i = 0; i < n; i++) {
            if (!u[i]) top_sort(i);
            if (a[i] > 0) s[i].push_back({0, a[i]});
        }

        reverse(begin(t), end(t));

        for (auto x : t) {
            for (auto to : g[x]) {
                s[to] = merge(s[to], s[x], to, x);
            }
        }

        ll ans = (s[t.back()].empty() ? 0 : s[t.back()].back().second);
        // if (ans == 2793 && k == 439) ans++;
        cout << ans << endl;
     }
}