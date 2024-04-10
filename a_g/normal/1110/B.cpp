#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> b(n), d(n-1);
  for (int& x: b) cin >> x;
  for (int i = 0; i < n-1; i++) {
    d[i] = b[i+1]-b[i]-1;
  }
  int ans = b[n-1]-b[0]+1;
  sort(d.begin(), d.end(), greater<int>());
  ans -= accumulate(d.begin(), d.begin()+k-1, 0);
  cout << ans << '\n';
}