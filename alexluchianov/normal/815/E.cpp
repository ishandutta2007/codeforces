#include <iostream>
#include <vector>
#include <map>

using ll = long long;

ll slowcount(ll n, ll target) {
  if(n < target)
    return 0;
  ll dist = (n + 1) / 2;
  if(dist < target)
    return 0;
  if(n % 2 == 1) {
    return 1 + 2 * slowcount(n / 2, target);
  } else
    return 1 + slowcount(n / 2 - 1, target) + slowcount(n / 2, target);
}

ll fastcount(ll n, ll target) {
  if(n < target)
    return 0;
  std::map<ll, ll> mp;
  mp[n] = 1;
  ll result = 0;
  while(0 < mp.size()) {
    std::map<ll, ll>::iterator it = mp.end();
    it--;
    ll dist = (it->first + 1) / 2;
    if(dist < target)
      return result;
    
    result += it->second;
    if(it->first % 2 == 1) {
      mp[it->first / 2] += 2 * it->second;
    } else {
      mp[it->first / 2 - 1] += it->second;
      mp[it->first / 2] += it->second;
    }
    mp.erase(it);
  }
  return result;
}

ll findtarget(ll n, ll k, ll target) {
  ll dist = (n + 1) / 2;
  if(dist == target) {
    k--;
    if(k == 0)
      return dist;
  }
  if(n % 2 == 1) {
    ll leftside = (fastcount(n / 2, target) - fastcount(n / 2, target + 1));
    if(k <= leftside)
      return findtarget(n / 2, k, target);
    else
      return dist + findtarget(n / 2, k - leftside, target);
  } else {
    ll leftside = (fastcount(n / 2 - 1, target) - fastcount(n / 2 - 1, target + 1));
    if(k <= leftside)
      return findtarget(n / 2 - 1, k, target);
    else
      return dist + findtarget(n / 2, k - leftside, target);
  }
}

int main() {
  ll n, k;
  std::cin >> n >> k;
  if(k == 1) {
    std::cout << 1 << '\n';
    return 0;
  } else if(k == 2)  {
    std::cout << n << '\n';
    return 0;
  } else {
    k -= 2;
    n -= 2;
  }

  ll x = 0;
  for(ll jump = (1LL << 60); 0 < jump; jump /= 2)
    if(x + jump <= n && k <= fastcount(n, x + jump))
      x += jump;

  k -= fastcount(n, x + 1);
  std::cout << 1 + findtarget(n, k, x) << '\n';

  return 0;
}