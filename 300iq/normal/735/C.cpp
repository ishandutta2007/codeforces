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

  map <ll, int> dp;

int ans(ll n) {
  if (dp.count(n)) return dp[n];
  int ret = 0;
  for (ll x = max(0ll, n / 2 - 2); x <= n / 2 + 2; x++) {
    if (x > 0 && x < n && abs(x - (n - x)) <= 1) {
      ret = max(ret, max(ans(x), ans(n - x)) + 1);
    }
  }
  return dp[n] = ret;
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  vector <ll> f(100);
  f[0] = 1;
  f[1] = 2;
  for (int i= 0; i < 100; i++) {
    if (i >= 2)
      f[i] = f[i - 1] + f[i - 2];
  }
  int x = 0;
  while (f[x + 1] <= n) x++;
  cout << x << endl;
}