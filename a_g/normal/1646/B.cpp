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
    long long r = 0;
    long long b = a[0];
    bool win = 0;
    for (int i = 1, j = n-1; ; i++, j--) {
      if (r > b) {
        win = 1;
        break;
      }
      if (i >= j) break;
      r += a[j];
      b += a[i];
    }
    cout << (win ? "YES" : "NO") << '\n';
  }
}