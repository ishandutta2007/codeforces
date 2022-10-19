#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define int ll
#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

const int INF = 1e18 + 228;

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    vector<vector<int>> pref(n + 1, vector<int> (n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pref[i + 1][j + 1] = pref[i][j + 1] + pref[i + 1][j] - pref[i][j] + arr[i][j];
        }
    }
    auto get = [&](int l1, int r1, int l2, int r2) {
        return pref[r1][r2] + pref[l1][l2] - pref[l1][r2] - pref[r1][l2];
    };
    vector<vector<int>> dp(n + 1, vector<int> (n + 1));
    for (int l = n - 1; l >= 0; l--) {
        for (int r = l + 1; r <= n; r++) {
            dp[l][r] = INF;
            for (int v = l; v < r; v++) {
                chkmin(dp[l][r], dp[l][v] + dp[v + 1][r] + get(l, v, 0, n) \
                    + get(v + 1, r, 0, n) - get(l, v, l, v) - get(v + 1, r, v + 1, r));
            }
        }
    }
    vector<int> p(n, -1);
    function<void(int,int,int)> solve;
    solve = [&](int l, int r, int pa) {
        if (l == r)
            return;
        for (int v = l; v < r; v++) {
            if (dp[l][r] == dp[l][v] + dp[v + 1][r] + get(l, v, 0, n) \
                    + get(v + 1, r, 0, n) - get(l, v, l, v) - get(v + 1, r, v + 1, r)) {
                p[v] = pa;
                solve(l, v, v);
                solve(v + 1, r, v);
                return;
            }
        }
    };
    solve(0, n, -1);
    for (int i = 0; i < n; i++) {
        cout << p[i] + 1 << " ";
    }
    cout << endl;
    return 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}