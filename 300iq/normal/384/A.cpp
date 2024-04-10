#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, c = 0, c1 = 0;
  cin >> n;
  char a[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = (i + j) & 1;
      if (a[i][j]) c++;
      else c1++;
    }
  }
  cout << max(c, c1) << endl;
  if (c > c1) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        a[i][j] = (i + j) & 1;
        cout << (a[i][j] ? 'C' : '.');
      }
      cout << endl;
    }
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        a[i][j] = (i + j) & 1;
        cout << (!a[i][j] ? 'C' : '.');
      }
      cout << endl;
    }
  }
}