#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int x = 0, y = 0;
    while (n--) {
      int a;
      cin >> a;
      if (a&1) x++;
      else y++;
    }
    cout << min(x, y) << '\n';
  }
}