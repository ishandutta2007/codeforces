#include <iostream>

using namespace std;

#include <bits/extc++.h>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>,
  rb_tree_tag, tree_order_statistics_node_update>;

// cur.order_of_key(2)
// the number of elements in the set less than 2
// *cur.find_by_order(1)
// the 1-st smallest number in the set(0-based)

const int MAX_N = 1e3 + 5;

int grid [MAX_N][MAX_N];
ordered_set<int> rowset [MAX_N];
ordered_set<int> colset [MAX_N];

int calc_for (int x, int y) {
  int nlx = rowset[x].order_of_key(grid[x][y]);
  int nly = colset[y].order_of_key(grid[x][y]);
  int ngx = (int) rowset[x].size() - nlx - 1;
  int ngy = (int) colset[y].size() - nly - 1;

  return 1 + max(nlx, nly) + max(ngx, ngy);
}

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
      rowset[i].insert(grid[i][j]);
      colset[j].insert(grid[i][j]);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << calc_for(i, j) << " ";
    }
    cout << '\n';
  }
}