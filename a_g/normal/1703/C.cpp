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
    for (int i = 0; i < n; i++) {
      int b;
      string s;
      cin >> b >> s;
      for (char c: s) {
        if (c == 'D') {
          a[i]++;
          if (a[i] == 10) a[i] = 0;
        }
        else {
          a[i]--;
          if (a[i] == -1) a[i] = 9;
        }
      }
    }
    for (int& x: a) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}