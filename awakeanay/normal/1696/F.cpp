#include <iostream>
#include <set>
#include <vector>

const int MAXN = 105;

int dst[MAXN][MAXN];
bool d[MAXN][MAXN][MAXN];
int vis[MAXN];
int n;

std::set<std::pair<int, int> > edges;

bool check() {
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      dst[i][j] = (i == j) ? 0 : n+1;
  for(auto j : edges) {
    dst[j.first][j.second] = 1;
  }
  if(edges.size() != 2*(n-1))
    return false;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      for(int k = 0; k < n; k++)
        dst[j][k] = std::min(dst[j][k], dst[j][i] + dst[i][k]);
  bool poss = true;
  for(int i = 0; i < n; i++)
    for(int j = i+1; j < n; j++)
      for(int k = 0; k < n; k++)
        poss &= (dst[i][k] == dst[j][k]) == (d[i][j][k]);
  return poss;
}

void dfs(int u, int p) {
  edges.insert({u, p});
  edges.insert({p, u});
  vis[u] = vis[p] = 1;

  for(int j = 0; j < n; j++) {
    if(vis[j])
      continue;
    if(d[p][j][u])
      dfs(j, u);
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    std::cin >> n;

    for(int i = 0; i+1 < n; i++) {
      for(int j = 1; j <= n-i-1; j++) {
        std::string s;
        std::cin >> s;
        for(int k = 0; k < n; k++) {
          d[i][i+j][k] = d[i+j][i][k] = s[k] == '1';
        }
      }
    }

    bool poss = false;
    for(int i = 1; i < n; i++) {
      edges.clear();
      for(int j = 0; j < n; j++)
        vis[j] = false;
      dfs(0, i);
      dfs(i, 0);
      if(check()) {
        poss = true;
        std::cout << "Yes" << std::endl;
        for(auto j : edges) {
          if(j.first < j.second)
            std::cout << j.first+1 << " " << j.second+1 << "\n";
        }
        break;
      }
    }


    if(!poss) {
      std::cout << "No" << std::endl;
    }
  }

  return 0;
}