#include <iostream>
#include <vector>

using namespace std;

void failure () {
  cout << "No" << '\n';
  exit(0);
}

const int MAX_N = 1e5 + 5;
vector<int> adj [MAX_N];

int prv [MAX_N];
pair<int, int> farthest (int u, int p) { // <dist, vtx>
  pair<int, int> ans = make_pair(0, u);
  prv[u] = p;
  for (int nxt : adj[u]) {
    if (nxt != p) {
      auto pr = farthest(nxt, u);
      pr.first++;
      ans = max(ans, pr);
    }
  }
  return ans;
}

void check_hh (int u, int p, int d, int K, bool &ok) {
  int chc = (int) adj[u].size();
  if (p != 0) chc--;

  if (d == K && chc != 0) {
    ok = false;
    return;
  } else if (d != K && chc < 3) {
    ok = false;
    return;
  }

  for (int nxt : adj[u]) {
    if (nxt != p) {
      check_hh(nxt, u, d + 1, K, ok);
    }
  }
}

int main () {
  ios::sync_with_stdio(false);
  
  int n, K;
  cin >> n >> K;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  auto pr1 = farthest(1, 0);
  auto pr2 = farthest(pr1.second, 0);
  if (pr2.first != 2 * K) failure();
  
  int root = pr2.second;
  for (int i = 0; i < K; i++) {
    root = prv[root];
  }
  
  bool ok = true;
  check_hh(root, 0, 0, K, ok);
  if (ok) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }
}