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
  int n;
  cin >> n;
  map <int, int> mp;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    mp[x]++;
    ans = max(ans, mp[x]);
  }
  cout << ans << endl;
  /*
  int t;
  cin >> t;
  while (t--)  {
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    int need_x = (a + c - 1) / c;
    int need_y = (b + d - 1) / d;
    if (need_x + need_y > k) {
      cout << -1 << endl;
    } else {
      cout << need_x << ' ' << need_y << endl;
    }
    */
    /*
    if ((need_x)
    for (int x = 0; x <= 100; x++) {
      for (int y = 0; y <= 100; y++) {
        if (
      }
    }
    */
//  }
}