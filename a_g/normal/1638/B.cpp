#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a[2];
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a[x&1].push_back(x);
    }
    cout << (is_sorted(a[0].begin(), a[0].end()) && is_sorted(a[1].begin(), a[1].end()) ? "YES" : "NO") << '\n';
  }
}