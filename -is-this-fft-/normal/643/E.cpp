#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int MAX_N = 5e5 + 5;
const int BLOCK = 75;

vector<int> adj [MAX_N]; // children
int par [MAX_N];
double dp [MAX_N][BLOCK];

int vertexc;
void recalc (int vertex) {
  if (adj[vertex].empty()) {
    dp[vertex][0] = 1;
    for (int i = 1; i < BLOCK; i++) {
      dp[vertex][i] = 0;
    }
  } else {
    dp[vertex][0] = 1;
    for (int i = 1; i < BLOCK; i++) {
      dp[vertex][i] = 1;
      for (int nxt : adj[vertex]) {
        dp[vertex][i] *= (1 - dp[nxt][i - 1] / 2);
      }
      dp[vertex][i] = 1 - dp[vertex][i];
    }
  }
}

double exp_score (int vertex) {  
  double ans = 0;
  for (int i = 0; i < BLOCK - 1; i++) {
    ans += i * (dp[vertex][i] - dp[vertex][i + 1]);
  }
  return ans;
}

void add_vertex (int _parent) {
  vertexc++;
  int u = vertexc;
  par[u] = _parent;
  adj[par[u]].push_back(u);

  recalc(u);
  double oldp = dp[par[u]][1];
  int dir = par[u];

  dp[par[u]][1] = 1 - dp[par[u]][1];
  dp[par[u]][1] *= (1.0 - 1.0 / 2);
  dp[par[u]][1] = 1 - dp[par[u]][1];

  if (par[u] == 1) return;
  for (int i = 2, v = par[par[u]]; i < BLOCK; i++, v = par[v]) {
    double nold = dp[v][i];
    dp[v][i] = 1 - dp[v][i];
    dp[v][i] /= (1 - oldp / 2);
    dp[v][i] *= (1 - dp[dir][i - 1] / 2);
    dp[v][i] = 1 - dp[v][i];

    if (v == 1) return;
    
    oldp = nold;
    dir = v;
  }
}

int main () {
  ios::sync_with_stdio(false);

  int queryc;
  cin >> queryc;
  vertexc = 1;
  for (int i = 0; i < queryc; i++) {
    int type, v;
    cin >> type >> v;

    if (type == 1) {
      add_vertex(v);
    } else {
      cout << fixed << setprecision(12) << exp_score(v) << '\n';
    }
  }
}