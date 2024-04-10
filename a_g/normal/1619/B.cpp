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
    int ans = 0;
    for (int i = 1; i <= 100000; i++) {
      int u = i*i;
      if (u > n) break;
      ans++;
    }
    for (int i = 1; i <= 10000; i++) {
      int u = i*i*i;
      if (u > n) break;
      ans++;
    }
    for (int i = 1; i <= 10000; i++) {
      int u = i*i*i*i*i*i;
      if (u > n) break;
      ans--;
    }
    cout << ans << '\n';
  }
}