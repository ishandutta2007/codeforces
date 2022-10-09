#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 300000;
int const modulo = 1000000007;

void gcd(int a ,int b , int &x ,int &y){
  if(b == 0){
    x = 1;
    y = 0;
  } else {
    gcd(b , a % b , x , y);
    int aux = x;
    x = y;
    y = aux - a / b * y;
  }
}

int v[5 + nmax];
int frec[5 + nmax];
int fact[5 + nmax];

void computefact(){
  fact[0] = 1;
  for(int i = 1 ; i <= nmax ; i++)
    fact[i] = 1LL * fact[i - 1] * i % modulo;
}

int comb(int n , int k){
  if(n < k)
    return 0;

  int result = 1LL *  fact[k] * fact[n - k] % modulo;

  int x , y;
  gcd(result , modulo , x , y);
  x %= modulo;
  if(x < 0)
    x += modulo;

  return 1LL * fact[n] * x % modulo;
}

ll dp[10][5 + nmax];

int main()
{
  computefact();
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n ;
  cin >> n;
  for(int i = 1 ; i <= n ; i++) {
    cin >> v[i];
    frec[v[i]]++;
  }

  for(int i = 1 ;i <= 7 ; i++) {
    for(int j = 1 ; j <= nmax ; j++){
      int result = 0;
      for(int j2 = j ; j2 <= nmax ; j2 += j)
        result += frec[j2];
      dp[i][j] = comb(result , i);
    }
  }

  for(int i = 1 ; i <= 7 ; i++)
    for(int j = nmax ; 1 <= j ; j--)
      for(int j2 = j * 2 ; j2 <= nmax ; j2 += j) {
        dp[i][j] -= dp[i][j2];
        if(dp[i][j] < 0)
          dp[i][j] += modulo;
      }
  for(int i = 1 ; i <= 7 ; i++) {
    if(0 < dp[i][1]) {
      cout << i;
      return 0;
    }
  }

  cout << -1;
  return 0;
}