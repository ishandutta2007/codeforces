#include <iostream>
#include <set>

using namespace std;

const int MAX_N = 2e5 + 5;

int ans;
set<int> dom [MAX_N];

void add_edge (int u, int v) {
  if (u > v) {
    swap(u, v);
  }

  if (dom[u].empty()) ans--;
  dom[u].insert(v);
}

void del_edge (int u, int v) {
  if (u > v) {
    swap(u, v);
  }

  dom[u].erase(v);
  if (dom[u].empty()) ans++;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  ans = n;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    add_edge(u, v);
  }

  int qc;
  cin >> qc;

  for (int i = 0; i < qc; i++) {
    int type;
    cin >> type;

    if (type == 3) {
      cout << ans << '\n';
    } else {
      int u, v;
      cin >> u >> v;

      if (type == 1) {
        add_edge(u, v);
      } else {
        del_edge(u, v);
      }
    }
  }
}