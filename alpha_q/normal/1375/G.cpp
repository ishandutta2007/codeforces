#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, cnt[2];
vector <int> g[N];

void go (int u = 1, int pr = -1, int col = 0) {
  ++cnt[col];
  for (int v : g[u]) if (v ^ pr) go(v, u, col ^ 1);
}

int main() {
  cin >> n;
  for (int i = 1, u, v; i < n; ++i) {
    scanf("%d %d", &u, &v);
    g[u].emplace_back(v), g[v].emplace_back(u);
  }
  go(); cout << min(cnt[0], cnt[1]) - 1 << '\n';
  return 0;
}