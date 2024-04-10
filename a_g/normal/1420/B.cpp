#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long ans = 0;
    for (int b = 31; b >= 0; b--) {
      vector<int> left_part;
      vector<int> right_part;
      for (int val: a) {
        if (val&(1<<b)) right_part.push_back(val);
        else left_part.push_back(val);
      }
      int k = right_part.size();
      ans += 1LL * k * (k-1) / 2;
      a = left_part;
    }
    cout << ans << '\n';
  }
}