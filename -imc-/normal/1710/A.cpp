#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

void solve(bool read) {
  int n, m, k;
  cin >> n >> m >> k;

  vector<li> a(k);
  for (li& x : a) cin >> x;

  for (int t = 0; t < 2; ++t) {
    li s = 0;
    bool can_any = false;
    for (li x : a) {
      li can = x / n;
      if (can < 2) continue;

      if (can > 2) {
        can_any = true;
      }

      s += can;
    }

    if (s >= m) {
      if (can_any || m % 2 == 0) {
        cout << "Yes\n";
        return;
      }
    }

    swap(n, m);
  }

  cout << "No\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

#if 1
  int nt = 1;
  cin >> nt;

  for (int i = 0; i < nt; ++i) {
    solve(true);
  }
#endif

  //solve(false);

  return 0;
}