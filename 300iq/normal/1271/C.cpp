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
  int n, x, y;
  cin >> n >> x >> y;
  vector <int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  auto dist = [&] (int a, int b, int c, int d) {
    return abs(a - c) + abs(b - d);
  };
  int best = -1;
  int ax = 0, ay = 0;
  for (int px = x - 1; px <= x + 1; px++) {
    for (int py = y - 1; py <= y + 1; py++) {
      if (px == x && py == y) continue;
      if (px < 0) continue;
      if (py < 0) continue;
      if (px > 1e9) continue;
      if (py > 1e9) continue;
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        if (dist(a[i], b[i], x, y) == dist(a[i], b[i], px, py) + dist(px, py, x, y)) {
          cnt++;
        }
      }
      if (cnt > best) {
        best = cnt;
        ax = px, ay = py;
      }
    }
  }
  cout << best << '\n';
  cout << ax << ' ' << ay << '\n';
}