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
  vector <int> a(n);
  map <int, int> dp;
  dp[0] = 1;
  const int mod = 1e9 + 7;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    vector <int> t;
    for (int x = 1; x * x <= a[i]; x++) {
      if (a[i] % x == 0) {
        t.push_back(x);
        if (x * x != a[i])
          t.push_back(a[i] / x);
      }
    }
    sort(t.rbegin(), t.rend());
    for (int p : t) {
      dp[p] += dp[p - 1];
      if (dp[p] >= mod) dp[p] -= mod;
    }
  }
  int s = -1;
  for (auto c : dp)  {
    s += c.second;
    if (s >= mod) s -= mod;
  }
  cout << s << endl;
}