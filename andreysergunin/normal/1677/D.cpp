#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
using namespace std;
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
 
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using uint = unsigned int;
using ull = unsigned long long;
 
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
 
void solve();
 
int task;
 
int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
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

const int P = 998244353;

void mul(int &a, int b) {
    a = ll(a) * b % P;
}

void solve() {  
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = n - k; i < n; ++i) {
        if (a[i] > 0) {
            cout << 0 << endl;
            return;
        }
    }
    rotate(a.begin(), a.begin() + n - k, a.end());
    for (int i = 0; i < k; ++i) {
        a[i] = -1;
    }
    for (int i = k; i < n; ++i) {
        if (a[i] == 0) {
            a[i] = -2;
        } else if (a[i] > 0) {
            a[i] += k;
        }
    }

    int res = 1;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] > i) {
            cout << 0 << endl;
            return;
        } else if (a[i] >= 0) {
            
        } else if (a[i] == -1) {
            mul(res, i + 1);
        } else if (a[i] == -2) {
            mul(res, min(i + 1, k + 1));
        }
    }
    cout << res << endl;

}