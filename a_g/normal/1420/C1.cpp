#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+2;
int a[N];
int n, q;
long long ans;

void upd(int x, bool remove) {
  if (x < 1 || x > n) return;
  if ((x == 1 && a[x] > a[x+1]) ||
      (x == n &&  a[x] > a[x-1]) ||
      (x != 1 && x != n && a[x] > a[x-1] && a[x] > a[x+1])
     ) {
      if (remove) ans -= a[x];
      else ans += a[x];
      }
  if ((x != 1 && x != n && a[x] < a[x+1] && a[x] < a[x-1])) {
    if (remove) ans += a[x];
    else ans -= a[x];
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> q;
    ans = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n == 1) {
      q++;
      while (q--) {
        cout << "1\n";
      }
      continue;
    }
    for (int i = 1; i <= n; i++) upd(i, 0);
    cout << ans << '\n';
    while (q--) {
      int l, r;
      cin >> l >> r;
      for (int i: set<int>({l-1, l, l+1, r-1, r, r+1})) {
        upd(i, 1);
      }
      swap(a[l], a[r]);
      for (int i: set<int>({l-1, l, l+1, r-1, r, r+1})) {
        upd(i, 0);
      }
      cout << ans << '\n';
    }
  }
}