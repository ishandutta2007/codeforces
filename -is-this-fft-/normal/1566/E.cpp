#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 5;

vector<int> adj [MAX_N];

// 1 - root, 2 - leaf
int calc_dp (int u, int p, int &ans) {
  int leafc = 0;
  for (int nxt : adj[u]) {
    if (nxt == p) continue;
    int ndp = calc_dp(nxt, u, ans);
    if (ndp == 2) {
      leafc++;
    }
  }

  if (leafc == 0) {
    return 2;
  } else {
    ans += leafc - 1;
    return 1;
  }
}

void solve () {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    adj[i].clear();
  }

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int ans = 0;
  calc_dp(1, 0, ans);
  cout << ans + 1 << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}