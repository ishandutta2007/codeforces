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
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  vector <int> b(n);
  for (int i = 0; i < n; i++) cin >> b[i];
  int ans = n + 1;
  for (int x= b[0]  - 1; x <= b[0] + 1; x++) {
    for (int y = b[1] - 1; y <= b[1] + 1; y++) {
      auto s = b;
      s[0] = x, s[1] = y;
      bool bad = false;
      for (int i = 2; i < n; i++) {
        s[i] = s[i - 1] + (y - x);
        if (abs(s[i] - b[i]) > 1) {
          bad = true;
          break;
        }
      }
      if (!bad) {
        int cur = 0;
        for (int i = 0; i < n; i++) if (s[i] != b[i]) cur++;
        ans= min(ans, cur);
      }
    }
  }
  if (ans == n + 1) ans = -1;
  cout << ans << endl;
}