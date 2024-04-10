#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MAX_V = 200005;

typedef long long ll;

ll nOdds [MAX_V];
ll nEvens [MAX_V];
ll sumOdds [MAX_V];
ll sumEvens [MAX_V];
vector<int> adj [MAX_V];
ll ans;
ll sub;

void solve (int vertex, int parent) {
  nOdds[vertex] = 1;
  sumOdds[vertex] = 1;
  for (int nxt : adj[vertex]) {
    if (nxt != parent) {
      solve(nxt, vertex);
      
      ans += nOdds[vertex] * sumOdds[nxt];
      ans += nOdds[nxt] * sumOdds[vertex];
      // sub += nOdds[nxt] * nOdds[vertex];
      
      ans += nEvens[vertex] * sumOdds[nxt];
      ans += nEvens[nxt] * sumOdds[vertex];
      sub += nEvens[nxt] * nOdds[vertex];

      ans += nOdds[vertex] * sumEvens[nxt];
      ans += nOdds[nxt] * sumEvens[vertex];
      sub += nOdds[nxt] * nEvens[vertex];

      ans += nEvens[vertex] * sumEvens[nxt];
      ans += nEvens[nxt] * sumEvens[vertex];
      // sub += nEvens[nxt] * nEvens[vertex];

      sumOdds[vertex] += sumEvens[nxt] + nEvens[nxt];
      nOdds[vertex] += nEvens[nxt];
      sumEvens[vertex] += sumOdds[nxt] + nOdds[nxt];
      nEvens[vertex] += nOdds[nxt];
    }
  }

  // cout << vertex << " " << nOdds[vertex] << " " << nEvens[vertex] << "  " << ans << " " << sub << endl;
}

int main () {
  int vertexc;
  cin >> vertexc;

  for (int i = 0; i < vertexc - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  solve(1, 1);

  cout << (ans - sub) / 2 << endl;
}