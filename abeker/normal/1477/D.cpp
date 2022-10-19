#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

int N, M;
vector <pii> input;
vector <vector <int>> adj;
vector <int> deg;

void load() {
  scanf("%d%d", &N, &M);
  input.resize(M);
  for (auto &it : input)
    scanf("%d%d", &it.first, &it.second);
}

void add_edge(int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
  deg[u]++;
  deg[v]++;
}

void build_graph(const vector <pii> &edges) {
  deg = vector <int> (N + 1, 0);
  adj = vector <vector <int>> (N + 1, vector <int> ());
  for (auto it : edges)
    add_edge(it.first, it.second);
}

void output(const vector <int> &v) {
  for (int i = 1; i <= N; i++)
    printf("%d ", v[i]);
  puts("");
}

void solve() {
  vector <bool> done(N + 1);
  vector <bool> neighbour(N + 1);
  vector <pii> complement;
  build_graph(input);
  for (int i = 1; i <= N; i++) {
    if (done[i] || deg[i] == N - 1)
      continue;
    for (auto it : adj[i])
      neighbour[it] = true;
    int mex = 1;
    while (mex == i || neighbour[mex])
      mex++;
    for (auto it : adj[i])
      neighbour[it] = false;
    complement.push_back({i, mex});
    done[i] = done[mex] = true;
  }
  
  vector <pii> stars;
  build_graph(complement);
  for (auto it : complement) 
    if (deg[it.first] > 1 && deg[it.second] > 1) {
      deg[it.first]--;
      deg[it.second]--;
    }
    else 
      stars.push_back(it);
  
  int curr = 1;
  vector <int> p(N + 1), q(N + 1);
  build_graph(stars);
  for (int i = 1; i <= N; i++) {
    bool central = true;
    for (auto it : adj[i])
      central &= deg[it] == 1;
    if (!deg[i])
      p[i] = q[i] = curr++;
    else if (central && !p[i] && !q[i]) {
      p[i] = curr;
      q[i] = curr + deg[i];
      for (int j = 0; j < deg[i]; j++) {
        p[adj[i][j]] = curr + j + 1;
        q[adj[i][j]] = curr + j;
      }
      curr += deg[i] + 1;
    }
  }
  output(p);
  output(q);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    solve();
  }
  return 0;
}