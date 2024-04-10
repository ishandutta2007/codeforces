#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  auto solve = [&] () {
    int n, s;
    cin >> n >> s;
    vector <int> a(n);
    vector <ll> pref(n);
    ll t = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      t += a[i];
      pref[i] = t;
    }
    int ans = -1;
    int pos = -1;
    for (int skip = 0; skip <= n; skip++) {
      auto cost = [&] (int i) {
        if (skip <= i) {
          return pref[i] - a[skip];
        } else {
          return pref[i];
        }
      };
      int l = -1, r = n;
      while (l < r - 1) {
        int m = (l + r) / 2;
        if (cost(m) <= s) {
          l = m;
        } else {
          r = m;
        }
      }
      int was = ans;
      ans = max(ans, l + 1 - (skip <= l));
      if (ans != was) pos = skip;
    }
    if (pos == n) {
      cout << 0 << '\n';
    } else {
      cout << pos + 1 << '\n';
    }
  };
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}