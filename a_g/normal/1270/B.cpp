#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    ll prev;
    cin >> prev;
    ll current;
    bool done = false;
    for (int i = 0; i < n-1; i++) {
      cin >> current;
      if (!done && abs(current-prev) > 1) {
        cout << "YES" << endl;
        cout << i+1 << " " << i+2 << endl;
        done = true;
      }
      prev = current;
    }
    if (!done) cout << "NO" << endl;
  }
}