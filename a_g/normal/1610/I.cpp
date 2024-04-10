#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+5;
vector<int> children[N];
int parent[N];
int val[N];
vector<int> adj[N];
int dead_edges;
int nimval;
bool contributor[N];
bool live[N];

void toggle(int v) {
  contributor[v] = 1-contributor[v];
  nimval ^= val[v];
}

void dfs(int v, int p) {
  parent[v] = p;
  for (int u: adj[v]) {
    if (u != p) {
      children[v].push_back(u);
      dfs(u, v);
      val[v] ^= val[u];
    }
  }
  val[v]++;
}

void ground(int v) {
  if (!live[v]) return;
  live[v] = 0;
  for (int u: children[v]) {
    if (live[u]) toggle(u);
  }
  if (parent[v] != v) dead_edges++;
  if (contributor[v]) toggle(v);
  ground(parent[v]);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 1);

  for (int i = 1; i <= n; i++) {
    live[i] = 1;
  }

  for (int i = 1; i <= n; i++) {
    ground(i);
    cout << (nimval^(dead_edges&1) ? '1' : '2');
  }
  cout << '\n';
}