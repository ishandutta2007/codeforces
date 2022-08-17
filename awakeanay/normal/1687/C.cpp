#include <iostream>
#include <queue>
#include <map>
#include <set>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    int last = 0;
    int cur = 0;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    std::set<std::pair<int, int> > zeroes;
    int vis = 0;

    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      a[i] -= x;
      cur += a[i];
      if(cur == 0) {
        if(i > last) {
          zeroes.insert({last, i});
        }
        last = i+1;
      }
    }

    int l[m], r[m];
    std::vector<int> deg(m, 0);
    std::vector<int> Adj[n];

    std::queue<int> q;
    for(int i = 0; i < m; i++) {
      std::cin >> l[i] >> r[i];
      l[i]--; r[i]--;
      auto it = zeroes.upper_bound({r[i], n});
      if(it != zeroes.begin()) {
        it--;
        if((*it).second > r[i]) {
          deg[i]++;
          Adj[(*it).first].push_back(i);
        }
      }
      it = zeroes.lower_bound({l[i], -1});
      if(it != zeroes.begin()) {
        it--;
        if((*it).second >= l[i]) {
          deg[i]++;
          Adj[(*it).first].push_back(i);
        }
      }
      if(deg[i] == 0)
        q.push(i);
    }

    /*
    for(auto j : zeroes) {
      std::cout << j.first << " " << j.second << std::endl;
    }
    */

    while(!q.empty()) {
      int u = q.front();
      q.pop();

      while(true) {
        auto it = zeroes.lower_bound({l[u], -1});
        if(it == zeroes.end() || (*it).first > r[u])
          break;
        int v = (*it).first;
        for(int j : Adj[v]) {
          deg[j]--;
          if(deg[j] == 0)
            q.push(j);
        }
        zeroes.erase(it);
      }
    }

    if(cur != 0) {
      std::cout << "NO" << std::endl;
      continue;
    }


    std::cout << (zeroes.empty() ? "YES" : "NO") << std::endl;
  }

  return 0;
}