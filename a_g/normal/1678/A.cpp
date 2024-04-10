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
    int k = count(a.begin(), a.end(), 0);
    if (k) {
      cout << n-k << '\n';
      continue;
    }
    sort(a.begin(), a.end());
    bool win = 0;
    for (int i = 0; i < n-1; i++) {
      if (a[i]==a[i+1]) {
        win = 1;
        break;
      }
    }
    cout << (win ? n : n+1) << '\n';
  }
}