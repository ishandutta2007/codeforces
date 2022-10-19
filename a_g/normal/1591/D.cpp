#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

bool solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> indices(n, -1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    indices[a[i]-1] = i;
  }
  ll inv = 0;
  ordered_set<int> o;
  for (int i = 0; i < n; i++) {
    int u = indices[i];
    if (u == -1) return 1;
    inv += o.order_of_key(-u);
    o.insert(-u);
  }
  return 1-inv&1;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cout << (solve() ? "YES" : "NO") << '\n';
  }
}