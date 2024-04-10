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
    for (int i = n&1; i + 1 < n; i += 2) {
      if (a[i] > a[i+1]) swap(a[i], a[i+1]);
    }
    cout << (is_sorted(a.begin(), a.end()) ? "YES" : "NO") << '\n';
  }
}