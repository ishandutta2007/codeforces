#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<long long> s(n), d(n-1);
  for (long long& x: s) cin >> x;
  sort(s.begin(), s.end());
  for (int i = 0; i < n-1; i++) {
    d[i] = s[i+1]-s[i];
  }
  sort(d.begin(), d.end());
  vector<long long> ds(n);
  for (int i = 0; i < n-1; i++) {
    ds[i+1] = ds[i] + d[i];
  }

  int q;
  cin >> q;
  while (q--) {
    long long l, r;
    cin >> l >> r;
    long long diff = r-l+1;
    // diff + sum of min(d[i], diff)
    int i = lower_bound(d.begin(), d.end(), diff)-d.begin();
    cout << (n-i)*diff+ds[i] << ' ';
  }
  cout << '\n';
}