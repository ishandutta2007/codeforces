#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N, A, B;
int da, db;
vector <int> adj[MAXN];
int dist;

void load() {
  scanf("%d%d%d%d%d", &N, &A, &B, &da, &db);
  for (int i = 1; i <= N; i++)
    adj[i].clear();
  for (int i = 1; i < N; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
}

void dfs(int x, int p, int d, int &mx, int &opt) {
  if (d > mx) {
    opt = x;
    mx = d;
  }
  for (auto it : adj[x])
    if (it != p)
      dfs(it, x, d + 1, mx, opt);
}

void find_dist(int x, int p, int d) {
  if (x == B)
    dist = d;
  for (auto it : adj[x])
    if (it != p)
      find_dist(it, x, d + 1);
}

bool solve() {
  int diam = 0, farthest = 0;
  dfs(1, 0, 0, diam, farthest);
  dfs(farthest, 0, 0, diam, farthest);
  find_dist(A, 0, 0);
  return da >= min((min(diam, db) + 1) / 2, dist);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    puts(solve() ? "Alice" : "Bob");
  }
  return 0;
}