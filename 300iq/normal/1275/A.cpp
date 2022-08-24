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
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int e, f;
  cin >> e >> f;
  int ans = 0;
  for (int i = 0; i <= min(a, d); i++) {
    int cur = e * i;
    int ot_d = d - i;
    int grab = min(min(b, c), ot_d);
    cur += grab * f;
    ans = max(ans, cur);
  }
  cout << ans << endl;
}