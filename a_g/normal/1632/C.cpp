#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int a, b;
    cin >> a >> b;
    int ans = b-a;
    for (int i = 0; i <= b-a; i++) {
      if (((a+i)|b) == b) {
        ans = min(ans, i+1);
        break;
      }
    }
    for (int i = 0; i <= b; i++) {
      if ((a|(b+i)) == b+i) {
        ans = min(ans, i+1);
        break;
      }
    }

    cout << ans << '\n';
  }
}