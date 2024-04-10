#include <cmath>
#include <functional>
#include <fstream>
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

const int inf = 1e9 + 228;

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, a, r, m;
  cin >> n >> a >> r >> m;
  m = min(m, a + r);
  vector <int> h(n);
  for (int i = 0; i < n; i++) cin >> h[i];
  ll sum = 0;
  for (int i = 0; i < n; i++) sum += h[i];
  sort(h.begin(), h.end());
  auto cost = [&] (int x) {
    ll sm = 0;
    for (int i = 0; i < n; i++) {
      sm += abs(h[i] - x) * (ll) m;
    }
    ll trash = abs(n * (ll) x - sum);
    ll s = (sm - trash * (ll) m) / 2;
    if (sum < n * (ll) x) {
      s += (n * (ll) x - sum) * (ll) a;
    } else {
      s += (sum - n * (ll) x) * (ll) r;
    }
    return s;
  };
  ll ans = 1e18;
  auto relax = [&] (int l, int r) {
    if (l > r) return;
    l--;
    while (l < r - 1) {
      int m = (l + r) / 2;
      if (cost(m) > cost(m + 1)) {
        l = m;
      } else {
        r = m;
      }
    }
    ans = min(ans, cost(l + 1));
  };
  ll ok = sum / n;
  relax(0, ok - 3);
  relax(ok + 3, inf);
  for (ll i = ok - 2; i <= ok + 2; i++) {
    if (i >= 0) {
      ans = min(ans, cost(i));
    }
  }
  cout << ans << endl;
}