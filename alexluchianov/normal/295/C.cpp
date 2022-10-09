#include <iostream>
#include <queue>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 50;
int const inf = 100000;
int const modulo = 1000000007;
int dp[1 + nmax][1 + nmax][2];
int dpcount[1 + nmax][1 + nmax][2];
int comb[1 + nmax][1 + nmax];

void computecomb(){
  comb[0][0] = 1;
  for(int i = 1;i <= nmax; i++) {
    comb[i][0] = 1;
    for(int j = 1; j <= i; j++)
      comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % modulo;
  }
}

int main()
{
  computecomb();
  int n, k;
  cin >> n >> k;
  int atotal = 0, btotal = 0;
  for(int i = 1;i <= n; i++){
    int val;
    cin >> val;
    if(val == 50)
      atotal++;
    else
      btotal++;
  }
  for(int i = 0;i <= nmax; i++)
    for(int j = 0;j <= nmax; j++)
      for(int h = 0; h < 2; h++)
        dp[i][j][h] = inf;

  dp[atotal][btotal][0] = 0;
  dpcount[atotal][btotal][0] = 1;
  queue<pair<pair<int,int>, int>> q;
  q.push({{atotal, btotal}, 0});

  while(0 < q.size()){
    int a = q.front().first.first;
    int b = q.front().first.second;
    int side = q.front().second;
    q.pop();
    if(side == 0){
      for(int a2 = 0; a2 <= a; a2++)
        for(int b2 = 0; b2 <= b; b2++)
          if(0 < a2 + b2 && a2 * 50 + b2 * 100 <= k) {
            if(dp[a][b][side] + 1 < dp[a - a2][b - b2][!side]){
              dp[a - a2][b - b2][!side] = dp[a][b][side] + 1;
              dpcount[a - a2][b - b2][!side] = 1LL * dpcount[a][b][side] * comb[a][a2] % modulo * comb[b][b2] % modulo;
              q.push({{a - a2, b - b2}, !side});
            } else if(dp[a][b][side] + 1 == dp[a - a2][b - b2][!side]){
              dpcount[a - a2][b - b2][!side] += 1LL * dpcount[a][b][side] * comb[a][a2] % modulo * comb[b][b2] % modulo;
              if(modulo <= dpcount[a - a2][b - b2][!side])
                dpcount[a - a2][b - b2][!side] -= modulo;
            }
          }
    } else {
      for(int a2 = 0; a2 + a <= atotal; a2++)
        for(int b2 = 0; b2 + b <= btotal; b2++)
          if(0 < a2 + b2 && a2 * 50 + b2 * 100 <= k) {
            if(dp[a][b][side] + 1 < dp[a + a2][b + b2][!side]){
              dp[a + a2][b + b2][!side] = dp[a][b][side] + 1;
              dpcount[a + a2][b + b2][!side] = 1LL * dpcount[a][b][side] * comb[atotal - a][a2] % modulo * comb[btotal - b][b2] % modulo;
              q.push({{a + a2, b + b2}, !side});
            } else if(dp[a][b][side] + 1 == dp[a + a2][b + b2][!side]){
              dpcount[a + a2][b + b2][!side] += 1LL * dpcount[a][b][side] * comb[atotal - a][a2] % modulo * comb[btotal - b][b2] % modulo;
              if(modulo <= dpcount[a + a2][b + b2][!side])
                dpcount[a + a2][b + b2][!side] -= modulo;
            }
          }
    }
  }
  if(0 < dpcount[0][0][1])
    cout << dp[0][0][1] << '\n' << dpcount[0][0][1];
  else
    cout << -1 << '\n' << 0 ;
  return 0;
}