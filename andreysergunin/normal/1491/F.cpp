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

int ask(const vector<int> &a, const vector<int> &b) {
    cout << "? " << sz(a) << " " << sz(b) << endl;
    for (int x : a) {
        cout << x + 1 << " ";
    }
    cout << endl;
    for (int x : b) {
        cout << x + 1 << " ";
    }
    cout << endl;

    int x;
    cin >> x;
    return x;
}

void solve() {  
    int n;
    cin >> n;

    vector<int> bad(n);
    vector<int> a = {0};

    int k = 1;
    for (; k < n; ++k) {
        int x = ask(a, {k});
        if (x != 0) {
            bad[k] = true;
            break;
        }
        a.push_back(k);
    }

    int lf = 0, rg = k;

    while (rg - lf > 1) {
        int mid = (lf + rg) / 2;
        vector<int> a(mid - lf);
        iota(all(a), lf);
        if (ask(a, {k})) {
            rg = mid;
        } else {
            lf = mid;
        }
    }

    bad[lf] = true;

    for (int i = k + 1; i < n; ++i) {
        if (ask({k}, {i})) {
            bad[i] = 1;
        }
    }

    vector<int> res;
    for (int i = 0; i < n; ++i) {
        if (!bad[i]) {
            res.push_back(i);
        }
    }

    cout << "! " << sz(res) << " ";
    for (int x : res) {
        cout << x + 1 << " ";
    }
    cout << endl;

}