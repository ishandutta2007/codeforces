#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = double;
using pii = pair<int, int>;
using uint = unsigned int;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    freopen("input.txt", "r2", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;  

    int tests = 1;
    cin >> tests;

    while (tests--) {
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// ----------------------------------------------------------------- 

void solve() { 
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    map<int, int> cnt;
    
    map<int, int> id;
    int last = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
        if (!id.count(a[i])) {
            id[a[i]] = last++;
        }
    }

    vector<vector<int>> g(last);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        g[id[x]].push_back(id[y]);
        g[id[y]].push_back(id[x]);
    }

    for (auto &to : g) {
        sort(all(to), greater<int>());
    }

    set<int> used_len;
    vector<vector<pii>> arr(n + 1);
    for (auto [x, len] : cnt) {
        used_len.insert(len);
        arr[len].emplace_back(x, id[x]);
    }

    for (int i = 1; i <= n; ++i) {
        sort(all(arr[i]), greater<pii>());
    }

    ll res = 0;
    vector<int> used(last);
    for (auto [x, len_x] : cnt) {
        for (int i : g[id[x]]) {
            used[i] = x;
        }
        used[id[x]] = x;
        for (int len_y : used_len) {
            int y = -1;
            for (int i = 0; i < sz(arr[len_y]); ++i) {
                if (used[arr[len_y][i].second] != x) {
                    y = arr[len_y][i].first;
                    break;
                }
            }
            if (y != -1) {
                res = max(res, ll(x + y) * (len_x + len_y));
            }
        }
    }
    cout << res << endl;
}