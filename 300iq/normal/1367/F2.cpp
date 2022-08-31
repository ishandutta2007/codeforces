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
    int n;
    cin >> n;
    vector <int> a(n);
    map <int, deque <int> > orz;
    vector <int> b;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      b.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    for (int i = 0; i < n; i++) {
      a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
      orz[a[i]].push_back(i);
    }
    map <int, int> dp;
    int ans = 0;
    for (auto c : orz) {
      dp[c.first] = orz[c.first].size();
      if (!orz[c.first - 1].empty() && orz[c.first - 1].back() < orz[c.first].front()) {
        dp[c.first] = max(dp[c.first], dp[c.first - 1] + (int) orz[c.first].size());
      }
      int cnt = 0;
      for (auto d : orz[c.first - 1]) {
        if (d < orz[c.first].front()) {
          cnt++;
        }
      }
      dp[c.first] = max(dp[c.first], cnt + (int) orz[c.first].size());
      ans = max(ans, dp[c.first]);
      int ret = 0;
      for (auto d : orz[c.first]) {
        if (!orz[c.first - 1].empty() && d > orz[c.first - 1].back()) {
          ret++;
        }
      }
      ans = max(ans, dp[c.first  - 1] + ret);
      vector <pair <int, int> > arr;
      for (auto d : orz[c.first - 1]) {
        arr.push_back({d, 0});
      }
      for (auto d : orz[c.first]) {
        arr.push_back({d, 1});
      }
      sort(arr.begin(), arr.end());
      int dp0 = 0, dp1 = 0;
      for (auto c : arr) {
        if (c.second == 1) {
          dp1++;
        } else {
          dp0++;
          dp1 = max(dp1, dp0);
        }
      }
      ans = max(ans, dp1);
    }
    cout << n - ans << '\n';
  }
}