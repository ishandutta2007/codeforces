#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, d;
  cin >> n >> d;
  vector<int> p(n);
  for (int& x: p) cin >> x;
  sort(p.begin(), p.end(), greater<int>());
  int used = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (used+(d/p[i])+1 <= n) {
      used += d/p[i]+1;
      ans++;
    }
    else {
      break;
    }
  }
  cout << ans << '\n';
}