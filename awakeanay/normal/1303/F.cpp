/*
Author: AwakeAnay
Date: 12/02/2020
Time: 21:01:18
*/

#include <iostream>
#include <vector>

#define MAX 5000000

int n, m, q;
std::vector<int> Adj[MAX];
int col[MAX];
int par[MAX];
int id[MAX];

inline int conv(int i, int j) {
  return i*m + j;
}

int root(int u) {
  if(par[u] < 0)
    return u;
  return par[u] = root(par[u]);
}

void merge(int u, int v) {
  u = root(u);
  v = root(v);
  
  if(u == v)
    return;

  if(par[u] < par[v])
    u ^= v ^= u ^= v;

  par[u] += par[v];
  par[v] = u;
}

int main() {
  scanf("%d %d %d", &n, &m, &q);

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      int u = conv(i, j);
      
      if(i) {
        int v = conv(i-1, j);
        Adj[u].push_back(v);
        Adj[v].push_back(u);
      }

      if(j) {
        int v = conv(i, j-1);
        Adj[u].push_back(v);
        Adj[v].push_back(u);
      }
    }
  }
  
  std::vector<std::pair<int, int> > rev(q);
  std::vector<int> change(q, 0);

  int next = 0;
  for(int i = 0; i < q; i++) {
    int x, y, c;
    scanf("%d %d %d", &x, &y, &c);
    //x = y = 1; c = i;
    x--; y--;
    int u = conv(x, y);

    rev[i] = {u, col[u]};
    col[u] = c;
    id[u] = next++;
    par[id[u]] = -1;
    
    for(int j : Adj[u]) {
      if(col[j] == col[u] && root(id[j]) != root(id[u])) {
        change[i]--;
        merge(id[j], id[u]);
        //std::cout << j << " " << u << std::endl;
      }
    }
  }
  
  for(int i = 0; i < MAX; i++) {
    par[i] = -1;
  }

  next = 0;
  for(int i = 0; i < n*m; i++)
    id[i] = next++;

  for(int i = 0; i < n*m; i++) {
    for(int j : Adj[i])
      if(col[i] == col[j])
        merge(id[i], id[j]);
  }

  for(int i = q-1; i >= 0; i--) {
    int u = rev[i].first;
    col[u] = rev[i].second;
    id[u] = next++;
    par[id[u]] = -1;

    for(int j : Adj[u]) {
      if(col[j] == col[u] && root(id[j]) != root(id[u])) {
        change[i]++;
        merge(id[j], id[u]);
      }
    }
  }
  
  int cur = 1;
  for(int i = 0; i < q; i++) {
    cur += change[i];
    printf("%d\n", cur);
  }

  return 0;
}