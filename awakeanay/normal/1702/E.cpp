#include <iostream>
#include <map>
#include <vector>

#define int long long

const int MAXN = 200005;

int bip = 1;
int vis[MAXN];
std::vector<int> Adj[MAXN];

void dfs(int u, int c) {
  vis[u] = c;
  for(int j : Adj[u]) {
    if(!vis[j])
      dfs(j, 3-c);
    if(vis[j] == vis[u])
      bip = 0;
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::map<int, std::pair<int, int> > mp;
    for(int i = 0; i < n; i++) {
      Adj[i].clear();
      vis[i] = 0;
    }

    bip = 1;
    for(int i = 0; i < n; i++) {
      int a, b;
      std::cin >> a >> b;
      if(mp.find(a) == mp.end()) {
        mp[a] = {i, 1};
      }
      else if(mp[a].second == 2)
        bip = false;
      else {
        mp[a].second = 2;
        int u = mp[a].first;
        Adj[u].push_back(i);
        Adj[i].push_back(u);
      }

      if(mp.find(b) == mp.end()) {
        mp[b] = {i, 1};
      }
      else if(mp[b].second == 2)
        bip = false;
      else {
        mp[b].second = 2;
        int u = mp[b].first;
        Adj[u].push_back(i);
        Adj[i].push_back(u);
      }
    }

    for(int i = 0; i < n; i++) {
      if(!vis[i])
        dfs(i, 1);
    }

    std::cout << (bip ? "YES" : "NO") << "\n";
  }

  return 0;
}