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


const int MOD = 1000000007;

ll powmod(ll a, ll b) {
    if (b == 0) {
        return 1;
    }
    ll r = powmod(a, b >> 1);
    r = r * r % MOD;
    return (b & 1)? r * a % MOD : r;
}


int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    int t;
    cin >> t;
    while (t--) {
        ll n, p;
        cin >> n >> p;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if (p == 1) {
            cout << (n & 1) << "\n";
            continue;
        }
        sort(all(a));
        reverse(all(a));
        ll vl = 0;
        ll pw = 0;
        const ll LIMIT = n + 42;
        bool ok = true;
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            if (vl == 0) {
                vl = 1;
                pw = a[i];
                continue;
            }
            while (vl < LIMIT && pw > a[i]) {
                vl *= p;
                pw -= 1;
            }
            if (vl >= LIMIT) {
                ans = vl % MOD * powmod(p, pw) % MOD;
                for (int j = i; j < n; ++j) {
                    ans = (ans - powmod(p, a[j]) + MOD) % MOD;
                }
                ok = false;
                break;
            }
            if (vl < LIMIT) {
                vl -= 1;
            }
        }
        if (ok) {
            cout << vl % MOD * powmod(p, pw) % MOD << "\n";
        } else {
            cout << ans << "\n";
        }
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}