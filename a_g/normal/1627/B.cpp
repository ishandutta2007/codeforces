#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ans.push_back(max(i, n-1-i) + max(j, m-1-j));
      }
    }
    sort(ans.begin(), ans.end());
    for (int val: ans) cout << val << ' ';
    cout << '\n';
  }
}