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
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;

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
    vector<int> b(n);
    for (int &x : a) {
        cin >> x;
    }
    for (int &x : b) {
        cin >> x;
    }

    sort(all(a), greater());
    sort(all(b), greater());
    vector<int> pa(n + 1), pb(n + 1);
    for (int i = 0; i < n; ++i) {
        pa[i + 1] = pa[i] + a[i];
        pb[i + 1] = pb[i] + b[i];
    }

    auto get = [&](int m) {
        int k = n + m;
        k -= k / 4;
        int sa = pa[k - min(m, k)] + min(m, k) * 100;
        int sb = pb[min(k, n)];
        return sa >= sb;
    };

    int l = -1, r = n;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (get(m)) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << r << endl;  
}