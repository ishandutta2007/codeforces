#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    if (n&1) {
      for (int i = 5; i <= n-2; i += 2) {
        cout << i << ' ' << i-1 << ' ';
      }
      cout << "2 3 1 ";
    }
    else {
      for (int i = 2; i <= n-2; i += 2) {
        cout << i << ' ' << i-1 << ' ';
      }
    }
    cout <<  n-1 << ' ' << n << '\n';
  }
}