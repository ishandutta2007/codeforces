#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = double; 
// using ld = __float128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
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
    cout << setprecision(8) << fixed;
    cerr << setprecision(8) << fixed;

    int tests = 1;
    cin >> tests;

    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// ----------------------------------------------------------------- 

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> arr(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        arr[a[i]].push_back(i);
    }

    string s(n, '0');

    int l = 0, r = n;


    for (int k = 1; k <= n; ++k) {
        if (sz(arr[k]) > 1) {
            s[n - k] = '1';
            break;
        } else if (sz(arr[k]) == 0) {
            break;
        }
        s[n - k] = '1';
        int pos = arr[k][0];
        if (pos == l) {
            ++l;
        } else if (pos == r - 1) {
            --r;
        } else {
            break;
        }
    }

    bool ok = true;
    for (int i = 1; i <= n; ++i) {
        ok &= sz(arr[i]) == 1;
    }
    if (ok) {
        s[0] = '1';
    }

    cout << s << "\n";

}