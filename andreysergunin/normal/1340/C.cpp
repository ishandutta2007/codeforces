#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")

#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = double;
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

const int MAXN = 10101;
const int MAXM = 1010;

vector<int> buf[MAXM];
bool used[MAXN][MAXM];

void solve() {
    int n, m;
    cin >> n >> m;
    // n = 1000000;
    // m = 10001;

    vector<int> d(m);
    for (int i = 0; i < m; ++i) {
        cin >> d[i];
        // d[i] = (i == 0 ? 0 : (i == m - 1 ? n : rnd() % n));
        // d[i] = n / (m - 1) * i;
    }
    int g, r;
    cin >> g >> r;
    // g = 1000, r = 100;

    sort(all(d));

    used[0][0] = 1;
    buf[0].push_back(0);

    int empty = 0;
    for (int i = 0; empty < g; ++i) {
        int rem = i % g;
        vector<int> cur = buf[rem];
        if (cur.empty()) {
            ++empty;
            continue;
        }
        empty = 0;
        buf[rem].clear();

        for (int v : cur) {
            if (v == m - 1) {
                cout << i + ((i - 1) / g) * r << "\n";
                return;
            }
            if (v != 0) {
                int delta = d[v] - d[v - 1];
                int t = (rem + delta == g ? 0 : rem + delta);
                if (delta <= g - rem && !used[v - 1][t]) {
                    used[v - 1][t] = 1;
                    buf[t].push_back(v - 1);
                }
            }
            if (v != m - 1) {
                int delta = d[v + 1] - d[v];
                int t = (rem + delta == g ? 0 : rem + delta);
                if (delta <= g - rem && !used[v + 1][t]) {
                    used[v + 1][t] = 1;
                    buf[t].push_back(v + 1);
                }
            }
        }
    }

    cout << "-1\n";
}