#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<bool> taken(2*n, 0);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i]--;
    }
    for (int val: a) taken[val] = 1;
    vector<int> ans;
    for (int val: a) {
      int t = val+1;
      while (t < 2*n && taken[t]) {
        t++;
      }
      if (t == 2*n) {
        break;
      }
      ans.push_back(val);
      ans.push_back(t);
      taken[t] = 1;
    }
    if (ans.size() < 2*n) {
      cout << -1 << endl;
    }
    else {
      for (int val: ans) {
        cout << val+1 << " ";
      }
      cout << endl;
    }
  }
}