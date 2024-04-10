#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

const int MOD = 1e9+1;
const int maxn = 2e5+7;
int lastans = 0;

// all values i where f(i) = f(i+1)
ordered_set X;

int get_temp(int T) {
  return T+X.size()/2-(int)X.order_of_key(T);
}

int get_index(int T) {
  int low = T-maxn;
  int high = T+maxn;
  while (low + 1 < high) {
    int mid = (low+high)/2;
    if (get_temp(mid) > T) high = mid;
    else low = mid;
  }
  return low;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int T, k;
    cin >> T >> k;
    vector<int> newvals = {get_index(T), get_index(T-1)};
    for (int u: newvals) X.insert(u);
    for (int j = 0; j < k; j++) {
      int x;
      cin >> x;
      x = (x+lastans)%MOD;
      lastans = get_temp(x);
      cout << lastans << '\n';
    }
  }
}