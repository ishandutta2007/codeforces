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

const int N = 300;

struct triple {
  int i, j, k;
};

int dp[N][N][N];
triple par[N][N][N];
int go[N][26];

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  string a, b;
  cin >> a >> b;
  string virus;
  cin >> virus;
  int m = (int) virus.size();
  vector <int> p(m);
  int j = 0;
  for (int i= 1; i < m; i++) {
    while (j > 0 && virus[i] != virus[j]) {
      j = p[j - 1];
    }
    j += (virus[i] == virus[j]);
    p[i] = j;
  }
  for (int i = 0; i < m; i++) {
    for (int t = 0; t < 26; t++) {
      if (t == virus[i] - 'A') {
        go[i][t] = i + 1;
      } else {
        if (i)
          go[i][t] = go[p[i - 1]][t];
        else
          go[i][t] = 0;
      }
    }
  }
  dp[0][0][0] = 0;
  for (int i = 0; i <= (int) a.size(); i++) {
    for (int j = 0; j <= (int) b.size(); j++) {
      for (int k = 0; k < m; k++) {
        if (i + 1 <= (int) a.size()) {
          int was = dp[i + 1][j][k];
          dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
          if (dp[i + 1][j][k] != was) {
            par[i + 1][j][k] = {i, j, k};
          }
        }
        if (j + 1 <= (int) b.size()) {
          int was = dp[i][j + 1][k];
          dp[i][j + 1][k] = max(dp[i][j + 1][k], dp[i][j][k]);
          if (dp[i][j + 1][k] != was) {
            par[i][j + 1][k] = {i, j, k};
          }
        }
        if (i < (int) a.size() && j < (int) b.size() && a[i] == b[j]) {
          int p = go[k][a[i] - 'A'];
          if (p < m) {
            int was = dp[i + 1][j + 1][p];
            dp[i + 1][j + 1][p] = max(dp[i + 1][j + 1][p], dp[i][j][k] + 1);
            if (dp[i + 1][j + 1][p] != was) {
              par[i + 1][j + 1][p] = {i, j, k};
            }
          }
        }
      }
    }
  }
  int x = -1, y = -1, z = -1;
  int ans = 0;
  for (int t = 0; t < m; t++) {
    int was = ans;
    ans = max(ans, dp[a.size()][b.size()][t]);
    if (was != ans) {
      x = a.size(), y = (int) b.size(), z = t;
    }
  }
  if (ans == 0) {
    cout << 0 << endl;
  } else {
    string ans = "";
    while (dp[x][y][z]) {
      auto go = par[x][y][z];
      if (go.i != x && go.j != y) {
        ans += a[x-1];
      }
      x = go.i, y = go.j, z = go.k;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
  }
}