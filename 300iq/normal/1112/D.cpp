#include <bits/stdc++.h>

using namespace std;

const int N = 5000 + 1;

int dp[N][N];

int main()
{
#ifndef ONLINE_JUDGE
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = n - 1; j >= 0; j--)
    {
      if (s[i] == s[j])
      {
        dp[i][j] = dp[i + 1][j + 1] + 1;
      }
      else
      {
        dp[i][j] = 0;
      }
    }
  }
  vector <int> f(n + 1, 1e9);
  f[0] = 0;
  for (int i = 0; i < n; i++)
  {
    int mx = 0;
    for (int j = 0; j < i; j++)
    {
      int len = min(i - j, dp[i][j]);
      mx = max(mx, len);
    }
    f[i + 1] = min(f[i + 1], f[i] + a);
    for (int j = i; j <= i + mx - 1; j++)
    {
      f[j + 1] = min(f[j + 1], f[i] + b);
    }
  }
  cout << f[n] << endl;
}