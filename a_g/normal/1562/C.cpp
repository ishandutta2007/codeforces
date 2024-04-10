#include <bits/stdc++.h>
using namespace std;

int main () {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    bool done = false;
    int n;
    string s;
    cin >> n >> s;
    for (int j = 0; j < n; j++) {
      if (s[j] == '0') {
        if (j <= (n-1)/2) {
          cout << j + 1 << " " << n << " " << j+2 << " " << n << endl;
        }
        else {
          cout << 1 << " " << j+1 << " " << 1 << " " << j << endl;
        }
        done = true;
        break;
      }
    }
    if (!done) {
      cout << 1 << " " << n-1 << " " << 2 << " " << n << endl;
    }
  }
}