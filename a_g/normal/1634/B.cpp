#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, x;
    long long y;
    cin >> n >> x >> y;
    int v = 0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      v ^= a;
    }
    cout << ((y+x+v)&1 ? "Bob" : "Alice") << '\n';
  }
}