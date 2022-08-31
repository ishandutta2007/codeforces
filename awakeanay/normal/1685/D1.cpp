#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

const int MAXN = 205;

int rev[MAXN];
int vis[MAXN];
int n;

std::vector<int> dfs(int u) {
  vis[u] = true;
  std::vector<int> ret;
  ret.push_back(u);

  int ct = rev[u];
  while(!vis[ct]) {
    vis[ct] = true;
    ret.push_back(ct);
    ct = rev[ct];
  }

  int sz = ret.size();
  for(int i = sz-1; i >= 0; i--) {
    int u = ret[i];
    if(u+1 < n && !vis[rev[u+1]]) {
      std::vector<int> next = dfs(rev[u+1]);
      ret.insert(ret.begin()+i+1, next.begin(), next.end());
    }
    if(u-1 >= 0 && !vis[rev[u-1]]) {
      std::vector<int> next = dfs(rev[u-1]);
      ret.insert(ret.begin()+i+1, next.begin(), next.end());
    }
  }

  return ret;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    std::cin >> n;

    int p[n];
    for(int i = 0; i < n; i++) {
      vis[i] = false;
      std::cin >> p[i];
      p[i]--;
      rev[p[i]] = i;
    }

    std::vector<int> ans = dfs(0);
    for(int j : ans)
      std::cout << j+1 << " ";
    std::cout << "\n";
  }

  return 0;
}