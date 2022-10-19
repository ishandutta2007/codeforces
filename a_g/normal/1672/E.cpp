#include <bits/stdc++.h>
using namespace std;

int ans = 1e9;

int query(int w) {
  cout << "? " << w << endl;
  int h;
  cin >> h;
  if (h) ans = min(ans, h*w);
  return h;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int low = 0;
  int high = 2001*n; // first, find smallest width to get 1 line
  while (high - low > 1) {
    int mid = (low+high)/2;
    int z = query(mid);
    if (z == 1) high = mid;
    else low = mid;
  }
  int L = high - (n-1); // sum of lengths
  for (int i = 2; i <= n; i++) {
    int cur = ans;
    query(ans/i);
  }
  cout << "! " << ans << endl;
}