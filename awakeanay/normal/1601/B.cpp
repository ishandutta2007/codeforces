#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  int a[n+1], b[n+1];
  for(int i = 0; i < n; i++)
    std::cin >> a[i+1];
  for(int j = 0; j < n; j++) {
    std::cin >> b[j+1];
    b[j+1] += j+1;
  }

  std::vector<int> mark(n+1, 0);
  std::set<int> rem;

  for(int i = 0; i < n; i++)
    rem.insert(i);

  std::vector<int> d(n+1, n+1);
  std::queue<int> bfs;
  d[n] = 0;
  bfs.push(n);
  mark[n] = true;

  std::vector<int> b1(n+1, -1), b2(n+1, -1);

  bool done = false;
  int ans = -1;
  while((!bfs.empty()) && (!done)) {
    int u = bfs.front();
    bfs.pop();

    while(1) {
      auto it = rem.lower_bound(u-a[u]);
      if(it == rem.end() || *it >= u)
        break;
      int v = *it;

      rem.erase(it);

      if(v == 0) {
        ans = u;
        done = true;
        break;
      }

      b1[v] = u;
      if(!mark[b[v]]) {
        b2[b[v]] = v;
        bfs.push(b[v]);
        mark[b[v]] = 1;
      }
    }
  }

  if(ans == -1) {
    std::cout << -1 << std::endl;
    return 0;
  }

  std::vector<int> vec;
  vec.push_back(0);

  int cur = ans;
  while(cur != n) {
    vec.push_back(b2[cur]);
    cur = b1[b2[cur]];
  }

  std::cout << vec.size() << std::endl;
  std::reverse(vec.begin(), vec.end());
  for(int j : vec)
    std::cout << j << " ";
  std::cout << std::endl;

  return 0;
}