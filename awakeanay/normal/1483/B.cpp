#include <iostream>
#include <set>
#include <vector>

#define int long long

int gcd(int a, int b) {
  if(b == 0)
    return a;
  return gcd(b, a%b);
}

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::vector<int> del(n, 0), next(n, 0), seq(n, 0);
    std::set<int> free;
    for(int i = 0; i < n; i++) {
      std::cin >> seq[i];
      next[i] = (i+1)%n;
    }

    for(int i = 0; i < n; i++) {
      if(gcd(seq[i], seq[next[i]]) == 1)
        free.insert(i);
    }

    std::vector<int> ans;

    while(!free.empty()) {
      int u = *free.begin();
      free.erase(free.begin());
      int x = u%n;

      if(del[x])
        continue;

      del[next[x]] = 1;
      ans.push_back(next[x]);
      next[x] = next[next[x]];

      if(gcd(seq[x], seq[next[x]]) == 1)
        free.insert(u+n);
    }

    std::cout << ans.size() << " ";
    for(int j : ans)
      std::cout << j+1 << " ";
    std::cout << std::endl;
  }
  
  return 0;
}