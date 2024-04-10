#include <iostream>
#include <map>

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

const int INF = 1e9 + 5;

map<int, ordered_set<pair<int, int>>> ds;

int cnt (int t, int x) {
  auto a = ds[x].order_of_key(make_pair(t, INF));
  auto b = ds[-x].order_of_key(make_pair(t, INF));

  return a - b;
}

int cur_op;

void add (int t, int x) {
  cur_op++;
  
  ds[x].insert(make_pair(t, cur_op));
}

void del (int t, int x) {
  cur_op++;

  ds[-x].insert(make_pair(t, cur_op));
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int type, t, x;
    cin >> type >> t >> x;

    if (type == 1) {
      add(t, x);
    } else if (type == 2) {
      del(t, x);
    } else {
      cout << cnt(t, x) << '\n';
    }
  }
}