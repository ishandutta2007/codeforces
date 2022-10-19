#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using namespace __gnu_pbds;
using namespace std;

bool solve() {
  int n;
  cin >> n;
  vector<int> b(n);
  for (int i = 0; i < n ; i++) cin >> b[i];
  ordered_set s;
  for (int i = 0; i < n-1; i++) {
    int x = min(b[i], b[i+1])+1;
    int y = max(b[i], b[i+1]);
    if (x < y && s.order_of_key(x) != s.order_of_key(y)) return 0;
    s.insert(b[i]);
  }
  return 1;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cout << (solve() ? "YES" : "NO") << endl;
  }
}