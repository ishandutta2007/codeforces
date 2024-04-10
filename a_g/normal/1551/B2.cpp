#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<vector<int>> indices(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      indices[a[i]-1].push_back(i);
    }
    vector<int> used;
    for (vector<int> p: indices) {
      for (int i = 0; i < min(k, (int)p.size()); i++) {
        used.push_back(p[i]);
      }
    }
    vector<int> ans(n);
    int total = k*(used.size()/k);
    for (int i = 0; i < total; i++) {
      ans[used[i]] = (i%k)+1;
    }
    for (int i: ans) cout << i << ' ';
    cout << endl;
  }
}