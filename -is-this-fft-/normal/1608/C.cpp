#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 5;

int x [MAX_N], y [MAX_N];

bool byx (int u, int v) {
  return x[u] < x[v];
}

bool byy (int u, int v) {
  return y[u] < y[v];
}

vector<int> adj [MAX_N];
bool can [MAX_N];

void dfs (int u) {
  if (can[u]) return;
  can[u] = true;

  for (int nxt : adj[u]) {
    dfs(nxt);
  }
}

void solve () {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> x[i];
    adj[i].clear();
    can[i] = false;
  }

  for (int i = 0; i < n; i++) {
    cin >> y[i];
  }

  vector<int> players;
  for (int i = 0; i < n; i++) {
    players.push_back(i);
  }

  sort(players.begin(), players.end(), byx);
  pair<int, int> mxy = make_pair(0, -1);
  for (int u : players) {
    mxy = max(mxy, make_pair(y[u], u));
    adj[mxy.second].push_back(u);
  }

  sort(players.begin(), players.end(), byy);
  pair<int, int> mxx = make_pair(0, -1);
  for (int u : players) {
    mxx = max(mxx, make_pair(x[u], u));
    adj[mxx.second].push_back(u);
  }

  int god = players.back();
  dfs(god);

  for (int i = 0; i < n; i++) {
    cout << can[i];
  }
  cout << '\n';
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