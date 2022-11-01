#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200010;

vector <int> g[N];
int n, k, h[N], sub[N], id[N];

void go (int u = 1, int pr = -1, int far = 0) {
  h[u] = far, sub[u] = 1;
  for (int v : g[u]) if (v ^ pr) {
    go(v, u, far + 1);
    sub[u] += sub[v];
  }
}

int main() {
  cin >> n >> k;
  for (int i = 1, u, v; i < n; ++i) {
    scanf("%d %d", &u, &v);
    g[u].emplace_back(v), g[v].emplace_back(u);
  }
  go();
  for (int i = 1; i <= n; ++i) id[i] = i;
  sort(id + 1, id + n + 1, [] (int i, int j) {return h[i] - sub[i] > h[j] - sub[j];});
  long long ans = 0;
  for (int i = 1; i <= k; ++i) ans += h[id[i]] - sub[id[i]] + 1;
  cout << ans << '\n';
  return 0;
}