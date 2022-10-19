#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x: a) cin >> x;
  vector<int> b = a;
  sort(b.begin(), b.end());
  int ans = (b[0]+1)/2 + (b[1]+1)/2;
  for (int i = 0; i < n-1; i++) {
    int x = a[i];
    int y = a[i+1];
    if (x > y) swap(x, y);
    if (y >= 2*x) {
      ans = min(ans, (y+1)/2);
    }
    else {
      int ops = (x+y+2)/3;
      assert(x >= ops);
      assert(y >= ops);
      ans = min(ans, ops);
    }
  }
  for (int i = 0; i < n-2; i++) {
    int x = a[i];
    int y = a[i+2];
    ans = min(ans, (x+y+1)/2);
  }
  cout << ans << '\n';
}