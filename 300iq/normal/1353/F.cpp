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

const ll inf = (ll) (1e18) + 7;

ll a[100][100];
ll dp[100][100];

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    auto f = [&] (ll x) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          dp[i][j] = inf;
        }
      }
      dp[0][0] = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (a[i][j] < x + (i + j)) {
            dp[i][j] = inf;
          } else {
            ll cost = a[i][j] - (x + (i + j));
            dp[i][j] += cost;
            if (i + 1 < n) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            if (j + 1 < m) dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
          }
        }
      }
      return dp[n - 1][m - 1];
    };
    ll ans = inf;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ans = min(ans, f(a[i][j] - (i + j)));
      }
    }
    cout << ans << '\n';
  }
}