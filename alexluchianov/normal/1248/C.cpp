#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int const modulo = 1000000007;

int v[1 + nmax];
int dp[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;

  ll result = 0;
  dp[0] = dp[1] = 1;
  for(int i = 2;i <= nmax; i++)
    dp[i] = (dp[i - 1] + dp[i - 2]) % modulo;
  cout << (2LL * (dp[n] + dp[m] - 1)) % modulo;

  return 0;
}