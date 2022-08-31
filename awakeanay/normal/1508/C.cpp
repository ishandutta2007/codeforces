#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>

#define int long long

const int MAXN = 200005;

int par1[MAXN], par2[MAXN];

int root(int u, int par[]) {
  if(par[u] < 0)
    return u;
  return par[u] = root(par[u], par);
}

void merge(int u, int v, int par[]) {
  u = root(u, par);
  v = root(v, par);

  if(u == v)
    return;

  if(par[u] > par[v])
    u ^= v ^= u ^= v;

  par[u] += par[v];
  par[v] = u;
}

signed main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::pair<int, int> > elist1;
  std::vector<std::pair<int, std::pair<int, int> > > elist2;

  int xval = 0;
  for(int i = 0; i < m; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;
    u--; v--;
    elist1.push_back({u, v});
    elist1.push_back({v, u});

    elist2.push_back({w, {u, v}});
    xval ^= w;
  }


  std::sort(elist1.begin(), elist1.end());
  std::sort(elist2.begin(), elist2.end());

  std::set<int> rem;
  for(int i = 0; i < n; i++) {
    par1[i] = par2[i] = -1;
    rem.insert(i);
  }

  while(rem.size()) {
    int u = *rem.begin();
    rem.erase(rem.begin());

    std::queue<int> bq;
    bq.push(u);

    while(!bq.empty()) {
      int i = bq.front();
      bq.pop();

      std::vector<int> toer;
      for(int j : rem) {
        int exist = std::binary_search(elist1.begin(), elist1.end(), std::make_pair(i, j));
        if(!exist) {
          toer.push_back(j);
          merge(i, j, par1);
          bq.push(j);
        }
      }

      for(int j : toer)
        rem.erase(j);
    }
  }

  int mst = 0;
  for(int i = 0; i < m; i++) {
    int u = elist2[i].second.first, v = elist2[i].second.second, w = elist2[i].first;
    if(root(u, par1) != root(v, par1)) {
      mst += w;
      merge(u, v, par1);
      merge(u, v, par2);
    }
  }

  int ans = mst + xval;

  if((n*(n-1))/2 - m >= n)
    ans = mst;

  for(int i = 0; i < m; i++) {
    int u = elist2[i].second.first, v = elist2[i].second.second, w = elist2[i].first;
    if(root(u, par2) != root(v, par2)) {
      ans = std::min(ans, mst + w);
    }
  }

  std::cout << ans << std::endl;

  return 0;
}