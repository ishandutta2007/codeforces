#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    cout << 1;
    for (int i = n; i >= 2; i--) cout << ' ' << i;
    cout << '\n';
  }
}