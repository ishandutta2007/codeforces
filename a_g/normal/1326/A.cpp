#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << "-1\n";
      continue;
    }
    if ((n-1)%3 == 0) {
      cout << string(n-2, '5');
      cout << '6';
    }
    else {
      cout << string(n-1, '5');
    }
    cout << "3\n";
  }
}