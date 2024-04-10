#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 5;

vector<int> adj [MAX_N];
ll l [MAX_N], r [MAX_N];

ll dfs (int u, int &ans) {
  ll cur = 0;
  for (int nxt : adj[u]) {
    cur += dfs(nxt, ans);
  }

  if (cur < l[u]) {
    ans++;
    cur = r[u];
  } else if (cur > r[u]) {
    cur = r[u];
  }
  return cur;
}

void solve () {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    adj[i].clear();
  }

  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;

    adj[p].push_back(i);
  }

  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
  }

  int ans = 0;
  dfs(1, ans);
  cout << ans << '\n';
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