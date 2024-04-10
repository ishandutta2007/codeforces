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

#ifdef LOCAL
#define dbg(x) cerr << #x " = " << x << endl;
#include "pretty_print.h"
#else
#define dbg(x)
#endif

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define snd second
#define fst first

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
      ll p, q, r;
      cin >> p >> q >> r;
      int a[n];
      ll lm[n];
      ll rm[n];
      for (int i = 0; i < n; ++i) {
        cin >> a[i];
      }
      lm[0] = p * a[0];
      for (int i = 1; i < n; ++i) {
        lm[i] = max(lm[i - 1], p * a[i]);
      }
      rm[n - 1] = r * a[n - 1];
      for (int i = n - 2; i >= 0; --i) {
        rm[i] = max(rm[i + 1], r * a[i]);
      }
      ll answer = lm[0] + a[0] * q + rm[0];
      for (int i = 1; i < n; ++i) {
        chmax(answer, lm[i] + a[i] * q + rm[i]);
      }
      cout << answer << endl;
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}