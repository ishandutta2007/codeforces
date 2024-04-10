#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int s = a+b+c+d;
    if (s == 0) {
      cout << "0\n";
    }
    else if (s == 4) {
      cout << "2\n";
    }
    else {
      cout << "1\n";
    }
  }
}