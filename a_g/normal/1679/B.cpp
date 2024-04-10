#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  vector<int> last_upd(n);
  int u = 0, y = 0;
  for (int& x: a) cin >> x;
  long long s = accumulate(a.begin(), a.end(), 0LL);
  for (int time = 1; time <= q; time++) {
    int t;
    cin >> t;
    if (t == 1) {
      int i, x;
      cin >> i >> x;
      i--;
      s += x-(last_upd[i] >= u ? a[i] : y);
      a[i] = x;
      last_upd[i] = time;
    }
    else {
      cin >> y;
      s = 1LL * y * n;
      u = time;
    }
    cout << s << '\n';
  }
}