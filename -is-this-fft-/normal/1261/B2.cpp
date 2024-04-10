#include <iostream>
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

const int MAX_N = 2e5 + 5;

int arr [MAX_N];
vector<pair<int, int>> qs [MAX_N]; // the queries at prefix length k <pos, idx>
int ans [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<pair<int, int>> ord;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    ord.push_back(make_pair(-arr[i], i));
  }
  sort(ord.begin(), ord.end(), less<pair<int, int>>());

  int qc;
  cin >> qc;
  for (int i = 0; i < qc; i++) {
    int k, pos;
    cin >> k >> pos;
    qs[k].push_back(make_pair(pos - 1, i));
  }

  ordered_set<int> cur;
  for (int i = 1; i <= n; i++) {
    cur.insert(ord[i - 1].second);
    for (auto q : qs[i]) {
      ans[q.second] = arr[*cur.find_by_order(q.first)];
    }
  }

  for (int i = 0; i < qc; i++) {
    cout << ans[i] << '\n';
  }
}