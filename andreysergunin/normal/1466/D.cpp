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
    cout << setprecision(10) << fixed;
    cerr << setprecision(10) << fixed;

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
    vector<int> w(n);

    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        sum += w[i];
    }

    vector<int> deg(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        ++deg[u];
        ++deg[v];
    }

    vector<int> arr;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < deg[i] - 1; ++j) {
            arr.push_back(w[i]);
        }
    }
    sort(all(arr), greater<int>());

    ll res = sum;
    cout << res << " ";
    for (int i = 0; i < n - 2; ++i) {
        res += arr[i];
        cout << res << " ";
    }
    cout << "\n";

    
}