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
      a[i&1].push_back(x);
    }
    for (int z = 0; z < 2; z++) {
      sort(a[z].begin(), a[z].end());
    }
    vector<int> a_merge(n);
    for (int i = 0; i < n; i++) {
      a_merge[i] = a[i&1][i/2];
    }
    cout << (is_sorted(a_merge.begin(), a_merge.end()) ? "YES" : "NO") << '\n';
  }
}