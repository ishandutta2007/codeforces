#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Edge {
  int from, to, capacity, cost;
};

vector<vector<int>> adj;
vector<map<int, int>> cost, capacity;

const int INF = 1e9;

void shortest_paths(int n, int v0, vector<int>& d, vector<int>& p) {
  d.assign(n, INF);
  d[v0] = 0;
  vector<bool> inq(n, false);
  queue<int> q;
  q.push(v0);
  p.assign(n, -1);

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    inq[u] = false;
    for (int v : adj[u]) {
      if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
        d[v] = d[u] + cost[u][v];
        p[v] = u;
        if (!inq[v]) {
          inq[v] = true;
          q.push(v);
        }
      }
    }
  }
}

bool compare(const Edge& x, const Edge& y) {return x.cost < y.cost;}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, k;
  cin >> n >> k;
  const int p = 1 << n;
  vector<int> payments(p);
  vector<bool> leftside(p, 0);
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < (1 << j); i++) {
      leftside[i+(1<<j)] = 1-leftside[i];
    }
  }

  const int num_edges = (2*n-1)*(k-1)+1;
  vector<Edge> edges;
  for (int i = 0; i < p; i++) {
    cin >> payments[i];
  }
  for (int i = 0; i < p; i++) {
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        int other = i^(1<<j);
        if (leftside[i]) {
          edges.push_back(Edge({i, other, 1, -payments[i]-payments[other]}));
        }
        else {
          edges.push_back(Edge({other, i, 1, -payments[i]-payments[other]}));
        }
      }
      if (edges.size() > 1e5) {
        nth_element(edges.begin(), edges.begin()+num_edges-1, edges.end(), compare);
        edges.resize(num_edges);
        edges.shrink_to_fit();
      }
    }
  }
  nth_element(edges.begin(), edges.begin()+num_edges-1, edges.end(), compare);
  edges.resize(num_edges);
  sort(edges.begin(), edges.end(), compare);

  int players = 0;
  set<int> used_players;
  map<int, int> relabel;
  vector<int> leftlabels;
  vector<int> rightlabels;
  for (Edge e: edges) {
    if (!used_players.count(e.from)) {
      used_players.insert(e.from);
      relabel[e.from] = players+1;
      leftlabels.push_back(players+1);
      players++;
    }
    if (!used_players.count(e.to)) {
      used_players.insert(e.to);
      relabel[e.to] = players+1;
      rightlabels.push_back(players+1);
      players++;
    }
  }
  int N = players + 2; // s = 0, t = players+1

  adj.assign(N, vector<int>());
  cost.assign(N, map<int, int>());
  capacity.assign(N, map<int, int>());
  for (Edge e : edges) {
    adj[relabel[e.from]].push_back(relabel[e.to]);
    adj[relabel[e.to]].push_back(relabel[e.from]);
    cost[relabel[e.from]][relabel[e.to]] = e.cost;
    cost[relabel[e.to]][relabel[e.from]] = -e.cost;
    capacity[relabel[e.from]][relabel[e.to]] = e.capacity;
  }
  for (int i: leftlabels) {
    adj[0].push_back(i);
    adj[i].push_back(0);
    capacity[0][i] = 1;
  }
  for (int i: rightlabels) {
    adj[N-1].push_back(i);
    adj[i].push_back(N-1);
    capacity[i][N-1] = 1;
  }

  int flow = 0;
  int cost = 0;
  vector<int> d, q;
  while (flow < k) {
    shortest_paths(N, 0, d, q);
    if (d[N-1] == INF)
      break;

    // find max flow on that path
    int f = k - flow;
    int cur = N-1;
    while (cur != 0) {
      f = min(f, capacity[q[cur]][cur]);
      cur = q[cur];
    }

    // apply flow
    flow += f;
    cost += f * d[N-1];
    cur = N-1;
    while (cur != 0) {
      capacity[q[cur]][cur] -= f;
      capacity[cur][q[cur]] += f;
      cur = q[cur];
    }
  }

  cout << -cost << endl;
}