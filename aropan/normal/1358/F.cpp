#include <iostream>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
#define dbg(x) cerr << #x " = " << x << endl;
#define idbg(x) #x " = " << x
#include "pretty_print.h"
#else
#define dbg(x)
#define idbg(x) ""
#endif

#ifdef _WIN32
#  define LLD "%I64d"
#else
#  define LLD "%lld"
#endif

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> bool chmin(T &x, const T& y) { if (x > y) { x = y; return true; } return false; }
template <typename T> bool chmax(T &x, const T& y) { if (x < y) { x = y; return true; } return false; }


int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    int n;
    while (cin >> n) {
        vector<ll> a(n);
        vector<ll> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<ll> r = a;
        reverse(all(r));
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        string ans;
        bool ok = true;
        ll cnt = 0;
        ll res = 0;
        int limit = 200000;
        for (;;) {
            if (a == b) {
                break;
            }
            if (r == b) {
                ans += "R";
                res += 1;
                reverse(all(b));
                break;
            }
            if (n == 1) {
                ok = false;
                break;
            }
            bool up = true;
            bool down = true;
            bool positive = true;
            for (int i = 0; i < n; ++i) {
                positive &= b[i] > 0;
            }
            if (!positive) {
                ok = false;
                break;
            }
            for (int i = 1; i < n; ++i) {
                up &= b[i - 1] < b[i];
                down &= b[i - 1] > b[i];
            }
            if (!up && !down) {
                ok = false;
                break;
            }
            if (!up) {
                ans += "R";
                res += 1;
                reverse(all(b));
                continue;
            }

            if (cnt > limit && n == 2) {
                ll sa = a[0] + a[1];
                ll sb = b[0] + b[1];
                if (sa >= sb) {
                    ok = false;
                    break;
                }
                ll k = min(sb - sa, b[1]) / b[0];
                if (k <= 0) {
                    ok = false;
                    break;
                }
                b[1] = b[1] - k * b[0];
                res += k;
            } else {
                for (int i = n - 1; i > 0; --i) {
                    b[i] -= b[i - 1];
                }
                ans += "P";
                res += 1;
                cnt += 1;
            }
        }

        if (!ok) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        cout << (cnt <= limit? "SMALL" : "BIG") << endl;
        if (cnt > limit) {
            for (auto& c : ans) {
                res -= c == 'R';
            }
        }
        cout << res << endl;
        if (cnt <= limit) {
            reverse(all(ans));
            cout << ans << endl;
        }
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}