#include <iostream>
#include <map>

#define int long long

std::map<int, int> mp;

std::pair<int, int> dig(int x) {
  int len = 0;
  int present = 0;

  while(x > 0) {
    len++;
    present |= (1 << (x%10));
    x /= 10;
  }

  return {len, present};
}

const int INF = 45;

int n;

int solve(int x) {
  if(mp[x])
    return mp[x]-1;

  int ans = 45;
  std::pair<int, int> get = dig(x);

  if(get.first == n) {
    ans = 0;
  }
  else {
    for(int i = 2; i < 10; i++) {
      if((get.second >> i)&1)
        ans = std::min(ans, 1 + solve(x*i));
    }
  }

  mp[x] = ans+1;
  return ans;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cin >> n;
  int x;
  std::cin >> x;

  int ans = solve(x);
  std::cout << (ans == 45 ? -1 : ans) << std::endl;

  return 0;
}