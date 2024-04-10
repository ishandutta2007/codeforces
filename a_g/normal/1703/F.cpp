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
    vector<int> indices;
    for (int i = 1; i <= n; i++) {
      cin >> a[i-1];
      if (a[i-1] < i) {
        indices.push_back(i);
      }
    }
    long long ans = 0;
    for (int x: indices) {
      ans += lower_bound(indices.begin(), indices.end(), a[x-1])-indices.begin();
    }
    cout << ans << '\n';
  }
}