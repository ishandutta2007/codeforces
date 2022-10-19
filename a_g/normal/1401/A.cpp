#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    if (n >= k) {
      cout << ((n+k)&1) << '\n';
      continue;
    }
    cout << k-n << '\n';
  }
}