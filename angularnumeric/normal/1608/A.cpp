#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> ans(n);
    ans[0] = 2;
    int p = 2;
    for (int i = 1; i < n; i++) {
      while (ans[i - 1] % p == 0) {
        p++;
      }
      ans[i] = p;
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }
}