#include <iostream>
#include <vector>

using namespace std;

void make_path (int u, int v, int len, int &cur, vector<pair<int, int>> &edges) {
  if (u == v) return;

  vector<int> path;
  path.push_back(u);

  for (int i = 0; i < len - 1; i++) {
    path.push_back(cur);
    cur++;
  }

  path.push_back(v);

  for (int i = 0; i < (int) path.size() - 1; i++) {
    edges.push_back({path[i], path[i + 1]});
  }
}

void solve () {
  int n, d12, d23, d31;
  cin >> n >> d12 >> d23 >> d31;

  int a1 = d12 - d23 + d31;
  int a2 = d12 + d23 - d31;
  int a3 = -d12 + d23 + d31;

  if (a1 < 0 || a2 < 0 || a3 < 0 ||
      a1 % 2 || a2 % 2 || a3 % 2) {
    cout << "NO" << '\n';
    return;
  }

  a1 /= 2; a2 /= 2; a3 /= 2;

  int need = 3;
  if (a1 > 0 && a2 > 0 && a3 > 0) {
    need++; // centre
  }

  need += max(0, a1 - 1);
  need += max(0, a2 - 1);
  need += max(0, a3 - 1);
  if (need > n) {
    cout << "NO" << '\n';
    return;
  }

  int cur = 4; // first free
  int mid;
  if (a1 == 0) mid = 1;
  else if (a2 == 0) mid = 2;
  else if (a3 == 0) mid = 3;
  else {
    mid = 4;
    cur++;
  }

  vector<pair<int, int>> edges;
  make_path(1, mid, a1, cur, edges);
  make_path(2, mid, a2, cur, edges);
  make_path(3, mid, a3, cur, edges);

  while (cur <= n) {
    edges.push_back({1, cur});
    cur++;
  }

  cout << "YES" << '\n';
  for (auto e : edges) {
    cout << e.first << " " << e.second << '\n';
  }
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