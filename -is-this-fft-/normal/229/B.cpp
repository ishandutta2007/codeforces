#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

template<typename T>
using ipq = priority_queue<T, vector<T>, greater<T>>;

const int INF = 2e9 + 5;
const int MAX_N = 1e5 + 5;

struct Edge {
  int to, cost;

  Edge (int _to = 0, int _cost = 0) : to(_to), cost(_cost) {}
};

vector<Edge> adj [MAX_N];
set<int> bans [MAX_N];
int dist [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    adj[u].push_back(Edge(v, w));
    adj[v].push_back(Edge(u, w));
  }

  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;

    for (int j = 0; j < k; j++) {
      int x;
      cin >> x;
      
      bans[i].insert(x);
    }
  }

  for (int i = 1; i <= n; i++) {
    dist[i] = INF;
  }

  ipq<pair<int, int>> PQ; // <dist, vtx>
  dist[1] = 0;
  PQ.push(make_pair(dist[1], 1));

  while (!PQ.empty()) {
    auto pr = PQ.top();
    PQ.pop();

    if (pr.first != dist[pr.second]) {
      continue;
    }

    int cur = pr.second;
    int sta = dist[cur];
    while (bans[cur].count(sta)) {
      sta++;
    }

    for (auto e : adj[cur]) {
      int nxt = e.to;
      int t = sta + e.cost;

      if (t < dist[nxt]) {
        dist[nxt] = t;
        PQ.push(make_pair(dist[nxt], nxt));
      }
    }
  }

  int ans = dist[n];
  if (ans == INF) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}