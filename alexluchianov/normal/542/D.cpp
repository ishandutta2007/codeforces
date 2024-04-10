#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <map>
#include <unordered_map>
#include <bitset>

using ll = long long;

int const nmax = 1000000;
std::bitset<1 + nmax> ciur;

void computeciur() {
  for(int i = 2;i <= nmax; i++)
    if(ciur[i] == 0)
      for(int j = 2 * i; j <= nmax; j += i)
        ciur[j] = 1;
}

bool isprime(ll number) {
  if(number < 2)
    return false;
  for(int i = 2;1LL * i * i <= number; i++)
    if(number % i == 0)
      return false;
  return true;
}

std::map<ll, ll> mp;

int main() {
  computeciur();
  ll n;
  std::cin >> n;
  std::vector<ll> primes, divs;
  for(int i = 2; i <= nmax; i++) {
    if(ciur[i] == 0)
      primes.push_back(i);
  }
  for(int i = 1; 1LL * i * i <= n; i++) {
    if(n % i == 0) {
      divs.push_back(i);
      divs.push_back(n / i);
      if(isprime(i - 1) == 1)
        primes.push_back(i -1);
      if(isprime(n / i - 1) == 1)
        primes.push_back(n / i - 1);
    }
  }
  

  std::sort(primes.begin(), primes.end());
  primes.erase(std::unique(primes.begin(), primes.end()), primes.end());
  std::sort(divs.begin(), divs.end());
  divs.erase(std::unique(divs.begin(), divs.end()), divs.end());
  
  mp[1] = 1;

  for(int i = 0; i < primes.size(); i++) {
    ll acc = primes[i];
    bool flag = false;
    while(acc + 1 <= n) {
      if(n % (acc + 1) == 0) {
        flag = true;
      }
      if(acc <= (n) / primes[i]) {
        acc *= primes[i];
      } else
        break;
    }
    if(flag == true) {
      for(int j = divs.size() - 1; 0 <= j; j--) {
        acc = primes[i];
        while(acc + 1 <= divs[j]) {
          if(divs[j] % (acc + 1) == 0) { 
            mp[divs[j]] += mp[divs[j] / (acc + 1)];
          }

          if(acc <= (divs[j]) / primes[i]) {
            acc *= primes[i];
          } else
            break;
        }
      }
    }
  }
  std::cout << mp[n] << '\n';
  return 0;
}