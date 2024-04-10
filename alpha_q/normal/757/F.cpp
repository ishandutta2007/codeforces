#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> pii;

const int N = 200010;
const ll INF = 1e17 + 5;

ll d[N];
vector <pii> g[N];
vector <int> dag[N], rev[N];
int n, m, s, deg[N], sub[N], par[N];

int main() {
  cin >> n >> m >> s;
  while (m--) {
    int u, v; ll w;
    scanf("%d %d %lld", &u, &v, &w);
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  for (int i = 1; i <= n; ++i) d[i] = INF;
  priority_queue <pii> pq;
  pq.emplace(0, s), d[s] = 0;
  while (!pq.empty()) {
    int u = pq.top().second; pq.pop();
    for (auto it : g[u]) {
      int v = it.first; ll w = it.second;
      if (d[v] > d[u] + w) d[v] = d[u] + w, pq.emplace(-d[v], v);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (auto it : g[i]) {
      int j = it.first; ll w = it.second;
      if (d[i] + w == d[j]) {
        ++deg[j];
        dag[i].emplace_back(j);
        rev[j].emplace_back(i);
      }
    }
  }
  queue <int> q({s});
  int ans = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    if (u ^ s) {
      int tmp = -1;
      bool own = 0;
      for (int nei : rev[u]) {
        if (nei == s) {
          own = 1; break;
        }
        if (tmp == -1) tmp = par[nei];
        else if (par[nei] != tmp) {
          own = 1; break;
        }
      }
      if (own) par[u] = u, ++sub[u], ans = max(ans, sub[u]);
      else par[u] = tmp, ++sub[tmp], ans = max(ans, sub[tmp]);
    }
    for (int v : dag[u]) {
      --deg[v];
      if (!deg[v]) q.emplace(v);
    }
  }
  cout << ans << '\n';
  return 0;
}