#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
long long hashes[N], vtx_hash[2][N];
vector<pair<int, int>> G[2][N];
int atob[N], btoa[N];

vector<int> recently_marked;

bool dfs(int av, int bv) {
  if (atob[av] != -1) {
    return atob[av] == bv;
  }
  if (vtx_hash[0][av] != vtx_hash[1][bv]) return 0;
  recently_marked.push_back(av);
  atob[av] = bv;
  btoa[bv] = av;
  assert(G[0][av].size() == G[1][bv].size());
  for (int i = 0; i < (int)G[0][av].size(); i++) {
    assert(G[0][av][i].first == G[1][bv][i].first);
    if (!dfs(G[0][av][i].second, G[1][bv][i].second)) return 0;
  }
  return 1;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  for (int i = 0; i < N; i++) {
    hashes[i] = rng();
  }
  fill(atob, atob+N, -1);
  fill(btoa, btoa+N, -1);

  int n, m;
  cin >> n >> m;
  for (int z = 0; z < 2; z++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int x;
        cin >> x;
        if (x) {
          G[z][i].emplace_back(x, j+n);
          G[z][j+n].emplace_back(x, i);
          vtx_hash[z][i] ^= hashes[x];
          vtx_hash[z][j+n] ^= hashes[x];
        }
      }
    }
    for (int v = 0; v < n+m; v++) {
      sort(G[z][v].begin(), G[z][v].end());
    }
  }

  recently_marked.reserve(n+m);

  int low = (n > m ? n : 0);
  int high = (n > m ? n+m : n);
  for (int i = low; i < high; i++) {
    if (atob[i] != -1) continue;
    for (int j = low; j < high; j++) {
      if (btoa[j] != -1) continue;
      if (!dfs(i, j)) {
        for (int x: recently_marked) {
          btoa[atob[x]] = -1;
          atob[x] = -1;
        }
        recently_marked.clear();
      }
      else {
        recently_marked.clear();
        break;
      }
    }
  }

  assert(count(atob, atob+n+m, -1) == count(btoa, btoa+n+m, -1));
  bool ok = 1;
  int x = 0;
  int y = 0;
  while (x < n+m && atob[x] != -1) x++;
  while (y < n+m && btoa[y] != -1) y++;
  while (x < n+m) {
    assert(y < n+m);
    if (vtx_hash[0][x] != 0 || vtx_hash[1][y] != 0) ok = 0;
    atob[x] = y;
    btoa[y] = x;
    x++;
    y++;
    while (x < n+m && atob[x] != -1) x++;
    while (y < n+m && btoa[y] != -1) y++;
  }

  if (!ok) {
    cout << "-1\n";
    return 0;
  }

  vector<tuple<int, int, int>> ans;
  for (int i = 0; i < n+m; i++) {
    int j = btoa[i];
    assert((i<n) == (j<n));
    if (j != i) {
      ans.emplace_back((i>=n)+1, i+1-(i<n ? 0 : n), j+1-(i<n ? 0 : n));
      swap(btoa[i], btoa[atob[i]]);
      swap(atob[i], atob[j]);
    }
  }

  cout << ans.size() << '\n';
  for (tuple<int, int, int>& op: ans) {
    int type, x, y;
    tie(type, x, y) = op;
    cout << type << ' ' << x << ' ' << y << '\n';
  }
}