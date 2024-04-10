#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int MAXK = 1e2 + 5;

int N, M, K, S;
vector <int> adj[MAXN];
vector <int> by_type[MAXK];
int dist[MAXN][MAXK];

void load() {
  scanf("%d%d%d%d", &N, &M, &K, &S);
  for (int i = 1; i <= N; i++) {
    int type;
    scanf("%d", &type);
    by_type[type].push_back(i);
  }
  while (M--) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
}

void solve() {
  memset(dist, -1, sizeof dist);
  for (int i = 1; i <= K; i++) {
    queue <int> q;
    for (auto it : by_type[i]) {
      dist[it][i] = 0;
      q.push(it);
    }
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (auto it : adj[x])
        if (dist[it][i] == -1) {
          dist[it][i] = dist[x][i] + 1;
          q.push(it);
        }
    }
  }
  for (int i = 1; i <= N; i++) {
    sort(dist[i] + 1, dist[i] + K + 1);
    printf("%d ", accumulate(dist[i] + 1, dist[i] + S + 1, 0));
  }
  puts("");
}

int main() {
  load();
  solve();
  return 0;
}