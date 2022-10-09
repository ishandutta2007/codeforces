#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;
int const nmax = 500;
int modulo;

int dp[5 + nmax][5 + nmax];
int seen[5 + nmax][5 + nmax];

int solve(int x, int y){
  if(x < 0 || y < 0)
    return 0;
  else if(x == 0 && y == 0)
    return 1;
  else if(0 < seen[x][y])
    return dp[x][y];
  else {
    dp[x][y] = (1LL * solve(x - 2, y    ) * x * (x - 1) / 2 +
                1LL * solve(x + 2, y - 2) * y * (y - 1) / 2 +
                1LL * solve(x, y - 1) * y * x) % modulo;
    seen[x][y] = 1;
  }
  return dp[x][y];
}

int frec[5 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m >> modulo;
  int full = n, half = 0;
  for(int i = 1;i <= m; i++){
    string s;
    cin >> s;
    s = "#" + s;
    int scount = 0;
    for(int j = 1;j <= n; j++){
      int val = s[j] - '0';
      scount += val;
      if(val == 1){
        frec[j]++;
        if(frec[j] == 1){
          full--;
          half++;
        } else if(frec[j] == 2)
          half--;
        else {
          cout << 0;
          return 0;
        }
      }
    }
    if(scount != 2){
      cout << 0;
      return 0;
    }
  }
  cout << solve(half, full);
  return 0;
}