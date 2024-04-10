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
  vector <ll> x(1), y(1);
  cin >> x[0] >> y[0];
  ll ax, ay, bx, by;
  cin >> ax >> ay >> bx >> by;
  ll xs, ys, t;
  cin >> xs >> ys >> t;
  for (int i = 1; ; i++) {
    x.push_back(0);
    y.push_back(0);
    x[i] = x[i - 1] * ax + bx;
    y[i] = y[i - 1] * ay + by;
    if (x[i] > xs + t || y[i] > ys + t) {
      break;
    }
  }
  int ans = 0;
  auto f = [&] (vector <ll> x, vector <ll> y) {
     for (int i = 0; i < (int) x.size(); i++) {
       for (int p = 0; p <= i; p++) {
        ll cur = abs(xs - x[i]) + abs(ys - y[i]);
        if (cur > t) continue;
        int mem = 1;
        ll sx = x[i], sy = y[i];
        for (int j = i - 1; j >= p; j--) {
          cur += abs(x[j] - sx) + abs(y[j] - sy);
          sx = x[j], sy = y[j];
          if (cur > t) break;
          mem++;
        }
        for (int j = i + 1; j < (int) x.size(); j++) {
          cur += abs(x[j] - sx) + abs(y[j] - sy);
          sx = x[j], sy = y[j];
          if (cur > t) break;
          mem++;
        }
        ans = max(ans, mem);
      }
    }
  };
  f(x, y);
  reverse(x.begin(), x.end());
  reverse(y.begin(), y.end());
  f(x, y);
  cout << ans << endl;
}