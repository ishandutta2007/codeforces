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

const int MAX_N = 4e5 + 5;
const int MAX_LG = 25;

typedef long long ll;

int n;
int arr [MAX_N];

const int MAX_A = (1 << 26) + 5;

char cum [MAX_A];

int clamp (int l, int m, int r) {
  return max(l, min(m, r));
}

int get_bit (int k) {
  ordered_set<pair<int, int>> seen;

  for (int i = 0; i < 1 << (k + 1); i++) {
    cum[i] = 0;
  }
  
  for (int i = 0; i < n; i++) {
    int cur = arr[i] % (1 << (k + 1));
    cum[cur]++;
  }

  for (int i = 1; i < 1 << (k + 1); i++) {
    cum[i] += cum[i - 1];
  }

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    int cur = arr[i] % (1 << (k + 1));

    if (4 * (1 << k) - cur - 1 >= 0) ans += cum[min((1 << (k + 1)) - 1, 4 * (1 << k) - cur - 1)];
    if (3 * (1 << k) - cur - 1 >= 0) ans -= cum[min((1 << (k + 1)) - 1, 3 * (1 << k) - cur - 1)];
    if (2 * (1 << k) - cur - 1 >= 0) ans += cum[min((1 << (k + 1)) - 1, 2 * (1 << k) - cur - 1)];
    if (1 * (1 << k) - cur - 1 >= 0) ans -= cum[min((1 << (k + 1)) - 1, 1 * (1 << k) - cur - 1)];
  }

  for (int i = 0; i < n; i++) {
    if ((2 * arr[i]) & 1 << k) {
      ans--;
    }
  }
  
  ans /= 2;
  
  ans %= 2;
  if (ans < 0) ans = 1;

  return ans;
}

int main () {
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int ans = 0;
  for (int i = 0; i < MAX_LG; i++) {
    ans += get_bit(i) << i;
  }
  cout << ans << endl;
}