#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+9;
vector<int> G[N];

int n;

void make_edge(int u, int v) {
  G[u].push_back(v);
  G[v].push_back(u);
}

bool solve() {
  cin >> n;
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    make_edge(u, v);
  }
  string s;
  cin >> s;
  if (count(s.begin(), s.end(), 'W') >= 3) return 1;
  int vtxs = n;
  for (int i = 1; i <= n; i++) {
    if (s[i-1] == 'W') {
      make_edge(i, vtxs+1);
      make_edge(vtxs+1, vtxs+2);
      make_edge(vtxs+1, vtxs+3);
      vtxs += 3;
    }
  }

  n = vtxs;
  int h = 0;
  for (int i = 1; i <= n; i++) {
    if (G[i].size() >= 4) return 1;
    if (G[i].size() == 3) {
      int c = 0;
      for (int v: G[i]) {
        if (G[v].size() > 1) c++;
      }
      if (c >= 2) return 1;
      if (++h >= 3) return 1;
    }
  }
  if (h < 2) return 0;
  return vtxs&1;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cout << (solve() ? "White" : "Draw") << '\n';
    fill(G+1, G+n+1, vector<int>());
  }
}