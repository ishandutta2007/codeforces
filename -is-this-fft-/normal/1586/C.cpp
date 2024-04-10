#include <iostream>
#include <vector>

using namespace std;

class Segtree {
  int n;
  vector<int> tree, lfend, rgend;

  void update (int u) {
    if (u == 0) return;
    tree[u] = max(tree[2 * u], tree[2 * u + 1]);
    update(u / 2);
  }
  
public:
  Segtree (int _n) {
    n = 1;
    while (n < _n) {
      n *= 2;      
    }

    tree = vector<int> (2 * n, 0);
    lfend = vector<int> (2 * n);
    rgend = vector<int> (2 * n);

    for (int i = n; i < 2 * n; i++) {
      lfend[i] = i - n;
      rgend[i] = i - n;
    }

    for (int i = n - 1; i > 0; i--) {
      lfend[i] = lfend[2 * i];
      rgend[i] = rgend[2 * i + 1];
    }
  }

  int query (int ql, int qr, int u = 1) {
    ql = max(ql, lfend[u]);
    qr = min(qr, rgend[u]);

    if (ql > qr) {
      return 0;
    }

    if (ql == lfend[u] && qr == rgend[u]) {
      return tree[u];
    }

    return max(query(ql, qr, 2 * u),
               query(ql, qr, 2 * u + 1));
  }

  void set (int pos, int val) {
    tree[n + pos] = val;
    update((n + pos) / 2);
  }
};

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<vector<char>> grid (n, vector<char> (m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }

  vector<vector<int>> dp (n, vector<int> (m));
  vector<int> arr (m, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      // if (grid[i][j] == 'X') continue;

      dp[i][j] = j;
      if (i == 0) {
        dp[i][j] = 0;
      } else if (grid[i - 1][j] != 'X') {
        dp[i][j] = min(dp[i][j], dp[i - 1][j]);
      }

      if (j != 0 && grid[i][j - 1] != 'X') {
        dp[i][j] = min(dp[i][j], dp[i][j - 1]);
      }

      arr[j] = max(arr[j], dp[i][j]);
    }
  }
  
  Segtree tree (m);
  for (int i = 0; i < m; i++) {
    tree.set(i, arr[i]);
  }

  int qc;
  cin >> qc;

  for (int i = 0; i < qc; i++) {
    int l, r;
    cin >> l >> r;
    l--; r--;

    if (tree.query(l, r) > l) {
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
    }
  }
}