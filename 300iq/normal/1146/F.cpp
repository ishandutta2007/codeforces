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

const int N = 2e5 + 7;
const int M = 998244353;

inline int add(int a, int b)
{
  a += b;
  if (a >= M) a -= M;
  if (a < 0) a += M;
  return a;
}

inline int mul(int a, int b)
{
  return (a * (ll) b) % M;
}

vector <int> g[N];
int dp_grab[N];
int dp[N];

int cur[3][2];
int go_cur[3][2];

void dfs(int v)
{
  for (int to : g[v])
  {
    dfs(to);
  }
  if (g[v].empty())
  {
    dp[v] = dp_grab[v] = 1;
    return;
  }
  for (int i = 0; i <= 2; i++)
  {
    for (int t = 0; t < 2; t++)
    {
      cur[i][t] = 0;
    }
  }
  cur[0][0] = 1;
  for (int to : g[v])
  {
    for (int i = 0; i <= 2; i++)
    {
      for (int t = 0; t < 2; t++)
      {
        go_cur[i][t] = 0;
      }
    }
    for (int i = 0; i <= 2; i++)
    {
      for (int t = 0; t < 2; t++)
      {
        int j = min(i + 1, 2);
        go_cur[j][t] = add(go_cur[j][t], mul(cur[i][t], dp_grab[to]));
        go_cur[i][t] = add(go_cur[i][t], mul(cur[i][t], dp[to]));
        if (!t)
        {
          go_cur[i][1] = add(go_cur[i][1], mul(cur[i][t], dp_grab[to]));
        }
      }
    }
    for (int i = 0; i <= 2; i++)
    {
      for (int t = 0; t < 2; t++)
      {
        cur[i][t] = go_cur[i][t];
      }
    }
  }
  dp[v] = add(cur[0][0], cur[2][0]);
  dp_grab[v] = add(cur[0][1], cur[2][0]);
}

int main() {
#ifdef ONPC
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++)
  {
    int p;
    cin >> p;
    p--;
    g[p].push_back(i);
  }
  dfs(0);
  cout << dp[0] << '\n';
}