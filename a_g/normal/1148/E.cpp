#include <bits/stdc++.h>
using namespace std;

struct op {
  int i, j, d;
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  long long tot = 0;
  vector<pair<int, int>> s(n);
  vector<int> t(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i].first;
    s[i].second = i+1;
  }
  for (int& x: t) cin >> x;
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());

  vector<int> d(n);
  for (int i = 0; i < n; i++) {
    d[i] = t[i]-s[i].first;
  }

  long long z = 0;
  for (int x: d) {
    z += x;
    if (z < 0) {
      cout << "NO\n";
      return 0;
    }
  }
  if (z != 0) {
    cout << "NO\n";
    return 0;
  }

  cout << "YES\n";
  vector<op> ops;

  int pos_p = 0, neg_p = 0;
  while (pos_p < n && d[pos_p] <= 0) pos_p++;
  while (neg_p < n && d[neg_p] >= 0) neg_p++;
  while (pos_p < n) {
    assert(neg_p < n);
    assert(neg_p > pos_p);
    int k = min(d[pos_p], -d[neg_p]);
    ops.push_back(op{s[pos_p].second, s[neg_p].second, k});
    d[pos_p] -= k;
    d[neg_p] += k;
    while (pos_p < n && d[pos_p] <= 0) pos_p++;
    while (neg_p < n && d[neg_p] >= 0) neg_p++;
  }

  cout << ops.size() << '\n';
  for (op& z: ops) {
    cout << z.i << " " << z.j << " " << z.d << '\n';
  }
}