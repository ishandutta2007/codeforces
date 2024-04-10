#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = (1 << 17) + 5;

vector<int> adj [MAX_N];

const pair<int, int> FAIL = {-1, -1};
// <h, 0> - normal
// <h, i> - special w ans i
// <-1, -1> - failure
pair<int, int> dfs (int u, int p) {
  vector<pair<int, int>> ch;
  for (int nxt : adj[u]) {
    if (p != nxt) {
      ch.push_back(dfs(nxt, u));
    }
  }

  if (ch.size() > 3) return FAIL;
  for (auto pr : ch) {
    if (pr == FAIL) return FAIL;
  }

  if (ch.size() == 3) {
    sort(ch.begin(), ch.end());
    for (auto pr : ch) {
      if (pr.second != 0) return FAIL;
    }

    if (ch[0].first + 1 != ch[2].first) return FAIL;
    if (ch[1].first + 1 != ch[2].first) return FAIL;
    return make_pair(ch[2].first + 1, u);
  }

  if (ch.size() == 2) {
    if (ch[0].first != ch[1].first) return FAIL;
    if (ch[0].second != 0 && ch[1].second != 0) return FAIL;
    return make_pair(ch[0].first + 1, ch[0].second + ch[1].second);
  }

  if (ch.size() == 1) {
    if (ch[0].first == 0 && ch[0].second == 0) return make_pair(1, u);
    return FAIL;
  }

  return make_pair(0, 0);
}

int n;
int subsz [MAX_N];
int centroid [MAX_N];
void calc_subsz (int u, int p) {
  subsz[u] = 1;
  for (int nxt : adj[u]) {
    if (nxt != p) {
      calc_subsz(nxt, u);
      subsz[u] += subsz[nxt];
    }
  }

  centroid[u] = 1;
  if (n - subsz[u] > n / 2) centroid[u] = 0;
  
  for (int nxt : adj[u]) {
    if (nxt != p) {
      if (subsz[nxt] > n / 2) centroid[u] = 0;
    }
  }
}

int main () {
  ios::sync_with_stdio(false);
  
  int k;
  cin >> k;

  n = (1 << k) - 2;
  int m = (1 << k) - 3;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  calc_subsz(1, 1);

  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    if (centroid[i]) {
      // cerr << i << endl;
      pair<int, int> p = dfs(i, i);
      if (p.first != -1 && p.second != 0) {
        ans.push_back(p.second);
      }
    }
  }

  cout << (int) ans.size() << endl;
  for (int u : ans) {
    cout << u << " ";
  }
  cout << endl;
}