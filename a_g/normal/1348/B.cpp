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
    vector<int> b = a;
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end())-b.begin());
    if (b.size() > k) {
      cout << "-1\n";
      continue;
    }
    cout << n*k << '\n';
    while (b.size() < k) b.push_back(1);
    for (int i = 0; i < n; i++) {
      for (int x: b) {
        cout << x << ' ';
      }
    }
    cout << '\n';
  }
}