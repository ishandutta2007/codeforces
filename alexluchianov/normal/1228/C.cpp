#include <iostream>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000;
int const modulo = 1000000007;

ll lgpow(ll a, ll b){
  if(b == 0)
    return 1;
  else if(b == 1)
    return a;
  else {
    ll result = lgpow(a, b / 2);
    if(b % 2 == 0)
      return 1LL * result * result % modulo;
    else
      return 1LL * result * result % modulo * a % modulo;
  }
}

ll legendre(ll prime, ll n){
  if(prime <= n)
    return n / prime + legendre(prime, n / prime);
  else
    return 0;
}

int main()
{
  ll x, n;
  cin >> x >> n;
  ll result = 1;
  for(int i = 2; i * i <= x; i++){
    if(x % i == 0){
      result = 1LL * result * lgpow(i, legendre(i, n)) % modulo;

      while(x % i == 0)
        x /= i;
    }
  }
  if(1 < x)
    result = 1LL * result * lgpow(x, legendre(x, n)) % modulo;
  cout << result;
  return 0;
}