#include <iostream>

using namespace std;
int const nmax = 100000;
int const modulo = 1000000007;

int v[5 + nmax];
int v2[5 + nmax];
int dp[5 + nmax][2];
///number of solution in which v <= v2 with the first (i - 1) elements unprocessed
///                            v2 < v
void update(int j){
  if(v[j] != v2[j]){
    dp[j][(v2[j] < v[j])] += dp[j + 1][0] + dp[j + 1][1];
    if(modulo <= dp[j][(v2[j] < v[j])] ){
      dp[j][(v2[j] < v[j])] -= modulo;
    }
  } else{
    dp[j][0] += dp[j + 1][0];
    dp[j][1] += dp[j + 1][1];
    if(modulo <= dp[j][0])
      dp[j][0] -= modulo;
    if(modulo <= dp[j][1])
      dp[j][1] -= modulo;
  }
}
void gcd(int a , int b , long long &x , long long &y){
  if(b == 0){
    x = 1;
    y = 0;
  } else{
    gcd(b , a % b , x , y);
    long long aux = x;
    x = y;
    y = aux - a / b * y;
  }
}
long long inv(long long a){
  long long x , y;
  gcd(a , modulo , x , y);
  x %= modulo;
  if(x < 0)
    x += modulo;
  return x;
}
int main()
{
  int n , m;
  cin>>n>>m;
  for(int i = 1 ; i <= n ;i++)
    cin>>v[i];
  for(int i = 1 ; i <= n ;i++)
    cin>>v2[i];
  dp[n + 1][0] = 1;
  for(int j = n ; 0 < j ; j--){
    if(0 < v[j] && 0 < v2[j]){
      update(j);
    } else if(0 < v2[j]){
      //cout<<dp[j + 1][0]<<":";
      dp[j][0] = (dp[j + 1][0] + ((1LL * (dp[j + 1][0] + dp[j + 1][1])) * (v2[j] - 1) % modulo)) % modulo;
      dp[j][1] = (dp[j + 1][1] + ((1LL * (dp[j + 1][0] + dp[j + 1][1])) * (m - v2[j]) % modulo)) % modulo;
    } else if(0 < v[j]){
      dp[j][0] = (1LL * dp[j + 1][0] + (1LL * (dp[j + 1][0] + dp[j + 1][1])) * (m - v[j]) % modulo) % modulo;
      dp[j][1] = (1LL * dp[j + 1][1] + (1LL * (dp[j + 1][0] + dp[j + 1][1])) * (v[j] - 1) % modulo) % modulo;
    } else{
      dp[j][0] = (1LL * dp[j + 1][0] * m + (1LL * (dp[j + 1][0] + dp[j + 1][1])) * ((1LL * m * (m - 1) / 2) % modulo)) % modulo;
      dp[j][1] = (1LL * dp[j + 1][1] * m + (1LL * (dp[j + 1][0] + dp[j + 1][1])) * ((1LL * m * (m - 1) / 2) % modulo)) % modulo;
    }
  }
  if(dp[1][1] == 0)
    cout<<0;
  else
    cout<<(inv(dp[1][0] + dp[1][1]) * dp[1][1]) % modulo;
  return 0;
}