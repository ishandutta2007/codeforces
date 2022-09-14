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
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;  

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


void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> used(2, vector<int>(n));
    int cnt = 0;

    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        --r; --c;
        for (int j = max(c - 1, 0); j <= min(c + 1, n - 1); ++j) {
            cnt -= used[r][c] & used[r ^ 1][j];
        }
        used[r][c] ^= 1;
        for (int j = max(c - 1, 0); j <= min(c + 1, n - 1); ++j) {
            cnt += used[r][c] & used[r ^ 1][j];
        }

        cout << (cnt == 0 ? "Yes\n" : "No\n");        
    }
}