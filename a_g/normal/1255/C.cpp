#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
vector<int> G[N];
int last = -1;
int second_last = -1;

void make_edge(int u, int v) {
  G[u].push_back(v);
  G[v].push_back(u);
}

void dfs(int v) {
  cout << v << " ";
  for (int u: G[v]) {
    if (u == last || u == second_last) continue;
    if (G[v].size() == 2 && G[u].size() != 4) continue;
    if (last == -1 || find(G[u].begin(), G[u].end(), last) != G[u].end()) {
      second_last = last;
      last = v;
      dfs(u);
      return;
    }
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n-2; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    make_edge(a, b);
    make_edge(b, c);
    make_edge(c, a);
  }
  for (int i = 1; i <= n; i++) {
    if (G[i].size() == 2) {
      dfs(i);
      cout << '\n';
      return 0;
    }
  }
}