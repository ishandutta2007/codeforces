#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double; 
// using ld = __float128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); 
#endif 

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(10) << fixed;
    cerr << setprecision(10) << fixed;

    int tests = 1;
    // cin >> tests;

    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// ----------------------------------------------------------------- 

const int MAXN = 1515;

int a[MAXN][MAXN];

vector<int> b[MAXN][MAXN], c[MAXN][MAXN];
    
void solve() {  
    int n, lim;
    cin >> n >> lim;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j >= 0; --j) {
            b[i][j].push_back(j);
            if (j != n - 1) {
                for (int x : b[i][j + 1]) {
                    if (a[i][x] != a[i][j]) {
                        b[i][j].push_back(x);
                    }
                    if (sz(b[i][j]) > lim + 1) {
                        b[i][j].pop_back();
                    }
                }
            }
        }
    }

    for (int j = 0; j < n; ++j) {
        for (int i = n - 1; i >= 0; --i) {
            if (i != n - 1) {
                c[i][j].push_back(i + 1);
                for (int x : c[i + 1][j]) {
                    if (a[x][j] != a[i + 1][j]) {
                        c[i][j].push_back(x);
                    }
                    if (sz(c[i][j]) > lim + 1) {
                        c[i][j].pop_back();
                    }
                }
            }
        }
    }

    auto cmp = [&](const pii &p, const pii &q) {
        return max(p.first, p.second) < max(q.first, q.second);
    };

    vector<int> pref(n + 1);

    int it = 0;
    vector<int> used(n * n + 1);

    for (int d = -(n - 1); d <= (n - 1); ++d) {
        vector<pii> p;
        vector<pii> q;
        vector<pii> r;

        vector<pii> u;

        for (int s = 2 * n - 2; s >= 0; --s) {
            ++it;
            if ((s + d) & 1) {
                continue;
            }

            int x = (s + d) / 2;
            int y = (s - d) / 2;
            if (x < 0 || y < 0 || x >= n || y >= n) {
                continue;
            }

            for (auto &[f, g] : p) {
                ++f; ++g;
            }
            q.clear();
            r.clear();

            for (int j : b[x][y]) {
                q.push_back({0, j - y});
            }

            for (int i : c[x][y]) {
                r.push_back({i - x, 0});
            }

            u.resize(sz(p) + sz(q));
            merge(all(p), all(q), u.begin(), cmp);

            p.resize(sz(u) + sz(r));
            merge(all(u), all(r), p.begin(), cmp);

            int k = 0;
            for (int i = 0; i < sz(p); ++i) {
                auto [dx, dy] = p[i];
                if (used[a[x + dx][y + dy]] != it) {
                    used[a[x + dx][y + dy]] = it;
                    p[k++] = p[i];
                }
            }
            p.resize(k);

            if (sz(p) > lim) {
                p.resize(lim + 1);
                int d = min(n - x, n - y);
                d = min(d, max(p[lim].first, p[lim].second));
                // cerr << x << " " << y << " " << d << endl;
                ++pref[d];
            } else {
                int d = min(n - x, n - y);
                ++pref[d];
            }
        }
    } 

    for (int i = n; i >= 1; --i) {
        pref[i - 1] += pref[i];
    }

    for (int i = 1; i <= n; ++i) {
        cout << pref[i] << "\n";
    }
}