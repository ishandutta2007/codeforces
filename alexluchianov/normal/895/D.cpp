#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
int const nmax = 1000000;
int const modulo = 1000000007;
char a[5 + nmax];
char b[5 + nmax];
int fact[5 + nmax];
int n;
void precompute(){
  fact[0] = 1;
  for(int i = 1 ; i <= n ;i++){
    fact[i] = (1LL * fact[i - 1] * i ) % modulo;
  }
}
void gcd(int a, int b ,long long &x ,long long &y){
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
int solve(char v[5 + nmax]){
  int frec[30] = {0};
  for(int i = 1 ; i <= n ;i++){
    frec[a[i]]++;
  }
  int result = 0;
  for(int i = 1 ; i <= n;i++){
    int sum2 = 1;
    for(int k = 0 ; k < 26 ;k++){
      sum2 = (1LL * sum2 * fact[frec[k]]) % modulo;
    }

    long long x , y;
    gcd(sum2 , modulo , x , y);
    x %= modulo;
    if(x < 0)
      x += modulo;

    for(int j = 0 ;j < v[i] ;j++){
      if(0 < frec[j]){
        int sum = fact[n - i];
        sum = (1LL * sum * x) % modulo;
        sum = (1LL * sum * frec[j]) % modulo;
        result = (result + sum) % modulo;
      }
    }
    if(0 < frec[v[i]]){
      frec[v[i]]--;
    } else
      break;
  }
  return result;
}
int main()
{
  cin>>(a + 1);
  cin>>(b + 1);
  n = strlen(a + 1);
  precompute();
  for(int i = 1 ; i <= n ;i++){
    a[i] -= 'a';
    b[i] -= 'a';
  }
  cout<<(solve(b) - solve(a) - 1 + modulo) % modulo;
  return 0;
}