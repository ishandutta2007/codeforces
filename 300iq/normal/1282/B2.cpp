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
    int n, p, k;
    cin >> n >> p >> k;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector <int> dp(n);
    for (int i = 0; i < n; i++) {
      if (i >= k - 1) {
        dp[i] = (i >= k ? dp[i - k] : 0) + a[i];
      } else {
        dp[i] = (i ? dp[i - 1] : 0) + a[i];
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (dp[i] <= p) {
        ans = i + 1;
      }
    }
    cout << ans << '\n';
  }
}