#include <iostream>
#include <map>

#define int long long

signed main() {
  int n, m;
  std::cin >> n >> m;
  m--;

  int a[n];
  for(int i = 0; i < n; i++) {
    std::cin >> a[i];
    a[i]--;
  }

  std::map<int, int> mp;
  int ans = 0;

  mp[0] = 1;
  int cur = 0;
  bool poss = false;
  for(int i = 0; i < n; i++) {
    cur += (a[i] > m);
    cur -= (a[i] <= m);

    if(a[i] == m)
      poss = true;

    //std::cout << cur << " " << poss << " " << mp[-cur] << " " << mp[-cur-1] << std::endl;

    if(poss) ans += mp[-cur] + mp[-cur-1];
    else mp[-cur]++;
  }

  std::cout << ans << std::endl;

  return 0;
}