#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = double;
using pii = pair<int, int>;
using uint = unsigned int;

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
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;  

    int tests = 1;
    cin >> tests;

    while (tests--) {
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// -----------------------------------------------------------------------

void solve() {
    string s;
    cin >> s;
    int n = sz(s);

    if (s == "0") {
        cout << "red" << endl;
        return;
    }

    bool zero = false;
    int r = 0;
    int even = 0;

    for (int i = 0; i < n; ++i) {
        int d = s[i] - '0';
        r += d;
        zero |= d == 0;
        even += d % 2 == 0;
    }

    if (r % 3 == 0 && zero && even >= 2) {
        cout << "red" << endl; 
    } else {
        cout << "cyan" << endl;
    }

}