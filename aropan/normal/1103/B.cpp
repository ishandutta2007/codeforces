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


int A;
int N;

string get(int x, int y) {
    cout << "? " << x << " " << y << endl;
    cout.flush();

    // if (++N > 60) {
    //     return "e";
    // }
    // return x % A >= y % A? "x" : "y";

    string ret;
    cin >> ret;
    if (ret == "e") {
        exit(0);
    }
    return ret;
}


int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifdef LOCAL
    // assert(freopen("inp", "r", stdin));
    // assert(freopen("out", "w", stdout));
    // #endif

    string stage;
    while (cin >> stage && stage == "start") {
    // for (;;) {
    //     A = rand() % 1000000000 + 1;
    //     N = 0;

        ll size = 1;
        while (get(size / 2, size) == "y") {
            size *= 2;
        }
        ll l = size / 2;
        ll r = size;
        while (l + 1 < r) {
            ll c = (l + r) / 2;
            if (get(l, c) == "x") {
                r = c;
            } else {
                l = c;
            }
        }
        ll ans = l + 1;
        cout << "! " << ans << endl;
        // assert(ans == A);
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}