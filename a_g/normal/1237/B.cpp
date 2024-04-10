#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), exit(n+1);
  for (int& x: a) cin >> x;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    exit[x] = i;
  }
  int m = -1;
  int ans = 0;
  for (int x: a) {
    if (exit[x] < m) ans++;
    m = max(m, exit[x]);
  }
  cout << ans << '\n';
}