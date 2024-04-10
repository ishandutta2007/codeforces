#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> has_bit(30);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < 30; j++) {
      if (a[i]&(1<<j)) has_bit[j].push_back(a[i]);
    }
  }

  for (int j = 29; j >= 0; j--) {
    if (has_bit[j].size() == 1) {
      cout << has_bit[j][0] << ' ';
      for (int val: a) {
        if (val != has_bit[j][0]) {
          cout << val << ' ';
        }
      }
      cout << '\n';
      return 0;
    }
  }

  for (int val: a) cout << val << ' ';
  cout << '\n';
}