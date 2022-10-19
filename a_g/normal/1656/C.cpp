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
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end())-a.begin());
    if (a.size() == 1) {
      cout << "YES\n";
      continue;
    }
    if (a[1] == 1) {
      assert(a[0] == 0);
      cout << "NO\n";
      continue;
    }
    if (a[0] != 1) {
      cout << "YES\n";
      continue;
    }
    bool win = 1;
    for (int i = 0; i + 1 < (int)a.size(); i++) {
      if (a[i+1]-a[i] == 1) {
        win = 0;
        break;
      }
    }
    cout << (win ? "YES" : "NO") << '\n';
  }
}