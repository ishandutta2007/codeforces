#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int a, b;
    cin >> a >> b;
    a = abs(a-b);
    if (a%5 <= 2) {
      cout << (a+4)/5 << '\n';
    }
    else {
      cout << 2+a/5 << '\n';
    }
  }
}