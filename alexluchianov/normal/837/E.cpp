#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

vector<ll> divisors(ll val){
  vector<ll> primes;

  for(int i = 2; 1LL * i * i <= val; i++){
    if(val % i == 0){
      primes.push_back(i);
      while(val % i == 0)
        val /= i;
    }
  }
  if(1 < val)
    primes.push_back(val);
  return primes;
}

ll f(ll x, ll y){
  if(y == 0)
    return 0;
  else {
    ll d = __gcd(x, y);
    if(1 < d)
      return f(x / d, y / d);
    vector<ll> primes = divisors(x);
    ll nexty = 0;
    for(int i = 0; i < primes.size(); i++)
      nexty = MAX(nexty, y / primes[i] * primes[i]);
    return y - nexty + f(x, nexty);
  }
}
int main()
{
  ll x, y;
  cin >> x >> y;
  cout << f(x, y);
  return 0;
}