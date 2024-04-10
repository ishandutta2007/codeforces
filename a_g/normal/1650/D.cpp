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
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i]--;
    }
    vector<int> ans(n);
    for (int i = n-1; i >= 0; i--) {
      auto it = find(a.begin(), a.end(), i);
      ans[i] = (1+it-a.begin())%(i+1);
      if (ans[i]) {
        rotate(a.begin(), it+1, a.begin()+(i+1));
      }
    }

    for (int x: ans) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}