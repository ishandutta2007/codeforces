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


string to_bin(int x) {
    string ret;
    while (x) {
        ret = ret + (char)((x % 2) + '0');
        x /= 2;
    }
    return ret;
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif

    // const int MAXN = 1000;
    // set<int> s;
    // vector<int> res;
    // for (int a = 1; a < MAXN; ++a) {
    //     bool ok = true;
    //     if (s.count(a) == 0)
    //         for (int b = a + 1; b < MAXN && ok; ++b) {
    //             if (s.count(b) == 0)
    //                 for (int c = b + 1; c < MAXN && ok; ++c) {
    //                     if (s.count(c) == 0 && (a ^ b ^ c) == 0) {
    //                         // cout << a << " " << b << " " << c << endl;
    //                         // cout << to_bin(b) << endl;
    //                         s.insert(a);
    //                         s.insert(b);
    //                         s.insert(c);
    //                         ok = false;
    //                         res.push_back(a);
    //                         res.push_back(b);
    //                         res.push_back(c);
    //                     }
    //                 }
    //         }
    // }


    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;

        ll m = (n - 1) / 3;
        int k = 0;
        ll p = 1;
        while (m >= p) {
            m -= p;
            k += 1;
            p *= 4;
        }
        vector<ll> a;
        for (int i = 0; i < k; ++i) {
            a.push_back(m % 4);
            m /= 4;
        }

        ll A, B;
        A = 1LL << (2 * k);
        B = 1LL << (2 * k + 1);
        vector<ll> b = {0, 2, 3, 1};
        for (int i = 0; i < k; ++i) {
            A ^= a[i] << (2 * i);
            B ^= b[a[i]] << (2 * i);
        }
        ll C = A ^ B;

        ll ans;
        if (n % 3 == 1) {
            ans = A;
        } else if (n % 3 == 2) {
            ans = B;
        } else {
            ans = C;
        }
        // dbg(n);
        // dbg(res[n - 1]);
        // dbg(ans);
        // assert(res[n - 1] == ans);
        cout << ans << "\n";
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}