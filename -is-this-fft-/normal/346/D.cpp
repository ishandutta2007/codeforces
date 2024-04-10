#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e6 + 5;
const int INF = 1e9 + 5;

vector<int> in_adj [MAX_N];
int out_deg [MAX_N];

vector<int> Q;
int fdist [MAX_N];

void proc (int u, int gen) {
  fdist[u] = gen;

  for (int prv : in_adj[u]) {
    Q.push_back(prv);
    out_deg[prv]--;

    if (out_deg[prv] == 0 && fdist[prv] == INF) {
      proc(prv, gen);
    }
  }
}

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    out_deg[u]++;
    in_adj[v].push_back(u);
  }

  int s, t;
  cin >> s >> t;

  for (int i = 1; i <= n; i++) {
    fdist[i] = INF;
  }

  Q.push_back(t);
  for (int i = 0; !Q.empty(); i++) {
    auto oldQ = Q;
    Q.clear();

    for (int u : oldQ) {
      if (fdist[u] == INF) {
        proc(u, i);
      }
    }
  }

  cout << (fdist[s] == INF ? -1 : fdist[s]) << endl;
}