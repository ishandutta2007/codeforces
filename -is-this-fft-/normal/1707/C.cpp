#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5;
const int MAX_LG = 20;

int root [MAX_N];

int find (int u) {
  if (root[u] != u) {
    root[u] = find(root[u]);
  }
  return root[u];
}

void merge (int u, int v) {
  u = find(u);
  v = find(v);

  root[u] = v;
}

vector<int> adj [MAX_N];

int sta [MAX_N];
int fin [MAX_N];
int lvl [MAX_N];
int jmp [MAX_N][MAX_LG];

void dfs (int u, int p, int &cur) {
  cur++;
  sta[u] = cur;

  lvl[u] = lvl[p] + 1;
  jmp[u][0] = p;
  for (int k = 1; k < MAX_LG; k++) {
    jmp[u][k] = jmp[jmp[u][k - 1]][k - 1];
  }

  for (int nxt : adj[u]) {
    if (nxt != p) {
      dfs(nxt, u, cur);
    }
  }

  fin[u] = cur;
}

int go_up (int u, int diff) {
  for (int k = 0; k < MAX_LG; k++) {
    if (diff & 1 << k) {
      u = jmp[u][k];
    }
  }
  return u;
}

int ans [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    root[i] = i;
  }

  vector<pair<int, int>> cross;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    if (find(u) != find(v)) {
      adj[u].push_back(v);
      adj[v].push_back(u);

      merge(u, v);
    } else {
      cross.push_back({u, v});
    }
  }

  int cur_dfs = 0;
  dfs(1, 0, cur_dfs);

  for (auto e : cross) {
    int u = e.first;
    int v = e.second;

    if (sta[u] > sta[v]) {
      swap(u, v);
    }

    // now sta[u] <= sta[v]
    if (fin[v] <= fin[u]) {
      // u ancestor of v
      ans[sta[1]]++;
      ans[fin[1] + 1]--;

      int w = go_up(v, lvl[v] - lvl[u] - 1);
      ans[sta[w]]--;
      ans[fin[w] + 1]++;

      ans[sta[v]]++;
      ans[fin[v] + 1]--;
    } else {
      ans[sta[u]]++;
      ans[fin[u] + 1]--;

      ans[sta[v]]++;
      ans[fin[v] + 1]--;
    }
  }

  for (int i = 1; i < MAX_N; i++) {
    ans[i] += ans[i - 1];
  }

  for (int i = 1; i <= n; i++) {
    cout << (ans[sta[i]] == (int) cross.size());
  }
  cout << '\n';
}