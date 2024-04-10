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

const int inf = 1e9;

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, r;
  cin >> r >> n;
  vector <int> x(n), y(n), t(n);
  vector <int> dp(n, -inf);
  int mx = -inf;
  for (int i = 0; i < n; i++) {
    cin >> t[i] >> x[i] >> y[i];
  }
  for (int i = 0; i < n; i++) {
    if (i >= 2 * r) {
      mx = max(mx, dp[i - 2 * r]);
    }
    if (abs(x[i] - 1) + abs(y[i] - 1) <= t[i]) {
      dp[i] = max(dp[i], 1);
    }
    dp[i] = max(dp[i], mx + 1);
    for (int j = i + 1; j < i + r + r && j < n; j++) {
      if (abs(x[i] - x[j]) + abs(y[i] - y[j]) + t[i] <= t[j]) {
        dp[j] = max(dp[j], dp[i] + 1);
      }
    }
  }
  cout << max(0, *max_element(dp.begin(), dp.end())) << endl;
}