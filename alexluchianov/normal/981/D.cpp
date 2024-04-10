#include <iostream>

using namespace std;

#define ll long long

#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 50;
ll const inf = (1LL << 60) - 1;
ll sum[5 + nmax];
bool dp[5 + nmax][5 + nmax];

int n , k;

bool cansolve(ll val){
  for(int i = 0 ; i <= n ;i++)
    for(int j = 0 ; j <= k ;j++)
      dp[i][j] = 0;
  dp[0][0] = 1;
  for(int h = 1 ; h <= k ;h++){
    for(int i = 1; i <= n ;i++){
      for(int j = 0 ; j < i ;j++){
        if(val == ((sum[i] - sum[j]) & val)){
          dp[i][h] |= dp[j][h - 1];
        }
      }
    }
  }
  return dp[n][k];
}

int main()
{
  cin >> n >> k;
  for(int i = 1 ; i <= n ;i++){
    cin >> sum[i];
    sum[i] += sum[i - 1];
  }
  ll x = 0;
  for(ll i = (1LL << 60) ; 0 < i ;i /= 2){
    ll jump = i;
    if(cansolve(x | jump) == 1){
      x |= jump;
    }
  }
  cout << x;
  return 0;
}