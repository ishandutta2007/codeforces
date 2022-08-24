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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x, y, x1, y1, x2, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    x1 -= x, y1 -= y, x2 -= x, y2 -= y;
    if (x1 < 0 || x2 > 0) {
      int t = min(a, b);
      a -= t, b -= t;
    }
    if (y1 < 0 || y2 > 0) {
      int t = min(c, d);
      c -= t, d -= t;
    }
    swap(a, b), swap(c, d);
    x = y = 0;
    if (x + a > x2 || x - b < x1 || y + c > y2 || y - d < y1) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
    }
  }
}