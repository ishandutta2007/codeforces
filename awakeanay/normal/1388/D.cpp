#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define int long long

signed main() {
  int n;
  std::cin >> n;

  int a[n], b[n];
  std::vector<int> deg(n, 0);
  for(int i = 0; i < n; i++)
    std::cin >> a[i];
  for(int i = 0;  i < n; i++) {
    std::cin >> b[i];
    b[i]--;
    if(b[i] >= 0)
      deg[b[i]]++;
  }

  std::vector<int> ans;
  std::vector<int> ans2;
  int count = 0;

  std::queue<int> bfs;
  for(int i = 0; i < n; i++)
    if(deg[i] == 0)
      bfs.push(i);

  while(!bfs.empty()) {
    int u = bfs.front(); bfs.pop();
    count += a[u];
    if(b[u] >= 0) {
      deg[b[u]]--;
      if(deg[b[u]] == 0)
        bfs.push(b[u]);
    }
    if(a[u] >= 0) {
      if(b[u] >= 0)
        a[b[u]] += a[u];
      ans.push_back(u);
    }
    else
      ans2.push_back(u);
  }

  std::cout << count << std::endl;
  for(int j : ans)
    std::cout << j+1 << " ";
  std::reverse(ans2.begin(), ans2.end());
  for(int j : ans2)
    std::cout << j+1 << " ";
  std::cout << std::endl;

  return 0;
}