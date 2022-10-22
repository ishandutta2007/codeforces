#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 5;

vector<int> adj [MAX_N];
int par [MAX_N];

int dfs (int u, int maxh, int &cnt) {
  int chm = 0;
  for (int nxt : adj[u]) {
    chm = max(chm, dfs(nxt, maxh, cnt));
  }

  chm++;
  if (chm == maxh && u != 1 && par[u] != 1) {
    cnt++;
    chm = 0;
  }

  return chm;
}

bool can (int K, int maxh) {
  int cnt = 0;
  dfs(1, maxh, cnt);
  return cnt <= K;
}

void solve () {
  int n, K;
  cin >> n >> K;

  for (int i = 1; i <= n; i++) {
    adj[i].clear();
  }

  for (int i = 2; i <= n; i++) {
    cin >> par[i];
    adj[par[i]].push_back(i);
  }

  int ans = 0;
  for (int k = 1 << 20; k != 0; k /= 2) {
    if (!can(K, ans + k)) {
      ans += k;
    }
  }

  cout << 1 + ans << '\n';
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