#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int x;
    cin >> x;
    cout << (x >= 111*(x % 11) ? "YES\n" : "NO\n");
  }
}