#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e6;
int a[N];
int b[N];
int p[N];
int c[2*N];

void solve(int l, int r, int lp, int rp) {
  int m = (l+r)/2;
  int c = 0;
  for (int i = lp+1; i <= rp; i++) {
    if (a[i] < b[m]) c++;
  }
  int best = c;
  int pos = lp;
  for (int i = lp+1; i <= rp; i++) {
    if (a[i] < b[m]) c--;
    if (a[i] > b[m]) c++;
    if (c < best) {
      best = c;
      pos = i;
    }
  }
  p[m] = pos;
  if (l < m) solve(l, m-1, lp, p[m]);
  if (r > m) solve(m+1, r, p[m], rp);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
      cin >> b[i];
    }
    sort(b+1, b+m+1);

    solve(1, m, 0, n);
    int x = 1;
    int y = 1;
    while (x <= m && p[x] == 0) {
      c[y++] = b[x++];
    }
    for (int i = 1; i <= n; i++) {
      c[y++] = a[i];
      while (x <= m && p[x] == i) {
        c[y++] = b[x++];
      }
    }

    ll ans = 0;
    ordered_set<pair<int, int>> o;
    for (int i = m+n; i >= 1; i--) {
      pair<int, int> p = make_pair(c[i], i);
      ans += o.order_of_key(p);
      o.insert(p);
    }

    cout << ans << '\n';
  }
}