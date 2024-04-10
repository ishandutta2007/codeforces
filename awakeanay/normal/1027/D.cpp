#include <iostream>
#include <vector>

#define int long long

signed main() {
  int n;
  std::cin >> n;

  int c[n];
  int a[n];
  for(int i = 0; i < n; i++)
    std::cin >> c[i];
  for(int i = 0; i < n; i++) {
    std::cin >> a[i];
    a[i]--;
  }

  std::vector<int> vis(n, 0);
  int ans = 0;
  for(int i = 0; i < n; i++) {
    if(vis[i])
      continue;

    int cur = i;
    vis[cur] = i+1;

    while(!vis[a[cur]]) {
      vis[a[cur]] = i+1;
      cur = a[cur];
    }

    cur = a[cur];
    if(vis[cur] != i+1)
      continue;

    int add = c[cur];
    vis[cur] = 2*n+5;
    while(vis[a[cur]] != 2*n+5) {
      vis[a[cur]] = 2*n+5;
      add = std::min(add, c[a[cur]]);
      cur = a[cur];
    }

    ans += add;
  }

  std::cout << ans << std::endl;

  return 0;
}