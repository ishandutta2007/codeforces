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
    cout << setprecision(16) << fixed;
    cerr << setprecision(16) << fixed;
 
    int tests = 1;
    // cin >> tests;
 
    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";
        solve();
    }
 
#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}
 
// ----------------------------------------------------------------- 

int n;
vector<int> a;

int ask(vector<int> &arr) {
    int k = sz(arr);
    cout << k << " ";
    for (int x : arr) {
        cout << x + 1 << " ";
        a[x] = 1;
    }
    cout << endl;

    int p;
    cin >> p;
    --p;

    for (int i = 0; i < k; ++i) {
        a[(p + i) % n] = 0;
    }

    return p;
}

void solve() {
    cin >> n;
    a.resize(n);


    auto f = [&](int l) {
        return n - (n + l - 1) / l - (l - 1);
    };

    int len = 1;
    for (int l = 1; l <= n; ++l) {
        if (f(len) < f(l)) {
            len = l;
        }
    }

    vector<int> b(n, 1);
    for (int i = 0; i < n; ++i) {
        if (i % len == 0) {
            b[i] = 0;
        }
    }

    int opt = f(len);

    while (true) {
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            cur += a[i];
        }
        if (cur == opt) {
            cout << 0 << endl;
            // for (int i = 0; i < n; ++i) {
            //     cerr << a[i];
            // }
            // cerr << endl;

            return;
        }

        vector<int> arr;
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                arr.push_back(i);
            }
        }

        if (sz(arr) >= len) {
            arr.resize(len);
        }

        ask(arr);
    }

}