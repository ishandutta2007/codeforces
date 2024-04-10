#include <bits/stdc++.h>
using namespace std;

long long query(int a, int b) {
  cout << "? " << a << ' ' << b << endl;
  long long ans;
  cin >> ans;
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  long long ans = 0;
  long long ub = 1e18;
  for (int a = 1; a <= 7; a++) {
    for (int b = a+1; b <= 7; b++) {
      long long x = query(a, b);
      long long y = query(b, a);
      if (x != -1 && x != y) ans = x+y;
      else if (x == -1) ub = min<long long>(ub, max(a, b)-1);
    }
  }
  if (ans) cout << "! " << ans << endl;
  else {
    assert(ub <= 6);
    cout << "! " << ub << endl;
  }
}