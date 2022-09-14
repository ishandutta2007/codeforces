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

int ask(int pos) {
    cout << "? " << pos + 1 << endl;
    int x;
    cin >> x;
    --x;
    return x;
}

void solve() {
    int n;
    cin >> n;
    set<int> used;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        if (used.contains(i)) {
            continue;
        }

        vector<int> arr;

        arr.push_back(ask(i));
        int x = 0;
        while ((x = ask(i)) != arr[0]) {
            arr.push_back(x);
        }

        for (int x : arr) {
            used.insert(x);
        }

        for (int j = 0; j < sz(arr); ++j) {
            p[arr[j]] = arr[(j + 1) % sz(arr)];
        }
    }

    cout << "! ";
    for (int x : p) {
         cout << x + 1 << " ";
    }
    cout << endl;


}