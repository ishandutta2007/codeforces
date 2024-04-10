#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  if (a == n/2+1 && b == n/2) {
    for (int i = n; i >= 1; i--) cout << i << ' ';
    cout << endl;
    return;
  }
  if (a > b || a >= n/2+1 || b <= n/2) {
    cout << -1 << endl;
    return;
  }
  vector<int> x(n);
  for (int i = 0; i < n/2; i++) x[i] = 1;
  x[a-1] = 0;
  x[b-1] = 1;
  for (int i = n; i >= 1; i--) {
    if (!x[i-1]) cout << i << ' ';
  }
  for (int i = n; i >= 1; i--) {
    if (x[i-1]) cout << i << ' ';
  }
  cout << endl;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}