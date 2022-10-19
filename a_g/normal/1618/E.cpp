#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool solve() {
  int n;
  cin >> n;
  vector<int> b(n);
  for (int i = 0; i < n; i++) cin >> b[i];
  ll tot = accumulate(b.begin(), b.end(), 0LL);
  int d = (n*(n+1))/2;
  if (tot % d != 0) return 0;
  ll s = tot/d;
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    ll u = (b[(i+n-1)%n] - b[i] + s);
    if (u % n != 0 || u <= 0) return 0;
    ans[i] = u/n;
  }
  cout << "YES\n";
  for (int a: ans) cout << a << ' ';
  cout << '\n';
  return 1;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    if (!solve()) cout << "NO\n";
  }
}