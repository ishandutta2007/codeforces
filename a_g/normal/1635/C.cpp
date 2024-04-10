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
    for (int i = 0; i < n; i++) cin >> a[i];
    if (a[n-2] > a[n-1]) {
      cout << "-1\n";
      continue;
    }
    if (a[n-1] < 0) {
      cout << (is_sorted(a.begin(), a.end()) ? "0" : "-1") << '\n';
      continue;
    }
    cout << n-2 << '\n';
    for (int i = n-2; i >= 1; i--) {
      cout << i << " " << i+1 << " " << n << '\n';
    }
  }
}