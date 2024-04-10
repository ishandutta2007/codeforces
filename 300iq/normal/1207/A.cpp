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
  int t;
  cin >> t;
  while (t--) {
    int b, p, f;
    cin >> b >> p >> f;
    int h, c;
    cin >> h >> c;
    int ans = 0;
    for (int i= 0; i <= 100; i++) {
      for (int j = 0; j <= 100; j++) {
        if (b >= 2 * i + 2 * j && p >= i && f >= j) {
          ans = max(ans, h * i + c * j);
        }
      }
    }
    cout << ans << endl;
  }
}