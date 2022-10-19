#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/contest/1630/submission/144210950
const int N = 2e5+5;
int a[N];
int r[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    r[a[i]] = i;
  }
  int ans = n;
  for (int i = 1; i <= n;) {
    int y = i;
    int z = r[a[i]];
    while (1) {
      ans--;
      int p = 0;
      for (int j = y; j <= z; j++) {
        p = max(p, r[a[j]]);
      }
      if (p == z) break;
      y = z+1;
      z = p;
    }
    if (i != z) ans--;
    i = z+1;
  }
  cout << ans << '\n';
}