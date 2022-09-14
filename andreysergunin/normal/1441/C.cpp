#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double; 
// using ld = __float128;
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
    cout << setprecision(15) << fixed;
    cerr << setprecision(15) << fixed;

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

const int MAXN = 3030;

ll pref[MAXN][MAXN];
ll suff[MAXN][MAXN];

void solve() { 
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        a[i].resize(m);
        for (int &x : a[i]) {
            cin >> x;
        }
    }

    for (int i = 0; i <= k; ++i) {
        pref[0][i] = -1;
    }
    pref[0][0] = 0;

    for (int i = 0; i < n; ++i) {
        ll sum = 0;
        for (int x : a[i]) {
            sum += x;
        }
        for(int j = 0; j <= k; ++j) {
            pref[i + 1][j] = pref[i][j];
        }
        for (int j = 0; j + sz(a[i]) <= k; ++j) {
            if (pref[i][j] == -1) {
                continue;
            }
            pref[i + 1][j + sz(a[i])] = max(pref[i + 1][j + sz(a[i])], pref[i][j] + sum);
        }
    }

    for (int i = 0; i <= k; ++i) {
        suff[n][i] = -1;
    }
    suff[n][0] = 0;

    for (int i = n - 1; i >= 0; --i) {
        ll sum = 0;
        for (int x : a[i]) {
            sum += x;
        }
        for(int j = 0; j <= k; ++j) {
            suff[i][j] = suff[i + 1][j];
        }
        for (int j = 0; j + sz(a[i]) <= k; ++j) {
            if (suff[i + 1][j] == -1) {
                continue;
            }
            suff[i][j + sz(a[i])] = max(suff[i][j + sz(a[i])], suff[i + 1][j] + sum);
        }
    }


    vector<vector<pair<ll, int>>> arr(k + 1);
    for (int i = 0; i < n; ++i) {
        ll sum = 0;
        for (int j = 0; j < sz(a[i]); ++j) {
            sum += a[i][j];
            if (j + 1 <= k) {
                arr[j + 1].push_back({sum, i});
            }
        }
    }

    ll res = pref[n][k];
    for (int i = 1; i <= k; ++i) {
        sort(all(arr[i]), greater());
        arr[i].resize(min(sz(arr[i]), k / i + 1));

        for (auto [s, p] : arr[i]) {
            for (int j = 0; j <= k - i; ++j) {
                if (pref[p][j] == -1 || suff[p + 1][k - i - j] == -1) {
                    continue;
                }
                res = max(res, pref[p][j] + suff[p + 1][k - i - j] + s);
            }
        }
    }

    cout << res << endl;

}