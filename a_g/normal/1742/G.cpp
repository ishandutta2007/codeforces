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
    for (int& x: a) cin >> x;
    vector<int> ans;
    int mask = 0;
    while (n) {
      int best_index = -1;
      for (int i = 0; i < n; i++) {
        if (best_index == -1 || ((mask|a[i]) > (mask|a[best_index]))) {
          best_index = i;
        }
      }
      if ((mask|a[best_index]) == mask) break;
      ans.push_back(a[best_index]);
      mask |= a[best_index];
      a.erase(a.begin()+best_index);
      n--;
    }
    for (int x: ans) cout << x << ' ';
    for (int x: a) cout << x << ' ';
    cout << '\n';
  }
}