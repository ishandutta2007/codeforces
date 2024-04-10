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
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> b = a;
    vector<vector<int>> ans;
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) {
        for (int j = i+1; j < n; j++) {
          if (a[j] == b[i]) {
            ans.push_back({i+1, j+1, j-i});
            rotate(a.begin()+i, a.begin()+j, a.begin()+j+1);
            break;
          }
        }
      }
    }
    cout << ans.size() << '\n';
    for (vector<int> x: ans) {
      for (int val: x) cout << val << ' ';
      cout << '\n';
    }
  }
}