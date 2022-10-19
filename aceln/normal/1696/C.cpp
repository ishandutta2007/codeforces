#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, long long>> v1, v2;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      int y = x, z = 1;
      while (y % m == 0) {
        y /= m, z *= m;
      }
      if (v1.empty() || v1.back().first != y) {
        v1.emplace_back(y, z);
      } else {
        v1.back().second += z;
      }
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
      int x;
      cin >> x;
      int y = x, z = 1;
      while (y % m == 0) {
        y /= m, z *= m;
      }
      if (v2.empty() || v2.back().first != y) {
        v2.emplace_back(y, z);
      } else {
        v2.back().second += z;
      }
    }
    if (v1 == v2)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}