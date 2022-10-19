#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& x: a) cin >> x;
    vector<pair<long long, long long>> left, right;
    long long s = 0;
    long long dip = 0;
    for (int i = k; i < n; i++) {
      s += a[i];
      if (s >= 0) {
        right.emplace_back(-dip, s);
        s = 0;
        dip = 0;
      }
      else {
        dip = min(dip, s);
      }
    }
    right.emplace_back(-dip, s);
    s = 0;
    dip = 0;
    for (int i = k-2; i >= 0; i--) {
      s += a[i];
      if (s >= 0) {
        left.emplace_back(-dip, s);
        s = 0;
        dip = 0;
      }
      else {
        dip = min(dip, s);
      }
    }
    left.emplace_back(-dip, s);
    reverse(left.begin(), left.end());
    reverse(right.begin(), right.end());
    long long x = a[k-1];
    while (left.size() || right.size()) {
      if (left.size() && x >= left.back().first) {
        x += left.back().second;
        left.pop_back();
      }
      else if (right.size() && x >= right.back().first) {
        x += right.back().second;
        right.pop_back();
      }
      else break;
    }
    bool ok = 0;
    if (left.empty()) ok = 1;
    else if (left.size() == 1 && x >= left.back().first) ok = 1;
    if (right.empty()) ok = 1;
    else if (right.size() == 1 && x >= right.back().first) ok = 1;
    cout << (ok ? "YES" : "NO") << '\n';
  }
}