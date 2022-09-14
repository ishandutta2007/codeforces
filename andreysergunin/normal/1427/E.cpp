#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = double; 
// using ld = __float128;
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
    cout << setprecision(6) << fixed;
    cerr << setprecision(6) << fixed;

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

void solve() {

    ll x;
    cin >> x;

    vector<array<ll, 3>> ops;

    auto norm = [&](ll x, ll y, bool flag = false) {
        if (flag) {
            for (int i = 0; i < 30; ++i) {
                ops.push_back({x << i, x << i, 0});
            }
        }
        for (int i = 30; i >= 0; --i) {
            if ((y ^ (x << i)) < y) {
                if (flag) {
                    ops.push_back({y, x << i, 1});
                }
                y ^= (x << i);
            }
        }
        return y;
    };


    while (x > 1) {
        ll z = x;
        for (int i = 0; i < 30; ++i) {
            ops.push_back({z, z, 0});
            z *= 2;
            ll y = norm(x, (x ^ z) + x);
            if (y < x && y != 0) {
                ops.push_back({x, z, 1});
                ops.push_back({x ^ z, x, 0});
                norm(x, (x ^ z) + x, true);
                if (!(y & 1)) {
                    y = norm(y, x, true);
                }
                x = y;
                break;
            }
        }
    }

    assert(sz(ops) < 1e5);
    cout << sz(ops) << endl;
    for (auto op : ops) {
        cout << op[0] << " " << (op[2] ? "^" : "+") << " " << op[1] << "\n";
    }

        
    // ll n;
    // cin >> n;

    // vector<int> dp(n + 1);

    // int maxx = 0;

    // for (ll x = 3; x <= n; x += 2) {
    //     bool ok = false;
    //     for (int k = 1; k < 20; ++k) {
    //         ll y = (x ^ (x << k)) + x;
    //         y = norm(x, y);
    //         if (y < x && y != 0) {
    //             cerr << x << " " << y << " " << k << endl;
    //             if (!(y & 1)) {
    //                 y = norm(y, x);
    //             }
    //             assert(y & 1);
    //             dp[x] = dp[y] + 1;
    //             ok = true;
    //             break;
    //         }
    //     }
    //     maxx = max(maxx, dp[x]);
    //     assert(ok);

    //     // // ll y = (x ^ (2 * x)) + (x ^ (4 * x));
    //     // ll y = (x ^ (2 * x)) + x;
    //     // // ll z = (x ^ (4 * x)) + (x ^ (4 * x));
    //     // ll z = (x ^ (4 * x)) + x;
    //     // y = norm(x, y);
    //     // z = norm(x, z);
    //     // cerr << bitset<10>(x) << " " << bitset<10>(y) << " " << bitset<10>(z) << endl;


    //     // // cerr << bitset<10>(x) << " " << bitset<10>((x ^ (2 * x)) + (x ^ (4 * x))) << endl;
    //     // // cerr << bitset<10>(i) << " " << bitset<10>((i ^ (2 * i)) + i) << endl;
    // }
    // cerr << maxx << endl;





    // ll x;
    // cin >> x;
    // ll y = x;

    // set<ll> setik;
    // setik.insert(x);

    // vector<array<int, 3>> ops;

    // auto apply = [&](const array<int, 3> &a) {
    //     ops.push_back(a);
    //     if (a[2] == 0) {
    //         setik.insert(a[0] + a[1]);
    //     } else {
    //         setik.insert(a[0] ^ a[1]);
    //     }
    // }

    // while (__builtin_popcount(y) > 1) {
    //     vector<int> bits;
    //     for (int i = 0; i < 60; ++i) {
    //         if (y & (1 << i)) {
    //             bits.push_back(i);
    //         }
    //     }

    //     ll z = y;
    //     for (int i = 0; i < bits[1] - bits[0]; ++i) {
    //         apply({z, z, 0});
    //         z *= 2;
    //     }

    //     apply({y, z, 0});
    //     apply({y, y + z, 1});


    // }

}