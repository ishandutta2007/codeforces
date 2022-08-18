#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX_N = 1e5 + 5;

#define x first
#define y second

template<typename T>
using ipq = priority_queue<T, vector<T>, greater<T>>;

typedef long long ll;

map<pair<int, int>, int> idx;
vector<pair<int, ll>> adj [MAX_N]; // <oth, weight>
ll dist [MAX_N];

void add_edge (int u, int v, ll w) {
  adj[u].push_back(make_pair(v, w));
  adj[v].push_back(make_pair(u, w));
}

bool byy (pair<int, int> p, pair<int, int> q) {
  if (p.y != q.y) return p.y < q.y;
  return p < q;
}

ll xs [MAX_N], ys [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  int sx, sy, fx, fy;
  cin >> sx >> sy >> fx >> fy;

  vector<pair<int, int>> points;
  for (int i = 0; i < m; i++) {
    cin >> xs[i] >> ys[i];

    idx[{xs[i], ys[i]}] = i;
    points.push_back(make_pair(xs[i], ys[i]));
  }

  sort(points.begin(), points.end()); // by x
  for (int i = 0; i < m - 1; i++) {
    auto cur = points[i], nxt = points[i + 1];
    add_edge(idx[cur], idx[nxt], nxt.x - cur.x);
  }

  sort(points.begin(), points.end(), byy);
  for (int i = 0; i < m - 1; i++) {
    auto cur = points[i], nxt = points[i + 1];
    add_edge(idx[cur], idx[nxt], nxt.y - cur.y);
  }

  for (auto p : points) {
    dist[idx[p]] = min(abs(sx - p.x), abs(sy - p.y));
  }

  ipq<pair<ll, int>> PQ;
  for (int i = 0; i < m; i++) {
    PQ.push(make_pair(dist[i], i));
  }

  while (!PQ.empty()) {
    auto qtop = PQ.top();
    PQ.pop();

    int cur = qtop.second;

    if (dist[cur] != qtop.first) {
      continue;
    }

    for (auto pr : adj[cur]) {
      int nxt = pr.first;
      ll w = pr.second;
      if (dist[cur] + w < dist[nxt]) {
        dist[nxt] = dist[cur] + w;
        PQ.push(make_pair(dist[nxt], nxt));
      }
    }
  }

  ll ans = abs(fx - sx) + abs(fy - sy);
  for (int i = 0; i < m; i++) {
    ans = min(ans, dist[i] + abs(fx - xs[i]) + abs(fy - ys[i]));
  }
  cout << ans << endl;
}