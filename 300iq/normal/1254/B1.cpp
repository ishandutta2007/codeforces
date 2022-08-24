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
  int n;
  cin >> n;
  vector <int> a(n);
  ll s = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s += a[i];
  }
  vector <ll> to_check;
  for (ll x = 2; x * x <= s; x++) {
    if (s % x == 0) {
      while (s % x == 0) {
        s /= x;
      }
      to_check.push_back(x);
    }
  }
  if (s != 1) {
    to_check.push_back(s);
  }
  if (to_check.empty()) {
    cout << -1 << '\n';
    return 0;
  }
  ll ans = 1e18;
  for (ll x : to_check) {
    ll cur = 0;
    ll tot = 0;
    for (int i = 0; i < n; i++) {
      cur += a[i] % x;
      cur %= x;
      tot += min(cur, x - cur);
    }
    ans = min(ans, tot);
  }
  cout << ans << endl;
}