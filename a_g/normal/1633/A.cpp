#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    if (n % 7 == 0) {
      cout << n << '\n';
      continue;
    }
    n -= n % 10;
    n += 7 - (n%7);
    cout << n << '\n';
  }
}