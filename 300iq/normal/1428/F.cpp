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
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector <pair <int, int> > f;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      int j = i;
      while (j < n && s[j] == '1') {
        j++;
      }
      f.push_back({i, j - 1});
      i = j - 1;
    }
  }
  sort(f.begin(), f.end(), [&] (pair <int, int> a, pair <int, int> b) {
    return a.second - a.first + 1 > b.second - b.first + 1;
  });
  ll ans = 0;
  auto cost = [&] (int n) {
    if (n < 0) return 0ll;
    return n * (ll) (n + 1) / 2;
  };
  for (int x = 1; x <= n; x++) {
    vector <pair <int, int >> g;
    for (int i = 0; i < (int) f.size(); i++) {
      if (f[i].second - f[i].first + 1 < x) {
        break;
      }
      g.push_back({f[i].first, f[i].second - x + 1});
    }
    if (g.empty()) continue;
    sort(g.begin(), g.end());
    ll sum = 0;
    for (int i = 0; i + 1 < (int) g.size(); i++) {
      int vl = g[i].second + 1;
      int ptr = g[i + 1].first - 1;
      sum += cost(ptr - vl + 1);
    }
    sum += cost(g[0].first);
    sum += cost(n - x - g.back().second);
    ans += cost(n - x + 1) - sum;
  }
  cout << ans << '\n';
}