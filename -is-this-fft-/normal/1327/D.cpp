#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 5;

int perm [MAX_N];
int vis [MAX_N];
int color [MAX_N];

bool has_path (vector<int> &cyc, int s, int d) {
  for (int i = s; i < (int) cyc.size(); i += d) {
    if (color[cyc[i]] != color[cyc[s]]) return false;
  }
  return true;
}

bool has_path (vector<int> &cyc, int d) {
  for (int s = 0; s < d; s++) {
    if (has_path(cyc, s, d)) return true;
  }
  return false;
}

void proc_cyc (int u, int &ans) {
  vector<int> cyc;
  int cur = u;
  do {
    vis[cur] = 1;
    cyc.push_back(cur);
    cur = perm[cur];
  } while (cur != u);

  int k = cyc.size();
  for (int d = 1; d * d <= k; d++) {
    if (k % d == 0) {
      if (has_path(cyc, d)) ans = min(ans, d);
      if (has_path(cyc, k / d)) ans = min(ans, k / d);
    }
  }
}

void solve () {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> perm[i];
  }

  for (int i = 1; i <= n; i++) {
    cin >> color[i];
  }

  int ans = n;
  for (int i = 1; i <= n; i++) {
    vis[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      proc_cyc(i, ans);
    }
  }

  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;
  for (int t = 1; t <= testc; t++) {
    solve();
  }
}