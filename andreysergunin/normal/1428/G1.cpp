#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double; 
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
    cout << setprecision(8) << fixed;
    cerr << setprecision(5) << fixed;

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
    int k;
    cin >> k;
    vector<ll> f(6);
    for (int i = 0; i < 6; ++i) {
        cin >> f[i];
    }

    auto get = [&](int n) {
        ll x = 0;
        for (int i = 0; i < 6; ++i) {   
            int r = n % 10;
            n /= 10;
            x += (r % 3 == 0 ? r / 3 * f[i] : 0);
        }
        return x;
    };
    
    int q;
    cin >> q;

    for (int que = 0; que < q; ++que) {
        int n;
        cin >> n;

        ll res = 0;

        for (int t = 0; t <= n; ++t) {
            int m = t;
            ll cur = get(n - m);
            if (m % 3 != 0) {
                continue;
            }
            m /= 3;

            vector<pair<ll, int>> arr, nxt;
            
            bool ok = true;

            for (int i = 0; i < 6; ++i) {
                if (k > 1) {
                    arr.push_back({f[i], 3 * k - 3});
                }
                sort(all(arr));

                int d = m % 10;
                m /= 10;
                
                while (d--) {
                    if (sz(arr) == 0) {
                        ok = false;
                        break;
                    }
                    cur += arr.back().first;
                    --arr.back().second;
                    if (arr.back().second == 0) {
                        arr.pop_back();
                    }
                }

                if (!ok) {
                    break;
                }

                int x = 0;
                ll s = 0;

                while (!arr.empty()) {
                    auto [val, cnt] = arr.back();
                    arr.pop_back();

                    if (x != 0 && x + cnt >= 10) {
                        nxt.push_back({s + val * (10 - x), 1});
                        cnt -= (10 - x);
                        x = 0;
                        s = 0;
                    }

                    if (cnt >= 10) {
                        nxt.push_back({val * 10, cnt / 10});
                        cnt %= 10;
                    }

                    x += cnt;
                    s += cnt * val;
                }

                arr = nxt;
                nxt.clear();
            }

            if (ok) {
                res = max(res, cur);
            }
        }

        cout << res << endl;
    }
}