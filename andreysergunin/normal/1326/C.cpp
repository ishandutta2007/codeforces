#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>

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

const int P = 998244353;

void mul(int &a, int b) {
    a = ll(a) * b % P;
}

void solve() {   
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    vector<int> good(n);
    ll sum = 0;
    int res = 1;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
        if (p[i] >= n - k) {
            good[i] = 1;
            sum += p[i] + 1;
        }
    }

    int prev = -1;
    for (int i = 0; i < n; ++i) {
        if (good[i]) {
            if (prev != -1) {
                mul(res, i - prev);
            }
            prev = i;
        }
    }

    cout << sum << " " << res << "\n";

}