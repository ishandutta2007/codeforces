#include <iostream>

using namespace std;

int const nmax = 1000000;
int const modulo = 1000000007;

int a , b , n;
bool isgood(int k ){
  while(0 < k){
    if(k % 10 != a && k % 10 != b)
      return 0;
    k /= 10;
  }
  return 1;
}
int fact[5 + nmax];

void computefact(){
  fact[0] = 1;
  for(int i = 1 ; i <= n ;i++){
    fact[i] = (1LL * fact[i - 1] * i) % modulo;
  }
}

void gcd(int a , int b ,long long &x ,long long &y){
  if(b == 0){
    x = 1;
    y = 0;
  } else {
    gcd(b , a % b , x , y);
    long long aux = x;
    x = y;
    y = aux - a / b * y;
  }
}
int solve(int c){
  int result = fact[n];
  long long x = 0 , y = 0;
  gcd(fact[c] , modulo , x , y);
  x %= modulo;
  if(x < 0)
    x += modulo;
  result = (1LL * result * x) % modulo;
  gcd(fact[n - c] , modulo , x , y);
  x %= modulo;
  if(x < 0)
    x += modulo;
  result = (1LL * result * x) % modulo;
  return result;
}
int main()
{
  cin >> a >> b >> n;
  computefact();
  int result = 0;
  for(int i = 0 ; i <= n ;i++){
    if(isgood(a * i + (n - i) * b) == 1){
      result += solve(i);
      result %= modulo;
    }
  }
  cout<<result;
  return 0;
}