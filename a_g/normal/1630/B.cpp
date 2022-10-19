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
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b.begin(), b.end());
    int x = 0;
    int y = 1e9;
    int z = (n+k-1)/2;
    for (int i = 0; i+z < n; i++) {
      if (b[i+z] - b[i] <= y-x) {
        x = b[i];
        y = b[i+z];
      }
    }
    cout << x << " " << y << '\n';
    int cur = 0;
    int prv = 0;
    int tot = 0;
    for (int i = 0; i < n; i++) {
      if (x <= a[i] && a[i] <= y) {
        cur++;
      }
      else {
        cur--;
      }
      if (cur == 1 && tot < k-1) {
        cout << prv+1 << " " << i+1 << '\n';
        prv = i+1;
        cur = 0;
        tot++;
      }
    }
    cout << prv+1 << " " << n << '\n';
  }
}