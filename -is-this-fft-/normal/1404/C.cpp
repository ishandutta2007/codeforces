#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

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

class Fenwick {
  vector<int> tree;

public:
  Fenwick (int _n) : tree(_n, 0) {}

  int get (int idx) {
    int ans = 0;
    for (int i = idx; i > 0; i -= i & -i) {
      ans += tree[i];
    }
    return ans;
  }

  int range (int l, int r) {
    return get(r) - get(l - 1);
  }
  
  void add (int idx, int val) {
    for (int i = idx; i < (int) tree.size(); i += i & -i) {
      tree[i] += val;
    }
  }
};

int arr [MAX_N];
int root [MAX_N];
int last [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, qc;
  cin >> n >> qc;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    arr[i] = i - arr[i];
  }

  vector<pair<int, pair<int, int>>> events; // <l, type, r>
    // type = 0 if query
  // type = 1 if add

  ordered_set<pair<int, int>> rootpq; // <root, idx>
  for (int i = 1; i <= n; i++) {
    if (arr[i] < 0 || (int) rootpq.size() < arr[i]) {
      root[i] = 0;
    } else if (arr[i] == 0) {
      root[i] = i;
    } else {
      int sz = rootpq.size();
      root[i] = rootpq.find_by_order(sz - arr[i])->first;
    }
    rootpq.insert(make_pair(root[i], i));
  }
  
  for (int i = 1; i <= n; i++) {
    if (root[i] != 0) {
      events.push_back(make_pair(root[i], make_pair(1, i)));
    }
  }
  
  vector<pair<int, int>> qs;
  for (int i = 0; i < qc; i++) {
    int a, b;
    cin >> a >> b;

    int l = a + 1;
    int r = n - b;
    qs.push_back(make_pair(l, r));
    events.push_back(make_pair(l, make_pair(0, r)));
  }

  sort(events.begin(), events.end());
  reverse(events.begin(), events.end());

  Fenwick fen (MAX_N);
  map<pair<int, int>, int> ans;
  for (auto ev : events) {
    if (ev.second.first == 1) {
      fen.add(ev.second.second, 1);
    } else {
      ans[make_pair(ev.first, ev.second.second)] = fen.range(ev.first, ev.second.second);
    }
  }

  for (auto pr : qs) {
    cout << ans[pr] << '\n';
  }
}