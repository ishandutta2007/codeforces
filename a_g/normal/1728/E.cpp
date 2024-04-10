#include <bits/stdc++.h>
using namespace std;

int inversemod(int p, int q) {
  // assumes p > 0
  // https://codeforces.com/blog/entry/23365
  return (p > 1 ? q-1LL*inversemod(q%p, p)*q/p : 1);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> c(n);
  long long s = 0;
  for (int i = 0; i < n; i++) {
    cin >> c[i].first >> c[i].second;
    s += c[i].second;
  }
  sort(c.begin(), c.end(), [&] (const pair<int, int>& x, const pair<int, int>& y) {
    return x.first-x.second > y.first-y.second;
      });
  vector<long long> val(n+1);
  val[0] = s;
  for (int i = 0; i < n; i++) {
    s += c[i].first-c[i].second;
    val[i+1] = s;
  }
  int opt = 0;
  while (opt < n && c[opt].first > c[opt].second) opt++;

  int q;
  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;
    int g = __gcd(x, y);
    if (n%g != 0) {
      cout << "-1\n";
      continue;
    }
    // a*(x/g)+b*(y/g)=n/g
    int a = (1LL*(n/g)*inversemod(x/g, y/g))%(y/g);
    if (1LL*a*x > n) {
      cout << "-1\n";
      continue;
    }
    // (a+k(y/g))x <= opt
    long long ans = 0;
    int target = opt/x;
    target = (y/g)*(target/(y/g))+a;
    while (1LL*target*x > opt) target -= y/g;
    if (target >= 0) ans = max(ans, val[target*x]);
    target += y/g;
    if (1LL*target*x <= n) ans = max(ans, val[target*x]);
    cout << ans << '\n';
  }
}