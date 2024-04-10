#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int totalxor = 0;
    int cutpoint = -1;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      totalxor ^= a[i];
      if (!totalxor && i % 2 == 0) {
        cutpoint = i;
      }
    }
    if (totalxor || (n % 2 == 0 && cutpoint == -1)) {
      cout << "NO" << '\n';
    }
    else {
      cout << "YES" << '\n';
      if (n & 1) {
        cout << n-2 << '\n';
        for (int j = 1; j < n; j += 2) {
          cout << j << " ";
        }
        for (int j = n-4; j > 0; j-= 2) {
          cout << j << " ";
        }
        cout << '\n';
      }
      else {
        int operations = n-4;
        if (cutpoint == 0 || cutpoint == n-2) {
          operations = n-3;
        }
        cout << operations << '\n';
        for (int j = 1; j < cutpoint; j += 2) {
          cout << j << " ";
        }
        for (int j = cutpoint-3; j > 0; j-= 2) {
          cout << j << " ";
        }
        for (int j = cutpoint + 2; j < n - 1; j += 2) {
          cout << j << " ";
        }
        for (int j = n-4; j > cutpoint; j-= 2) {
          cout << j << " ";
        }
        cout << '\n';
      }
    }
  }
}