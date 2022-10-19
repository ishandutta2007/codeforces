#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int a = 0, b = 0;
    for (int i = 1; i <= n/2-1; i++) {
      a += 1<<i;
    }
    for (int i = n/2; i < n; i++) {
      b += 1<<i;
    }
    a += 1<<n;
    cout << a-b << '\n';
  }
}