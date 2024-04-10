#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair <int, int> pii;
 
const int MAXN = 1e5 + 5;
const ll INF = 1e18;
 
struct Line {
  int a;
  ll b;
  ll operator ()(int x) const {
    return (ll)a * x + b;
  }
};
 
bool smaller(Line p, Line q, int x) {
  return p(x) < q(x);
}
 
class LiChao {
  int offset;
  vector <Line> tour;
public:
  LiChao(int n) {
    for (offset = 1; offset <= n; offset *= 2);
    tour.resize(2 * offset, {0, INF});
  }
  void update(int x, int lo, int hi, Line l) {
    int mid = (lo + hi) / 2;
    bool left = smaller(l, tour[x], lo);
    bool middle = smaller(l, tour[x], mid);
    if (middle)
      swap(tour[x], l);
    if (hi - lo == 1)
      return;
    if (left != middle)
      update(2 * x, lo, mid, l);
    else
      update(2 * x + 1, mid, hi, l);
  }
  void update(Line l) {
    update(1, 0, offset, l);
  }
  ll query(int x, int lo, int hi, int pos) const {
    ll curr = tour[x](pos);
    if (hi - lo == 1)
      return curr;
    int mid = (lo + hi) / 2;
    if (pos < mid)
      return min(curr, query(2 * x, lo, mid, pos));
    return min(curr, query(2 * x + 1, mid, hi, pos));
  }
  ll query(int pos) const {
    return query(1, 0, offset, pos);
  }
};
 
int N, M, K;
vector <pii> adj[MAXN];
 
void load() {
  scanf("%d%d%d", &N, &M, &K);
  while (M--) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
}
 
void solve() {
  vector <ll> dist(N + 1, INF);
  dist[1] = 0;
  for (int k = 0; k <= K; k++) {
    if (k) {
      LiChao solver(N);
      for (int i = 1; i <= N; i++)
        solver.update({-2 * i, dist[i] + (ll)i * i});
      for (int i = 1; i <= N; i++)
        dist[i] = solver.query(i) + (ll)i * i;
    }
    auto cmp = [&](int x, int y) -> bool { 
      if (dist[x] != dist[y])
        return dist[x] < dist[y];
      return x < y;
    };
    set <int, decltype(cmp)> curr(cmp);
    for (int i = 1; i <= N; i++)
      curr.insert(i);
    while (!curr.empty()) {
      int best = *curr.begin();
      curr.erase(best);
      for (auto it : adj[best]) {
        ll tmp = dist[best] + it.second;
        if (dist[it.first] > tmp) {
          curr.erase(it.first);
          dist[it.first] = tmp;
          curr.insert(it.first);
        }
      }
    }
  }
  for (int i = 1; i <= N; i++)
    printf("%lld ", dist[i]);
  puts("");
}
 
int main() {
  load();
  solve();
  return 0;
}