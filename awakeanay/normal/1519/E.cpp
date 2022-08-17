#include <iostream>
#include <map>
#include <vector>
#include <set>

#define int long long

const int MAXN = 400005;

std::vector<std::pair<int, int> > Adj[MAXN];
std::vector<int> dir[MAXN];
std::map<std::pair<int, int>, int> mpn;
int vis[MAXN];
int nc = 0;

int gcd(int a, int b) {
  if(a == 0)
    return b;
  return gcd(b%a, a);
}

int get(std::pair<int, int> x) {
  int gc = gcd(x.first, x.second);
  x.first /= gc;
  x.second /= gc;
  if(mpn[x])
    return mpn[x]-1;
  mpn[x] = nc+1;
  nc++;
  return mpn[x]-1;
}

void dfs(int u, int p) {
  vis[u] = 1;
  for(auto j : Adj[u]) {
    if(j.second == p || vis[j.first] == 2)
      continue;
    if(vis[j.first]) {
      dir[u].push_back(j.second);
    }
    else {
      dfs(j.first, j.second);
      if(dir[j.first].size()%2)
        dir[j.first].push_back(j.second);
      else
        dir[u].push_back(j.second);
    }
  }
  vis[u] = 2;
}

signed main() {
  int n;
  std::cin >> n;

  for(int i = 0; i < n; i++) {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    std::pair<int, int> n1 = {(a+b)*d, c*b};
    std::pair<int, int> n2 = {a*d, (c+d)*b};

    int v1 = get(n1);
    int v2 = get(n2);

    Adj[v1].push_back({v2, i+1});
    Adj[v2].push_back({v1, i+1});
  }

  for(int i = 0; i < nc; i++) {
    if(!vis[i])
      dfs(i, -1);
  }

  int ans = 0;
  for(int i = 0; i < nc; i++)
    ans += dir[i].size()/2;

  std::cout << ans << std::endl;
  for(int j = 0; j < nc; j++) {
    for(int i = 0; i+1 < dir[j].size(); i+=2) 
      std::cout << dir[j][i] << " " << dir[j][i+1] << std::endl;
  }

  return 0;
}