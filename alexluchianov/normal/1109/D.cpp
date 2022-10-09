#include <iostream>
#include <fstream>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
int const modulo = 1000000007;
int fact[5 + 2 * nmax];

void computefact(){
  fact[0] = 1;
  for(int i = 1; i <= 2 * nmax; i++)
    fact[i] = 1LL * fact[i - 1] * i % modulo;
}

void gcd(int a, int b, int &x, int &y){
  if(b == 0){
    x = 1;
    y = 0;
  } else {
    gcd(b, a % b, x , y);
    int aux = x;
    x = y;
    y = aux - a / b * y;
  }
}

int inv(int val){
  int x, y;
  gcd(val, modulo, x, y);
  x %= modulo;
  if(x < 0)
  x += modulo;
  return x;
}

int comb(int n, int k){
  int result2 = 1LL * fact[k] * fact[n - k] % modulo;
  int x, y;
  gcd(result2 , modulo, x, y);
  x %= modulo;
  if(x < 0)
  x += modulo;
  return 1LL * fact[n] * x % modulo;
}

int lgpow(int a, int b){
  if(b == 0)
    return 1;
  else if(b == 1)
    return a;
  else {
    int result = lgpow(a, b / 2);
    if(b % 2 == 0)
      return 1LL * result * result % modulo;
    else
      return 1LL * result * result % modulo * a % modulo;
  }
}

int repcomb(int n, int k){
  return comb(n + k - 1, k);
}

int solve(int n, int sum){
  sum -= n;
  if(0 <= sum)
    return repcomb(n, sum);
  else
    return 0;
}

int tree(int n, int k){
  if(n == k)
    return 1;
  else
    return 1LL * k * lgpow(n, n - k - 1) % modulo;
}

int main()
{
  computefact();
  int n, m;
  cin >> n >> m;
  int totalresult = 0;
  for(int i = 1 ; i < n ; i++){///size of path
    int result = 1LL * solve(i, m) % modulo * comb(n - 2, i - 1) % modulo * fact[i - 1] % modulo;
    result = 1LL * result * lgpow(m , n - 1 - i) % modulo * tree(n, i + 1) % modulo;
    totalresult += result;
    if(modulo <= totalresult)
      totalresult -= modulo;
  }
  cout << totalresult;
  return 0;
}