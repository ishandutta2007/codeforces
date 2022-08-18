#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5;

vector<int> adj [MAX_N];

void find_bob (int u, int p, int da, int B, bool &found) {
  if (u == B) found = 1;
  if (da > 0) {
    for (int nxt : adj[u]) {
      if (nxt != p) {
        find_bob(nxt, u, da - 1, B, found);
      }
    }
  }
}

pair<int, int> farthest (int u, int p) {
  pair<int, int> ans = make_pair(0, u);
  for (int nxt : adj[u]) {
    if (nxt != p) {
      auto pr = farthest(nxt, u);
      pr.first++;
      ans = max(ans, pr);
    }
  }
  return ans;
}

int get_diam () {
  auto pr1 = farthest(1, 0);
  auto pr2 = farthest(pr1.second, 0);
  return pr2.first;
}

void solve () {
  int n, A, B, DA, DB;
  cin >> n >> A >> B >> DA >> DB;

  for (int i = 1; i <= n; i++) {
    adj[i].clear();
  }

  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  bool found_bob = false;
  find_bob(A, 0, DA, B, found_bob);
  if (found_bob) {
    cout << "Alice" << '\n';
    return;
  }

  if (DB >= 2 * DA + 1 && get_diam() >= 2 * DA + 1) {
    cout << "Bob" << '\n';
    return;
  } else {
    cout << "Alice" << '\n';
  }
}

int main () {
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
}