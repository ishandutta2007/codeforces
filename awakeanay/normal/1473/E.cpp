#include <iostream>
#include <set>
#include <vector>

#define int long long

const int MAXN = 200005;
const int INF = 100000000000000000;

std::vector<std::pair<int, int> > Adj[4*MAXN];
std::vector<int> d(4*MAXN, INF);
std::vector<int> done(4*MAXN, 0);
int n;

void dij() {
  d[0] = 0;
  std::set<std::pair<int, int> > best;
  best.insert({0, 0});

  while(!best.empty()) {
    int x = (*best.begin()).second;
    best.erase(best.begin());
    done[x] = true;
    for(std::pair<int, int> j : Adj[x]) {
      if(done[j.first])
        continue;

      int next = d[x] + j.second;
      if(d[j.first] > next) {
        best.erase({d[j.first], j.first});
        d[j.first] = next;
        best.insert({d[j.first], j.first});
      }
    }
  }
}

signed main() {
  int m;
  std::cin >> n >> m;

  for(int i = 0; i < m; i++) {
    int u, v, w;
    std::cin >> u >> v;
    u--; v--;
    std::cin >> w;
    for(int l = 0; l < 2; l++) {
      Adj[u].push_back({v, w});
      Adj[u].push_back({v+3*n, w});
      Adj[u].push_back({v+n, 0});
      Adj[u].push_back({v+2*n, 2*w});
      
      Adj[u+n].push_back({v+3*n, 2*w});
      Adj[u+n].push_back({v+n, w});
      
      Adj[u+2*n].push_back({v+3*n, 0});
      Adj[u+2*n].push_back({v+2*n, w});
      
      Adj[u+3*n].push_back({v+3*n, w});
      u ^= v ^= u ^= v;
    }
  }

  dij();

  for(int i = 1; i < n; i++) {
    std::cout << d[i+3*n] << " ";
  }

  return 0;
}