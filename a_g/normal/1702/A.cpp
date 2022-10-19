#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int m;
    cin >> m;
    int z = 1;
    while (10LL*z <= m) z *= 10;
    cout << m-z << '\n';
  }
}