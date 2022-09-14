// #pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")

#include <bits/stdc++.h>
// #include <iostream>
// #include <cstdio>
// #include <iomanip>
// #include <random>

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
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(14) << fixed;
    cerr << setprecision(14) << fixed;

    int tests = 1;
    // cin >> tests;

    while (tests--) {
       solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// ----------------------------------------------------------------- 

const int MAXN = 81;
const int OPS = 10000;
const int INF = 2e9;

int d[MAXN][MAXN];
vector<int> p[2];
int dst[2][MAXN];
int part[MAXN];

void solve() {  
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> d[i][j];
            // d[i][j] = rnd() % int(1e8);
        }
    }

    int res = INF;
    
    for (int op = 0; op < OPS; ++op) {
        p[0].clear();
        p[1].clear();

        p[0].push_back(0);
        for (int i = 1; i < n; ++i) {
            int x = rnd() & 1;
            p[x].push_back(i);
            part[i] = x;
        }

        for (int i = 0; i < n; ++i) {
            dst[0][i] = INF;
        }
        dst[0][0] = 0;

        for (int it = 0; it < k; ++it) {
            int u = it & 1;
            int v = u ^ 1;

            for (int i = 0; i < n; ++i) {
                dst[v][i] = INF;
            }

            for (int i = 0; i < n; ++i) {
                for (int j : p[part[i] ^ 1]) {
                    dst[v][j] = min(dst[v][j], dst[u][i] + d[i][j]);
                }
            }
        }

        res = min(res, dst[0][0]);
    }

    cout << res << endl;
}