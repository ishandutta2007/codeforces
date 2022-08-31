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
#include <iomanip>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int N = 3e5 + 7;
const ll inf = (ll) (1e18) + 7;

ll dp[N][3][3];

int main()
{
#ifdef ONPC
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  vector <ll> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (int i = 0; i <= n; i++)
  {
    for (int x = 0; x < 3; x++)
    {
      for (int j = 0; j < 3; j++)
      {
        dp[i][x][j] = -inf;
      }
    }
  }
  dp[0][0][0] = 0;
  for (int i = 0; i < n; i++)
  {
    for (int oa = 0; oa < 3; oa++)
    {
      for (int ob = 0; ob < 3; ob++)
      {
        ll me = a[i];
        if (oa != 2)
        {
          if (ob != 2)
          {
            dp[i + 1][1][1] = max(dp[i + 1][1][1], dp[i][oa][ob] + me * x);
          }
          int new_ob = (ob == 0 ? ob : 2);
          dp[i + 1][1][new_ob] = max(dp[i + 1][1][new_ob], dp[i][oa][ob]);
        }
        {
          int new_oa = (oa == 0 ? oa : 2);
          if (ob != 2)
          {
            dp[i + 1][new_oa][1] = max(dp[i + 1][new_oa][1], dp[i][oa][ob] + me);
          }
          int new_ob = (ob == 0 ? ob : 2);
          dp[i + 1][new_oa][new_ob] = max(dp[i + 1][new_oa][new_ob], dp[i][oa][ob]);
        }
      }
    }
  }
  ll ans = 0;
  for (int i = 0; i <= n; i++)
  {
    for (int a = 0; a < 3; a++)
    {
      for (int b = 0; b < 3; b++)
      {
        ans = max(ans, dp[i][a][b]);
      }
    }
  }
  cout << ans << endl;
}