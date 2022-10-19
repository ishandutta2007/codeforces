#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int breakpoint = -1;
    for (int i = 0; i < n; i++) {
      if (a[i] < i) {
        breakpoint = i-1;
        break;
      }
    }
    if (breakpoint == -1) {
      cout << "Yes\n";
      continue;
    }
    bool win = 1;
    for (int i = n-1; i >= breakpoint; i--) {
      if (a[i] < n-1-i) {
        win = 0;
        break;
      }
    }
    cout << (win ? "Yes" : "No") << '\n';
  }
}