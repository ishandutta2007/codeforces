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
    vector<string> a(n-2);
    for (int i = 0; i < n-2; i++) cin >> a[i];
    bool found = 0;
    cout << a[0][0];
    for (int i = 0; i < n-3; i++) {
      cout << a[i][1];
      if (a[i][1] != a[i+1][0]) {
        found = 1;
        cout << a[i+1][0];
      }
    }
    cout << a[n-3][1];
    if (!found) cout << a[n-3][1];
    cout << '\n';
  }
}