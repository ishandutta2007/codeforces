#include <iostream>
#include <set>

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

const int MAX_N = 3e5 + 5;

int mn [MAX_N];
int mx [MAX_N];
int cur_pri [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;

  ordered_set<pair<int, int>> cur;
  for (int i = 1; i <= n; i++) {
    mn[i] = i;
    mx[i] = i;
    cur_pri[i] = i;
    cur.insert({cur_pri[i], i});
  }

  for (int i = 0; i < q; i++) {
    int a;
    cin >> a;

    mn[a] = 1;
    int pos = cur.order_of_key({cur_pri[a], a}) + 1;
    mx[a] = max(mx[a], pos);
    cur.erase({cur_pri[a], a});
    cur_pri[a] = -i;
    cur.insert({cur_pri[a], a});
  }

  for (int i = 1; i <= n; i++) {
    int a = i;
    int pos = cur.order_of_key({cur_pri[i], i}) + 1;
    mx[a] = max(mx[a], pos);

    cout << mn[a] << " " << mx[a] << '\n';
  }
}