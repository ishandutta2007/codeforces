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

const int N = 5000 + 7;

int dp[N][N];

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector <int> a(n), b(n), c(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }
  vector <int> when(n);
  for (int i = 0; i < n; i++) when[i] = i;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    when[v] = max(when[v], u);
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= 5000; j++) {
      dp[i][j] = -1e9;
    }
  }
  dp[0][k] = 0;
  for (int i = 0; i < n; i++) {
    vector <int> costs;
    for (int t = 0; t < n; t++) {
      if (when[t] == i)
        costs.push_back(c[t]);
    }
    sort(costs.rbegin(), costs.rend());
    for (int j = 0; j <= 5000; j++) {
      if (j >= a[i] && dp[i][j] >= 0) {
        int nj = j + b[i];
        dp[i + 1][nj] = max(dp[i + 1][nj], dp[i][j]);
      }
    }
    for (int x : costs) {
      for (int j = 1; j <= 5000; j++) {
        if (dp[i + 1][j] >= 0) {
          dp[i + 1][j - 1] = max(dp[i + 1][j - 1], dp[i + 1][j] + x);
        }
      }
    }
  }
  int mx = -1;
  for (int i = 0; i <= 5000; i++)
    mx = max(mx, dp[n][i]);
  cout << mx << endl;
}