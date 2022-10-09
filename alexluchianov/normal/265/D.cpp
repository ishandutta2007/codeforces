#include <iostream>

using namespace std;

#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int dp[5 + nmax];

int query(int n){
  int result = 0;
  for(int i = 2 ; i * i <= n ; i++){
    if(n % i == 0)
      result = MAX(result, dp[i]);
    while(n % i == 0)
      n /= i;
  }
  if(1 < n)
    result = MAX(result , dp[n]);
  return result;
}
void update(int n , int result){
  for(int i = 2 ; i * i <= n ; i++){
    if(n % i == 0)
      dp[i] = MAX(dp[i] , result);
    while(n % i == 0)
      n /= i;
  }
  if(1 < n)
    dp[n] = MAX(dp[n] , result);
}

int main()
{
  int n;
  cin >> n;
  for(int i = 1 ; i <= n ; i++){
    int a;
    cin >> a;
    update(a , query(a) + 1);
  }
  int result = 0;
  for(int i = 1 ; i < nmax ; i++)
    result = MAX(result , dp[i]);
  cout << MAX(1 , result);

  return 0;
}