#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    int total = (m*n)/2;
    bool transpose = 0;
    if (n&1) {
      swap(m, n);
      k = total-k;
      transpose = 1;
    }
    bool possible = 1;
    if (k&1) possible = 0;
    if (m&1 && k > (m/2)*n) possible = 0;
    cout << (possible ? "YES" : "NO") << endl;
  }
}