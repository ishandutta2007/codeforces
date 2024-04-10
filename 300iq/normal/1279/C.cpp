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
    int n, m;
    cin >> n >> m;
    vector <int> a(n);
    vector <int> ind(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i]--;
      ind[a[i]] = i;
    }
    vector <int> b(m);
    int mx = -1;
    ll ans = 0;
    for (int i = 0; i < m; i++) {
      cin >> b[i];
      b[i]--;
      int x = ind[b[i]];
      if (x > mx) {
        mx = x;
        ans += 2 * (x - i) + 1;
      } else {
        ans++;
      }
    }
    cout << ans << '\n';
  };
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}