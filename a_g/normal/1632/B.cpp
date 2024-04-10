#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int k = 31-__builtin_clz(n-1);
    int u = 1<<k;
    for (int i = u-1; i >= 0; i--) {
      cout << i << ' ';
    }
    for (int i = u; i < n; i++) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}