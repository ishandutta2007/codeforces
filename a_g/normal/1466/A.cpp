#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), b;
    for (int& x: a) cin >> x;
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        b.push_back(a[j]-a[i]);
      }
    }
    sort(b.begin(), b.end());
    cout << unique(b.begin(), b.end())-b.begin() << '\n';
  }
}