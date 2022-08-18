#include <iostream>
#include <map>

using namespace std;

const int MAX_N = 1e5 + 5;

class PrefMax {
  map<int, int> tree;

public:
  void add (int idx, int val) {
    idx++;
    for (int i = idx; i < MAX_N; i += i & -i) {
      if (!tree.count(i)) {
        tree[i] = 0;
      }
      tree[i] = max(tree[i], val);
    }
  }

  int get (int idx) {
    idx++;
    if (idx <= 0) return 0;
    int ans = 0;
    for (int i = idx; i > 0; i -= i & -i) {
      if (tree.count(i)) {
        ans = max(ans, tree[i]);
      }
    }
    return ans;
  }
};

PrefMax table [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    table[v].add(w, table[u].get(w - 1) + 1);
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, table[i].get(MAX_N - 1));
  }
  cout << ans << endl;
}