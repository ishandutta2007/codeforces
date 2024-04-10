#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_N = 100005;

vector<int> adj [MAX_N];
int comp [MAX_N];
int comp_sz [MAX_N];

void dfs (int vertex, int _comp) {
  comp[vertex] = _comp;
  comp_sz[_comp]++;

  for (int nxt : adj[vertex]) {
    if (comp[nxt] == 0) {
      dfs(nxt, _comp);
    }
  }
}

int main () {
  ios::sync_with_stdio(false);

  int vertexc, edgec, mod;
  cin >> vertexc >> edgec >> mod;
  
  for (int i = 0; i < edgec; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<ll> sz_vec;
  for (int i = 1; i <= vertexc; i++) {
    if (comp[i] == 0) {
      dfs(i, i);
      sz_vec.push_back(comp_sz[i]);
    }
  }

  if ((int) sz_vec.size() == 1) {
    cout << 1 % mod << endl;
    return 0;
  }

  ll ans = 1;
  for (ll u : sz_vec) {
    ans *= u;
    ans %= mod;
  }

  ll sz_sum = 0;
  for (ll u : sz_vec) {
    sz_sum += u;
    sz_sum %= mod;
  }

  for (int i = 0; i < (int) sz_vec.size() - 2; i++) {
    ans *= sz_sum;
    ans %= mod;
  }

  cout << ans << endl;
}