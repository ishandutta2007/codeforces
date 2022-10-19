#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    cout << "2\n";
    for (int i = 1; i <= n; i += 2) {
      int v = i;
      while (v <= n) {
        cout << v << ' ';
        v *= 2;
      }
    }
    cout << '\n';
  }
}