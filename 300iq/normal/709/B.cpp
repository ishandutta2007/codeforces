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
  int n, a;
  cin >> n >> a;
  vector <int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  sort(x.begin(), x.end());
  auto cost = [&] (vector <int> x) {
    if (x.empty()) return 0;
    int n = (int) x.size();
    if (x[0] <= a && a <= x[n - 1])
      return min(abs(a - x[n - 1]), abs(a - x[0])) + abs(x[n - 1] - x[0]);
    else 
      return max(abs(x[0] - a), abs(x[n - 1] - a));
  };
  vector <int> t = x;
  t.pop_back();
  int ans = cost(t);
  t = x;
  t.erase(t.begin());
  ans = min(ans, cost(t));
  cout << ans << endl;
}