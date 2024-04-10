#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
#include <vector>
#include <map>

int n, m, k;

bool match(std::string s, std::string p) {
  for(int i = 0; i < k; i++)
    if(p[i] != '_' && p[i] != s[i])
      return false;
  return true;
}

signed main() {
  std::cin >> n >> m >> k;

  std::map<std::string, int> rev;
  std::string pats[n];
  bool can = true;
  for(int i = 0; i < n; i++) {
    std::cin >> pats[i];
    rev[pats[i]] = i+1;
  }

  std::vector<int> deg(n, 0);
  std::set<int> Adj[n];

  for(int i = 0; i < m; i++) {
    std::string s; int x;
    std::cin >> s >> x;

    x--;

    if(!match(s, pats[x])) {
      std::cout << "NO" << std::endl;
      return 0;
    }

    for(int j = 0; j < (1<<k); j++) {
      std::string t = s;
      for(int i = 0; i < k; i++) {
        if((j >> i)&1)
          t[i] = '_';
      }

      auto it = rev.find(t);
      if(it != rev.end()) {
        int pt = (*it).second-1;
        if(pt != x && !Adj[x].count(pt)) {
          deg[pt]++;
          Adj[x].insert(pt);
        }
      }
    }
  }

  std::queue<int> poss;
  for(int i = 0; i < n; i++) {
    if(deg[i] == 0)
      poss.push(i);
  }

  std::vector<int> ans;
  while(!poss.empty()) {
    int u = poss.front();
    poss.pop();

    ans.push_back(u+1);

    for(int j : Adj[u]) {
      deg[j]--;
      if(deg[j] == 0)
        poss.push(j);
    }
  }

  if(ans.size() < n) {
    std::cout << "NO" << std::endl;
    return 0;
  }

  std::cout << "YES" << std::endl;
  for(int j : ans)
    std::cout << j << " ";
  std::cout << std::endl;

  return 0;
}