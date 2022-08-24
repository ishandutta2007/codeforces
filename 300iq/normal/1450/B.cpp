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

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector <int> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    int ans = -1;
    for (int i = 0; i < n; i++) {
      int mx = 0;
      for (int j = 0; j < n; j++) {
        mx = max(mx, abs(x[i] - x[j]) + abs(y[i] - y[j]));
      }
      if (mx <= k) ans = 1;
    }
    cout << ans << '\n';
  }
}