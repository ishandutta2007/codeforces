#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")

#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = double;
using pii = pair<int, int>;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(16) << fixed;
    cerr << setprecision(16) << fixed;

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
    vector<int> p(n);
    vector<int> q(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
        q[p[i]] = i;
    }
    int k = 0;


    while (k < n) {
        int pos = q[k];
        int m = n - k;
        while (pos < m) {
            if (p[pos] != k) {
                cout << "No\n";
                return; 
            }
            ++pos;
            ++k;
        }
    }

    cout << "Yes\n";
}