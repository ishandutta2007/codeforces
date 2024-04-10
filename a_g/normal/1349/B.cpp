#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    bool match = 0;
    for (int i = 0; i < n; i++) {
      int val;
      cin >> val;
      if (val < k) a[i] = -1;
      else if (val == k) {
        match = 1;
        a[i] = 0;
      }
      else a[i] = 1;
    }
    bool win = 0;
    // check for 00, 0+, +0
    for (int i = 0; i < n-1; i++) {
      if ((a[i] & a[i+1]) == 0 && a[i]+a[i+1] >= 0) win = 1;
    }
    // check for triples where median is >= 0
    for (int i = 0; i < n-2; i++) {
      int x = 0;
      for (int j = 0; j < 3; j++) {
        x += (a[i+j] >= 0);
      }
      if (x > 1 && match) win = 1;
    }
    // special case n = 1
    if (n == 1 && match) win = 1;
    cout << (win ? "YES\n" : "NO\n");
  }
}