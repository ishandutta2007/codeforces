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
    for (int i = 0; i < n; i++) cin >> a[i];
    long long ans = 0;
    int r = 0;
    for (int l = 0; l < n; l++) {
      while (r+1 < n && a[r+1]-(r+1) >= 1-l) r++;
      ans += r-l+1;
    }
    cout << ans << '\n';
  }
}