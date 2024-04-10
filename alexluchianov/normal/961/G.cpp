#include <iostream>

using namespace std;

int const nmax = 200000;
int const modulo = 1000000007;
int fact[5 + nmax];

void computefact(){
  fact[0] = 1;
  for(int i = 1; i <= nmax ;i++)
    fact[i] = (1LL * fact[i - 1] * i) % modulo;
}

void gcd(int a , int b , int &x , int &y){
  if(b == 0){
    x = 1;
    y = 0;
  } else{
    gcd(b , a % b , x , y);
    int aux = x;
    x = y;
    y = aux - a / b * y;
  }
}

int comb(int n , int k){
  int result = fact[n];
  int result2 = (1LL * fact[k] * fact[n - k]) % modulo;
  int x , y;
  gcd(result2 , modulo , x , y);
  x %= modulo;
  if(x < 0)
    x += modulo;
  return (1LL * result * x) % modulo;
}

int lgpow(int a , int b){
  if(b == 0)
    return 1;
  else if(b == 1)
    return a;
  else{
    int result = lgpow(a , b / 2);
    if(b % 2 == 0)
      return 1LL * result * result % modulo;
    else
      return 1LL * result * result % modulo * a % modulo;
  }
}

int stirling(int n ,int k){
  int result = 0;
  for(int i = 1 ; i <= k ;i++){
    result = result + 1LL * lgpow(-1 , k - i) * comb(k , i) % modulo * lgpow(i , n) % modulo;
    result %= modulo;
  }
  if(result < 0)
    result += modulo;
  int x , y;
  gcd(fact[k] , modulo , x , y);
  x %= modulo;
  if(x < 0)
    x += modulo;

  result = (1LL * result * x) % modulo;
  return result;
}
int main()
{
  computefact();
  int n , k;
  cin >> n >> k;
  int sum = 0;
  for(int i = 1 ; i <= n ;i++){
    int a;
    cin >> a;
    sum += a;
    if(modulo <= sum)
      sum -= modulo;
  }

  int result = stirling(n , k) + 1LL * stirling(n - 1 , k) * (n - 1) % modulo;
  cout << (1LL * sum * result) % modulo;

  return 0;
}