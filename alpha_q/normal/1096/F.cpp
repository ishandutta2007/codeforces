#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

const int N = 200010;
const int MOD = 998244353;

bitset <N> vis;
int n, p[N], bad; ll ans = 0; 
tree <int, null_type, greater <int>, rb_tree_tag, tree_order_statistics_node_update> os;

ll bigMod (ll a, ll e) {
  if (e == -1) e = MOD - 2;
  ll ret = 1;
  while (e) {
    if (e & 1) ret = ret * a % MOD;
    a = a * a % MOD, e >>= 1;
  }
  return ret;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", p + i);
    if (p[i] == -1) ++bad;
    else {
      vis[p[i]] = 1;
      ans += os.order_of_key(p[i]);
      os.insert(p[i]);
    }
  }
  ll add = (ll) bad * (bad - 1) % MOD;
  add = add * bigMod(4, -1) % MOD;
  ans += add, ans %= MOD;
  if (bad) ans *= bad, ans %= MOD;
  vector <int> v;
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) v.push_back(i);
  }
  int left = 0, right = bad;
  for (int i = 1; i <= n; ++i) {
    if (p[i] == -1) {
      ++left, --right;
      continue;
    }
    int small = upper_bound(v.begin(), v.end(), p[i]) - v.begin(), big = bad - small;
    ans += (ll) small * right + (ll) big * left, ans %= MOD;
  }
  if (bad) ans *= bigMod(bad, -1), ans %= MOD;
  cout << ans << '\n';
  return 0;
}