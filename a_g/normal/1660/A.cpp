#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int a, b;
    cin >> a >> b;
    if (a == 0) {
      cout << "1\n";
      continue;
    }
    cout << a+2*b+1 << '\n';
  }
}