#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

vector<ll> getprimes(ll n){
  vector<ll> primes;
  for(int i = 2;1LL * i * i <= n; i++){
    if(n % i == 0){
      primes.push_back(i);
      while(n % i == 0)
        n /= i;
    }
  }
  if(1 < n)
    primes.push_back(n);
  return primes;
}

int main()
{
  ll n;
  cin >> n;
  vector<ll> v = getprimes(n);
  if(1 < v.size() || v.size() == 0)
    cout << 1;
  else
    cout << v[0];
  return 0;
}