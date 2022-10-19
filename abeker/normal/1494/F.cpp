#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e3 + 5;

int N, M;
unordered_set <int> adj[MAXN], tmp[MAXN];

void add_edge(int x, int y) {
  adj[x].insert(y);
  adj[y].insert(x);
}

void remove_edge(int x, int y) {
  adj[y].erase(x);
  adj[x].erase(y);
}

void load() {
  scanf("%d%d", &N, &M);
  while (M--) {
    int x, y;
    scanf("%d%d", &x, &y);
    add_edge(x, y);
  }
}

void euler(int x, vector <int> &curr) {
  while (!tmp[x].empty()) {
    int y = *tmp[x].begin();
    tmp[x].erase(y);
    tmp[y].erase(x);
    euler(y, curr);
  }
  curr.push_back(x);
}

void construct(int x, const vector <int> &v, int y) {
  int edges = 0;
  for (int i = 1; i <= N; i++) {
    edges += adj[i].size();
    tmp[i] = adj[i];
  }
  vector <int> path;
  euler(x, path);
  if (path.size() != edges / 2 + 1)
    return;
  path.push_back(-1);
  for (auto it : v)
    if (it != y) {
      path.push_back(it);
      path.push_back(x);
    }
  printf("%d\n", path.size());
  for (auto it : path)
    printf("%d ", it);
  puts("");
  exit(0);
}

void attempt(int x) {
  int non_adj = 0;
  vector <int> odd;
  for (int i = 1; i <= N; i++)
    if (i != x && adj[i].size() % 2) {
      if (adj[x].count(i))
        odd.push_back(i);
      else
        non_adj++;
    }
  if (non_adj > 1)
    return;
  for (auto it : odd)
    remove_edge(x, it);
  construct(x, odd, 0);
  if (!non_adj)
    for (auto it : odd) {
      add_edge(x, it);
      construct(x, odd, it);
      remove_edge(x, it);
    }
  for (auto it : odd)
    add_edge(x, it);
}

void solve() {
  for (int i = 1; i <= N; i++)
    attempt(i);
  puts("0");
}

int main() {
  load();
  solve();
  return 0;
}