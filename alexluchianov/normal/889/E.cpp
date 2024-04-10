#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <map>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
ll v[5 + nmax];
std::map<ll, ll> mp;

void _insert(ll x, ll y) {
  mp[x] = std::max(mp[x], y);
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  mp[v[1] - 1] = 0;
  v[n + 1] = 1;

  for(int i = 1;i <= n; i++) {
    std::vector<std::pair<ll,ll>> sol2;
    while(0 < mp.size()) {
      std::map<ll, ll>::iterator it = mp.end();
      it--;
      if(v[i + 1] <= it->first) { 
        ll last = it->first - it->first % v[i + 1];
        sol2.push_back({it->first % v[i + 1], last * i + it->second});
        if(0 <= (last - v[i + 1]))
          sol2.push_back({v[i + 1] - 1, (last - v[i + 1]) * i + it->second});
        _insert(it->first % v[i + 1], last * i + it->second);
        _insert(v[i + 1] - 1, (last - v[i + 1]) * i + it->second);
        mp.erase(it);
      } else
        break;
    }
  }
  std::cout << mp[0];
  return 0;
}