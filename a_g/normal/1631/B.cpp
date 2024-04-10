#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int a[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int z = n-1;
    while (z && a[z] == a[n]) z--;
    int ans = 0;
    while (z) {
      ans++;
      z = 2*z - n;
      if (z < 0) break;
      while (z && a[z] == a[n]) z--;
    }

    cout << ans << '\n';
  }
}