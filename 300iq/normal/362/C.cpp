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

const int N = 5000;

int dp[N][N];

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> p(n);
  int s = 0;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    if (i) s += dp[i - 1][p[i]];
    for (int j = 0; j < p[i]; j++) {
      dp[i][j]++;
    }
    for (int j = 0; j < n; j++) {
      if (i) dp[i][j] += dp[i - 1][j];
    }
  }
  int ans = 1e9;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (p[i] > p[j]) {
        int go = s - 2 * (dp[i][p[i]] + dp[j][p[j]] - dp[i][p[j]] - dp[j][p[i]]) - 1;
        if (go < ans) {
          ans = go;
          cnt = 1;
        } else if (go == ans) cnt++;
      }
    }
  }
  cout << ans << ' ' << cnt << endl;
}