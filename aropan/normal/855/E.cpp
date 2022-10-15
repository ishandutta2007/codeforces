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

const int MAXB = 11;
const int MAXL = 70;
const int MAXM = 1024;

ll f[MAXB][MAXL][MAXM];

ll get(ll n, int b) {
  vector <int> a;
  do  {
    a.push_back(n % b);
    n /= b;
  } while (n);
  reverse(a.begin(), a.end());
  // cout << a << endl;
  ll answer = 0;
  int l = a.size();
  int mask = 0;

  for (int i = 1; i < l; ++i) {
    for (int j = 1; j < b; ++j) {
      answer += f[b][i - 1][(1 << j)];
    }
  }

  for (int i = 0; i < l; ++i) {
    for (int j = (i == 0)? 1 : 0; j < a[i]; ++j) {
      mask ^= (1 << j);
      answer += f[b][l - i - 1][mask];
      mask ^= (1 << j);
    }
    mask ^= 1 << a[i];
  }
  if (mask == 0) {
    answer += 1;
  }
  return answer;
}


int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif

    memset(f, 0, sizeof(f));
    for (int b = 2; b < MAXB; ++b) {
      f[b][0][0] = 1;
      for (int i = 0; i < MAXL - 1; ++i) {
        for (int j = 0; j < MAXM; ++j) {
          if (f[b][i][j]) {
            for (int x = 0; x < b; ++x) {
              f[b][i + 1][j ^ (1 << x)] += f[b][i][j];
            }
          }
        }
      }
    }

    int t;
    cin >> t;
    while (t--) {
      int b;
      ll l, r;
      cin >> b >> l >> r;
      // cout << get(r, b) << endl;
      cout << get(r, b) - get(l - 1, b) << "\n";
      // cout << endl;
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}