#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
using namespace __gnu_pbds;
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    ordered_set a;
    ll ans = 0;
    for (int i = 0; i < n; i++ ){
      int val;
      cin >> val;
      int s = a.order_of_key({val, -1});
      int l = i-a.order_of_key({val, i});
      ans += min(s, l);
      a.insert({val, i});
    }
    cout << ans << '\n';
  }
}