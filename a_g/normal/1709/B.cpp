#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int& x: a) cin >> x;
  vector<long long> l(n), r(n);
  for (int i = 1; i < n; i++) {
    l[i] = l[i-1] + max(0, a[i]-a[i-1]);
    r[i] = r[i-1] + max(0, a[i-1]-a[i]);
  }

  while (q--) {
    int s, t;
    cin >> s >> t;
    if (s < t) {
      cout << r[t-1]-r[s-1] << '\n';
    }
    else {
      cout << l[s-1]-l[t-1] << '\n';
    }
  }
}