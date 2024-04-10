#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")

#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(16) << fixed;
    cerr << setprecision(16) << fixed;

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

const int MAXN = 300300;

void solve() {
    vector<pair<ll, int>> p;
    vector<int> n(3);

    cin >> n[0] >> n[1] >> n[2];

    for (int k = 0; k < 3; ++k) {
        for (int i = 0; i < n[k]; ++i) {
            int val;
            cin >> val;
            p.push_back({val, k});
        }
    }
    sort(all(p));

    int m = sz(p);

    vector<vector<int>> nxt(m, vector<int>(3));
    vector<int> val(3, m);

    for (int i = m - 1; i >= 0; --i) {
        val[p[i].second] = i;
        nxt[i] = val;
    }

    ll res = 4e18;

    auto sqr = [](ll x) {
        return x * x;
    };
    auto f = [&](ll x, ll y, ll z) {
        return sqr(x - y) + sqr(y - z) + sqr(z - x);
    };

    val.assign(3, -1);
    for (int i = 0; i < m; ++i) {
        int c = p[i].second;
        val[c] = i;

        for (int j = 1; j <= 2; ++j) {
            int c1 = (c + j) % 3;
            int c2 = (c + 3 - j) % 3;
            if (val[c1] == -1 || nxt[i][c2] == m) {
                continue;
            }
            res = min(res, f(p[val[c1]].first, p[i].first, p[nxt[i][c2]].first));
        }
    }

    cout << res << endl;
}