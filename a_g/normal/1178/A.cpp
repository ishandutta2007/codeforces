#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x: a) cin >> x;
  int tot = accumulate(a.begin(), a.end(), 0);
  vector<int> ans(1, 0);
  int z = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] <= a[0]/2) {
      ans.push_back(i);
      z += a[i];
    }
  }
  if (2*z <= tot) {
    cout << "0\n";
  }
  else {
    cout << ans.size() << '\n';
    for (int x: ans) {
      cout << x+1 << ' ';
    }
    cout << '\n';
  }
}