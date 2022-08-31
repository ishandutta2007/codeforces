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

const int N = 100 + 7;

int dp[N][30 * N];
pair <int, int> par[N][30 * N];

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> t(n), d(n), p(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i] >> d[i] >> p[i];
  }
  vector <int> ord;
  for (int i = 0; i < n; i++) {
    ord.push_back(i);
  }
  sort(ord.begin(), ord.end(), [&] (int i, int j) {
      return d[i] < d[j];
  });
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    int gay = ord[i];
    for (int j = 0; j < 30 * N; j++){
      if (dp[i + 1][j] < dp[i][j]) {
        dp[i + 1][j] = dp[i][j];
        par[i + 1][j] = {i, j};
      }
      if (j + t[i] < 30 * N) {
        int go = (j + t[gay] < d[gay] ? p[gay] : 0);
        if (dp[i + 1][j + t[gay]] < dp[i][j] + go) {
          dp[i + 1][j + t[gay]] = dp[i][j] + go;
          par[i + 1][j + t[gay]] = {i, j};
        }
      }
    }
  }
  int ans = 0;
  int pts = 0;
  for (int i = 0; i < 30 * N; i++) {
    int was = ans;
    ans = max(ans, dp[n][i]);
    if (ans != was) pts = i;
  }
  vector <int> as;
  int i = n;
  while (i || pts) {
    auto a = par[i][pts];
    if (a.second != pts) {
      as.push_back(ord[i - 1]);
    }
    i = a.first, pts = a.second;
  }
  reverse(as.begin(), as.end());
  cout << ans << endl;
  cout << as.size() << endl;
  for (int x : as) cout << x + 1 << ' ';
  cout << endl;
}