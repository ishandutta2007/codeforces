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
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

typedef long long ll;

const int N = 50 + 2;

int dp[N][N][N];
int vl[N], vr[N], x[N], c[N];

int main() {
#ifdef ONPC
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, h, m;
  cin >> n >> h >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> vl[i] >> vr[i] >> x[i] >> c[i];
    vl[i]--, vr[i]--;
  }
  for (int len = 1; len <= n; len++)
  {
    for (int l = 0; l + len - 1 < n; l++)
    {
      int r = l + len - 1;
      for (int mx = l; mx <= r; mx++)
      {
        vector <int> ok(h + 2);
        for (int j = 0; j < m; j++)
        {
          if (l <= vl[j] && vl[j] <= mx && mx <= vr[j] && vr[j] <= r)
          {
            ok[x[j] + 1] += c[j];
          }
        }
        for (int i = 1; i <= h; i++)
        {
          ok[i] += ok[i - 1];
        }
        for (int cur = 0; cur <= h; cur++)
        {
          int sum = cur * cur - ok[cur];
          if (l < mx)
          {
            sum += dp[l][mx - 1][cur];
          }
          if (mx < r)
          {
            sum += dp[mx + 1][r][cur];
          }
          dp[l][r][cur] = max(dp[l][r][cur], sum);
        }
      }
      for (int x = 1; x <= h; x++)
      {
        dp[l][r][x] = max(dp[l][r][x], dp[l][r][x - 1]);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= h; i++) ans = max(ans, dp[0][n - 1][i]);
  cout << ans << endl;
}