#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
// using ld = long double; 
using ld = __float128;
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
    cout << setprecision(6) << fixed;
    cerr << setprecision(6) << fixed;

    int tests = 1;
    cin >> tests;

    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";s
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// ----------------------------------------------------------------- 

void solve() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }   


    set<pii> setik;
    vector<int> h(m);
    for (int i = 0; i < m; ++i) {
        setik.insert({h[i], i});
    }   

    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
        auto it = setik.begin();
        int k = it->second;
        setik.erase(it);

        res[i] = k + 1;
        h[k] += a[i];
        setik.insert({h[k], k});
    }


    cout << "YES" << endl;
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;
}