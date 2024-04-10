#include <iostream>
#include <vector>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, c;
    std::cin >> n >> c;

    std::vector<int> a(c+1, 0), p(c+1, 0);
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      a[x]++;
    }

    for(int i = 1; i <= c; i++)
      p[i] = p[i-1] + a[i];

    bool poss = true;
    for(int j = 1; j <= c; j++) {
      if(!a[j])
        continue;
      for(int i = 1; i*j <= c; i++) {
        if(a[i])
          continue;

        int u = i*j-1;
        int v = std::min((i+1)*j-1, c);
        if(p[v]-p[u]) {
          poss = false;
        }
      }
    }

    std::cout << (poss ? "Yes" : "No") << std::endl;
  }

  return 0;
}