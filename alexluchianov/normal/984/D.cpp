#include <iostream>

using namespace std;

int const nmax = 5000;
int v[5 + nmax];

int dp[5 + nmax][5 + nmax];
int n;

void computedp(){
  for(int i = 1 ; i <= n ;i++)
    dp[i][i] = v[i];
  for(int h = 1 ; h < n ;h++){
    for(int i = 1 ; i <= n - h ;i++){
      dp[i][i + h] = dp[i][i + h - 1] ^ (dp[i + 1][i + h]);
    }
  }
}

void computenewdp(){
  for(int h = 1 ; h < n ;h++){
    for(int i = 1 ; i <= n - h ;i++){
      int j = i + h;
      if(dp[i][j] < dp[i][j - 1])
        dp[i][j] = dp[i][j - 1];
      if(dp[i][j] < dp[i + 1][j])
        dp[i][j] = dp[i + 1][j];
    }
  }
}

int main()
{
  cin >> n;
  for(int i = 1 ; i <= n ;i++)
    cin >> v[i];
  computedp();
  computenewdp();

  int q;
  cin >> q;
  for(int i = 1 ;i <= q ;i++){
    int x , y;
    cin >> x >> y;
    cout << dp[x][y] << '\n';
  }
  return 0;
}