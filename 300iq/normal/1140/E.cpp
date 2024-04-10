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

#ifdef ONPC
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

vector <int> a[2];

const int N = 2e5 + 7;
const int M = 998244353;

void add(int &a, int b)
{
  a += b;
  if (a < 0) a += M;
  if (a >= M) a -= M;
}

int mul(int a, int b)
{
  return (a * (ll) b) % M;
}

int bin(int a, int n)
{
  int res = 1;
  while (n)
  {
    if (n % 2 == 0)
    {
      a = mul(a, a);
      n /= 2;
    }
    else
    {
      res = mul(res, a);
      n--;
    }
  }
  return res;
}

int dp[N][2][2];

int solve(vector <int> a, int k)
{
  int inv = bin(k, M - 2);
  int n = (int) a.size();
  for (int i = 0; i < n; i++)
  {
    for (int t = 0; t < 2; t++)
    {
      for (int d = 0; d < 2; d++)
      {
        dp[i][t][d] = 0;
      }
    }
  }
  dp[0][a[0] != -1][0] = (a[0] != -1 ? 1 : k);
  vector <int> last;
  if (a[0] != -1)
  {
    last.push_back(a[0]);
  }
  for (int i = 1; i < n; i++)
  {
    for (int t = 0; t < 2; t++)
    {
      for (int chet = 0; chet < 2; chet++)
      {
        if (!dp[i - 1][t][chet]) continue;
        add(dp[i][a[i] != -1][chet], mul(dp[i - 1][t][chet], a[i] != -1 ? 1 : k));
        if (a[i] != -1 && t && last.back() != a[i]) continue;
        int koef = ((!t && (a[i] != -1)) ? inv : 1);
        add(dp[i][t | (a[i] != -1)][chet ^ 1], mul(dp[i - 1][t][chet], koef));
      }
    }
    if (a[i] != -1)
    {
      last.push_back(a[i]);
    }
  }
  int ans = 0;
  for (int t = 0; t < 2; t++)
  {
    for (int d = 0; d < 2; d++)
    {
      if (d == 0)
      {
        add(ans, dp[n - 1][t][d]);
      }
      else
      {
        add(ans, -dp[n - 1][t][d]);
      }
    }
  }
  return ans;
}

int main()
{
#ifdef ONPC
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    a[i % 2].push_back(x);
  }
  cout << mul(solve(a[0], k), solve(a[1], k)) << '\n';
}