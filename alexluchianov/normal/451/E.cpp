#include <iostream>

using namespace std;

using ll = long long;

int const nmax = 100000;
int const modulo = 1000000007;

void gcd(int a, int b, int &x, int &y){
  if(b == 0){
    x = 1;
    y = 0;
  } else {
    gcd(b, a % b, x, y);
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

int comb(ll n, int k){
  if(0 <= k && k <= n){
    int result = 1;
    for(ll i = n - k + 1; i <= n; i++)
      result =  1LL * i % modulo * result % modulo;
    for(int i = 1;i <= k; i++)
      result = 1LL * result * inv(i) % modulo;
    return result;
  } else
    return 0;
}

ll v[1 + nmax];

int eval(int k, ll val, int steps){
  if(val < 0)
    return 0;
  if(k == 0){
    return comb(val + steps - 1, steps - 1);
  } else {
    return (modulo + eval(k - 1, val, steps + 1) - eval(k - 1, val - v[k] - 1, steps + 1)) % modulo;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  ll sum = 0;
  cin >> n >> sum;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  cout << eval(n, sum, 0);
  return 0;
}