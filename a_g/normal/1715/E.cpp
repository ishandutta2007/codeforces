#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
const long long INF = 1e18;
long long dist[N], newdist[N];
bool done[N];
vector<pair<int, int>> G[N];

void dijkstra(int n) {
  fill(done, done+n+1, 0);
  priority_queue<pair<long long, int>> pq;
  for (int i = 1; i <= n; i++) {
    pq.emplace(-dist[i], i);
  }
  while (!pq.empty()) {
    long long d = -pq.top().first;
    int v = pq.top().second;
    pq.pop();
    if (done[v]) continue;
    done[v] = 1;
    for (auto& [u, w]: G[v]) {
      dist[u] = min(dist[u], d+w);
      pq.emplace(-(d+w), u);
    }
  }
}

void fly(int n) {
  fill(newdist, newdist+n+1, INF);
  vector<tuple<int, long long, long long>> lowerhull;
  // (m, b, s) = mx+b is the lowest point starting from s
  for (int i = 1; i <= n; i++) {
    int slope = -2*i;
    long long c = dist[i]+1LL*i*i;
    long long crit_x = 1;
    while (lowerhull.size()) {
      int other_slope = get<0>(lowerhull.back());
      long long other_c = get<1>(lowerhull.back());
      // slope*x+c < other_slope*x+other_c
      crit_x = (c-other_c)/(other_slope-slope);
      while (slope*crit_x+c >= other_slope*crit_x+other_c) crit_x++;
      if (crit_x <= (get<2>(lowerhull.back()))) {
        lowerhull.pop_back();
      }
      else break;
    }
    lowerhull.emplace_back(slope, c, crit_x);
  }
  int sz = (int)lowerhull.size();
  for (int i = 0; i < sz; i++) {
    if (get<2>(lowerhull[i]) > n) break;
    int high = n;
    if (i < sz-1) {
      high = min<long long>(high, get<2>(lowerhull[i+1])-1);
    }
    int slope = get<0>(lowerhull[i]);
    long long c = get<1>(lowerhull[i]);
    for (int j = get<2>(lowerhull[i]); j <= high; j++) {
      dist[j] = min(dist[j], 1LL*(slope+j)*j+c);
    }
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  fill(dist, dist+N, INF);
  dist[1] = 0;
  int n, m, k;
  cin >> n >> m >> k;
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    G[u].emplace_back(v, w);
    G[v].emplace_back(u, w);
  }
  dijkstra(n);
  while (k--) {
    fly(n);
    dijkstra(n);
  }
  for (int i = 1; i <= n; i++) {
    cout << dist[i] << " \n"[i==n];
  }
}