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
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); 
#endif 

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(9) << fixed;
    cerr << setprecision(9) << fixed;

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
    int s = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s += a[i];
    }
    if (s & 1) {
        cout << "NO" << endl;
        return;
    }

    int start = -1;
    s = 0;
    for (int i = 0; i < n; ++i) {
        s += a[i];
        if (a[i] == 0 && s % 2 == 0) {
            start = i;
            break;
        }
    }

    vector<int> arr;

    auto update = [&](int i) {
        int x = a[i] ^ a[i + 1] ^ a[i + 2];
        // cout << x << " " << a[i] << " " << a[i + 1] << " " << a[i + 2] << endl;
        if (a[i] != x || a[i + 1] != x || a[i + 2] != x) {
            arr.push_back(i);
        }
        a[i] = a[i + 1] = a[i + 2] = x;
        return x;
    };

    if (start == -1) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i]) {
                if (cnt > 0 && (cnt & 1)) {
                    int k = i;
                    for (; a[k - 2] == 0; k -= 2) {
                        update(k - 2);
                    }
                    update(k - 2);
                    start = k - 1;
                }
                cnt = 0;
            } else {
                ++cnt;
            }
        }

        if (start == -1) {
            cout << "NO" << endl;
            return;
        }

    }

    cout << "YES" << endl;

    for (int i = start; i + 2 < n; ++i) {
        if (a[i + 1] == 0) {
            continue;
        }
        if (a[i] ^ a[i + 1] ^ a[i + 2] == 0) {
            update(i);
            assert(!a[i] & !a[i + 1]);
        } else {
            assert(i + 3 < n);
            update(i + 1);
            update(i);
            assert(!a[i] && !a[i + 1]);
        }
    }

    for (int i = start; i >= 2; --i) {
        if (a[i - 1] == 0) {
            continue;
        }

        if (a[i] ^ a[i - 1] ^ a[i - 2] == 0) {
            update(i - 2);
            assert(!a[i] & !a[i - 1]);
        } else {
            assert(i >= 3);
            update(i - 3);
            update(i - 2);
            assert(!a[i] && !a[i - 1]);
        }
    }

    assert(sz(arr) <= n);

    for (int i = 0; i < n; ++i) {
        assert(a[i] == 0);
    }

    cout << sz(arr) << endl;
    for (int x : arr) {
        cout << x + 1 << " ";
    }
    cout << endl;

}