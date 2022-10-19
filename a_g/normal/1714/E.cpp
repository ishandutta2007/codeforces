#include <bits/stdc++.h>
using namespace std;

int c[20];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  c[2] = 0;
  c[4] = 0;
  c[6] = 1;
  c[8] = 0;
  c[12] = 1;
  c[14] = 1;
  c[16] = 0;
  c[18] = 1;
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int multiples_of_5 = 0;
    for (int& x: a) {
      cin >> x;
      if (x%2 == 1) {
        x += x%10;
      }
      if (x%5 == 0) multiples_of_5++;
    }
    if (multiples_of_5 == n) {
      for (int& x: a) {
        if (x%10 == 5) x += 5;
      }
      bool ok = 1;
      for (int& x: a) {
        if (x != a[0]) ok = 0;
      }
      cout << (ok ? "Yes" : "No") << '\n';
      continue;
    }
    else if (multiples_of_5 > 0) {
      cout << "No\n";
      continue;
    }
    bool ok = 1;
    for (int i = 0; i < n-1; i++) {
      if (c[a[i]%20] != c[a[i+1]%20]) ok = 0;
    }
    cout << (ok ? "Yes" : "No") << '\n';
  }
}