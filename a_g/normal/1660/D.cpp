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
    int best = 0;
    int x = n;
    int y = 0;
    int l = 0;
    while (l < n) {
      while (l < n && a[l] == 0) l++;
      if (l == n) {
        break;
      }
      int r = l;
      while (r < n && a[r] != 0) r++;
      bool neg = 0;
      int c = 0;
      for (int j = l; j < r; j++) {
        if (a[j] < 0) neg = !neg;
        if (abs(a[j]) == 2) c++;
        if (!neg && c > best) {
          best = c;
          x = l;
          y = n-1-j;
        }
      }
      neg = 0;
      c = 0;
      for (int j = r-1; j >= l; j--) {
        if (a[j] < 0) neg = !neg;
        if (abs(a[j]) == 2) c++;
        if (!neg && c > best) {
          best = c;
          x = j;
          y = n-r;
        }
      }
      l = r+1;
    }

    cout << x << " " << y << '\n';
  }
}