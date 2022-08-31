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

int main () {
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;

  ordered_set<int> points;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    points.insert(x);
  }

  while (points.size() > 2) {
    int K = points.size();
    if (K % 2 == 0) {
      // vova takes one of the endpoints
      int U = (K / 2) - 1;
      int ll = *points.find_by_order(0);
      int lr = *points.find_by_order(K - 1 - U);

      int rl = *points.find_by_order(U);
      int rr = *points.find_by_order(K - 1);

      if (lr - ll < rr - rl) {
        points.erase(rr);
      } else {
        points.erase(ll);
      }
    } else {
      int m = *points.find_by_order(K / 2);
      points.erase(m);
    }
  }

  cout << *points.rbegin() - *points.begin() << endl;
}