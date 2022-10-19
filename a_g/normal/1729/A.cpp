#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int a, b, c;
    cin >> a >> b >> c;
    int x = a-1;
    int y = abs(b-c)+c-1;
    if (x > y) {
      cout << "2\n";
    }
    else if (x < y) {
      cout << "1\n";
    }
    else {
      cout << "3\n";
    }
  }
}