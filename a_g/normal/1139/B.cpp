#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x: a) cin >> x;
  reverse(a.begin(), a.end());
  long long ans = 0;
  int cur = 1e9;
  for (int x: a) {
    int d = min(cur, x);
    ans += d;
    cur = max(0, d-1);
  }
  cout << ans << '\n';
}