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
  ll n, s;
  cin >> n >> s;
  auto sm = [&] (ll x) {
    int s = 0;
    while (x) {
      s += x % 10;
      x /= 10;
    }
    return s;
  };
  int inf = 1e6;
  ll ans = 0;
  ans += max(0ll, n - (s + inf) + 1);
  for (ll x = s; x <= n && x < s + inf; x++) {
    if (x - sm(x) >= s) {
      ans++;
    }
  }
  cout << ans << endl;
}