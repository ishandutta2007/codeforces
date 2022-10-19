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
    vector<int> rightmost(n+1);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      rightmost[a[i]] = i;
    }
    int l = n-2;
    while (l >= 0 && a[l] <= a[l+1]) l--;
    if (l == -1) {
      cout << "0\n";
      continue;
    }

    int r = 0;
    set<int> zeroed;
    for (int i = l; i >= 0; i--) {
      zeroed.insert(a[i]);
      r = max(r, rightmost[a[i]]);
    }
    for (int i = r-1; i >= l+1; i--) zeroed.insert(a[i]);
    cout << zeroed.size() << '\n';
  }
}