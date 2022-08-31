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
  int n, m;
  cin >> n >> m;
  vector <ll> need(n);
  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    a--, b--;
    need[a] -= w;
    need[b] += w;
  }
  vector <int> x, y;
  for (int i = 0; i < n; i++) {
    if (need[i] > 0)
      x.push_back(i);
    if (need[i] < 0)
      y.push_back(i);
  }
  vector <pair <pair <int, int>, ll> > ans;
  while (!x.empty() && !y.empty()) {
    if (!need[x.back()]) {
      x.pop_back(); continue;
    }
    if (!need[y.back()]) {
      y.pop_back(); continue;
    }
    ll cur = min(need[x.back()], -need[y.back()]);
    need[x.back()] -= cur;
    need[y.back()] += cur;
    ans.push_back({{x.back(), y.back()}, cur});
  }
  cout << ans.size() << '\n';
  for (auto c : ans) {
    cout << c.first.second + 1 << ' ' << c.first.first + 1 << ' ' << c.second << '\n';
  }
}