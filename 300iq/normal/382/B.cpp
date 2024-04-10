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
  ll a, b, w, x, c;
  cin >> a >> b >> w >> x >> c;
  if (a < c) {
    cout << ((c - a) * x - b + w - x - 1) / (w - x) + c - a << '\n';
  } else {
    cout << 0 << '\n';
  }
  /*(
  for (int it = 0; ; it++) {
    if (c <= a) {
      cout << it << '\n';
      return 0;
    }
    c--;
    if (b >= x) {
      b -= x;
    } else {
      b = (w - (x - b));
      a--;
    }
  }
  */
}