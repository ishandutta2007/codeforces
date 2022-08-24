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
  int n, h;
  cin >> n >> h;
  vector <int> l(n), r(n);
  vector <int> ok(n);
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
    if (i) {
      ok[i] = ok[i - 1];
      ok[i] -= r[i - 1];
    }
    ok[i] += l[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x = lower_bound(ok.begin(), ok.end(), h + ok[i]) - ok.begin() - 1;
    ans = max(ans, (x >= 0 ? r[x] - ok[x] : 0) - l[i] + h + ok[i]);
  }
  cout << ans << '\n';
}