#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k, r, c;
    cin >> n >> k >> r >> c;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++){
        cout << ((i+j)%k == (r+c)%k ? 'X' : '.');
      }
      cout << '\n';
    }
  }
}