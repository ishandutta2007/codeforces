#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template<typename T>
using ipq = priority_queue<T, vector<T>, greater<T>>;

const int INF = 1e9 + 5;
const int MAX_N = 2e5 + 5;

vector<int> out [MAX_N];
vector<int> in [MAX_N];

bool active [MAX_N];
int dist [MAX_N];
int bad_out [MAX_N];

ipq<pair<int, int>> Q;

void activate (int u) {
  for (int v : in[u]) {
    bad_out[v]--;
    if (!active[v]) {
      dist[v] = min(dist[v], dist[u] + 1 + bad_out[v]);
      Q.push(make_pair(dist[v], v));
    }
  }

  active[u] = true;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    out[u].push_back(v);
    in[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    dist[i] = INF;
    bad_out[i] = out[i].size();
  }

  dist[n] = 0;
  activate(n);
  while (!Q.empty()) {
    int u = Q.top().second;
    Q.pop();

    if (active[u]) {
      continue;
    }

    activate(u);
  }

  cout << dist[1] << '\n';
}