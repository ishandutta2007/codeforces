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

const int N = 200 + 7;

double dp[N][N][N];

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k, l;
  cin >> n >> k >> l;
  dp[0][0][l] = 1;
  vector <double> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i] /= 100;
  }
  vector <int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      for (int k = 0; k < N; k++) {
        dp[i + 1][j][k] += dp[i][j][k] * (1 - p[i]);
        if (a[i] == -1) {
          dp[i + 1][j + 1][k] += dp[i][j][k] * p[i];
        } else {
          int nk = min(k + a[i] + 1, N - 1);
          dp[i + 1][j + 1][nk] += dp[i][j][k] * p[i];
        }
      }
    }
  }
  double ans = 0;
  for (int j = k; j <= n; j++) {
    for (int t = j; t < N; t++) {
      ans += dp[n][j][t];
    }
  }
  cout << fixed << setprecision(20) << ans << endl;
}