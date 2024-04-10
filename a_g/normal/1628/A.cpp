#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> indices(n+2);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      indices[a[i]].push_back(i);
    }
    for (int i = 0; i <= n; i++) {
      if (indices[i].size()) {
        reverse(indices[i].begin(), indices[i].end());
      }
    }


    vector<int> b;
    int ptr = 0;
    while (ptr < n) {
      int target = 0;
      int nptr = ptr+1;
      while (indices[target].size()) {
        nptr = max(nptr, indices[target].back()+1);
        target++;
      }
      b.push_back(target);
      for (int i = 0; i < target; i++) {
        while (indices[i].size() && indices[i].back() <= nptr-1) indices[i].pop_back();
      }
      ptr = nptr;
    }
    cout << b.size() << '\n';
    for (int val: b) cout << val << ' ';
    cout << endl;
  }
}