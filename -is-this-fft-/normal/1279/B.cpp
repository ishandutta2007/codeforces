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

typedef long long ll;

const int MAX_N = 1e5 + 5;

ll arr [MAX_N];
ll cum [MAX_N];

void solve () {
  int n;
  ll s;
  cin >> n >> s;

  ordered_set<ll> times;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    cum[i] = cum[i - 1] + arr[i];
    times.insert(cum[i]);
  }

  if (cum[n] <= s) {
    cout << 0 << '\n';
    return;
  }

  pair<int, int> best = {times.order_of_key(s + 1), 0};
  for (int i = 1; i <= n; i++) {
    if (cum[i] <= s) {
      int ngs = times.order_of_key(s + arr[i] + 1) - 1;
      best = max(best, {ngs, i});
    } else if (cum[i] > s && cum[i - 1] < s) {
      int ngs = times.order_of_key(s + arr[i] + 1) - 1;
      best = max(best, {ngs, i});
    }
  }
  
  cout << best.second << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}