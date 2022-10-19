#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < min(a, b); i++) {
      cout << "01";
    }
    for (int i = 0; i < a-b; i++) {
      cout << "0";
    }
    for (int i = 0; i < b-a; i++) {
      cout << "1";
    }
    cout << '\n';
  }
}