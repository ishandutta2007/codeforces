#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N, M, Q;
set <int> adj[MAXN];
bool loc_max[MAXN];
int ans;

void recalc(int x) {
  ans -= loc_max[x];
  loc_max[x] = adj[x].empty() || *adj[x].rbegin() < x;
  ans += loc_max[x];
}

void add_edge(int u, int v) {
  adj[u].insert(v);
  adj[v].insert(u);
  recalc(u);
  recalc(v);
}

void remove_edge(int u, int v) {
  adj[u].erase(v);
  adj[v].erase(u);
  recalc(u);
  recalc(v);
}

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; i++)
    recalc(i);
  while (M--) {
    int x, y;
    scanf("%d%d", &x, &y);
    add_edge(x, y);
  }
  scanf("%d", &Q);
  while (Q--) {
    int t;
    scanf("%d", &t);
    if (t == 3)
      printf("%d\n", ans);
    else {
      int x, y;
      scanf("%d%d", &x, &y);
      if (t == 1)
        add_edge(x, y);
      else
        remove_edge(x, y);
    }
  }
  return 0;
}