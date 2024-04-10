#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int cnt = 0, last = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (last == 0 && x != 0)
        cnt++;
      last = x;
    }
    cout << min(cnt, 2) << '\n';
  }
}