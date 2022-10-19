#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> indices;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') indices.push_back(i);
    }
    if (!indices.size()) {
      cout << "0\n";
      continue;
    }
    if (k >= n-1-indices.back()) {
      k -= n-1-indices.back();
      indices.back() = n-1;
    }
    if (indices[0] != n-1 && k >= indices[0]) {
      indices[0] = 0;
    }
    int ans = 0;
    for (int x: indices) {
      if (x == 0) ans += 10;
      else if (x == n-1) ans += 1;
      else ans += 11;
    }
    cout << ans << '\n';
  }
}