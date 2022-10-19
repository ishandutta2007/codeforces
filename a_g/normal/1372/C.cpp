#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int ans = 0;
    bool current = 0;
    for (int i = 1; i <= n; i++) {
      int val;
      cin >> val;
      if (val == i) {
        current = 0;
      }
      else {
        if (!current) {
          current = 1;
          ans++;
        }
      }
    }
    cout << min(2, ans) << endl;
  }
}