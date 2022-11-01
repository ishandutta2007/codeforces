#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

vector <int> g[N];
int n, m, p[N], in[N], out[N], ptr, h[N];

void go (int u = 1, int par = 1, int far = 0) {
  p[u] = par, in[u] = ++ptr, h[u] = far;
  for (int v : g[u]) if (v ^ par) go(v, u, far + 1);
  out[u] = ptr;
}

int main() {
  cin >> n >> m;
  for (int i = 1, u, v; i < n; ++i) {
    scanf("%d %d", &u, &v);
    g[u].emplace_back(v), g[v].emplace_back(u);
  }
  go();
  while (m--) {
    int sz;
    scanf("%d", &sz);
    vector <int> vec(sz);
    for (int i = 0; i < sz; ++i) {
      scanf("%d", &vec[i]);
      vec[i] = p[vec[i]];
    }
    sort(vec.begin(), vec.end(), [] (int u, int v) {
      return h[u] < h[v];
    });
    bool good = 1;
    for (int i = 0; i + 1 < vec.size(); ++i) {
      int u = vec[i], v = vec[i + 1];
      if (!(in[u] <= in[v] and in[v] <= out[u])) {
        good = 0; break;
      }
    }
    puts(good ? "YES" : "NO");
  }
  return 0;
}