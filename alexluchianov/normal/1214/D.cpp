#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
vector<vector<char>> v;
vector<vector<int> > dp;
vector<vector<int> > dp2;

int scount[1 + 2 * nmax];


int main()
{
  int n, m;
  cin >> n >> m;
  v.resize(2 + n);
  for(int i = 0; i <= 1 + n; i++)
    v[i].resize(2 + m);

  dp.resize(2 + n);
  for(int i = 0; i <= 1 + n; i++)
    dp[i].resize(2 + m);

  dp2.resize(2 + n);
  for(int i = 0; i <= 1 + n; i++)
    dp2[i].resize(2 + m);

  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++)
      cin >> v[i][j];

  dp[1][1] = 1;
  dp2[n][m] = 1;

  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++)
      if(v[i][j] == '.')
        dp[i][j] |= dp[i - 1][j] | dp[i][j - 1];


  for(int i = n;1 <= i; i--)
    for(int j = m; 1 <= j; j--)
      if(v[i][j] == '.') {
        dp2[i][j] |= dp2[i + 1][j] | dp2[i][j + 1];
      }

  int smin = 2;
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++)
      scount[i + j] += (dp[i][j] & dp2[i][j]);


  for(int i = 3;i < n + m; i++)
    smin = MIN(smin, scount[i]);
  cout << smin;
  return 0;
}