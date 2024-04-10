#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  ll ans = 0;
  for (int l = 0; l < n; l += 2) {
    ll cut = a[l];
    ll level = 0;
    for (int j = l; j < n; j++) {
      if (j&1) {
        ans += max<ll>(0, min<ll>(level, cut)-max<ll>(0, level-a[j]));
        cut = min(cut, level-a[j]+1);
      }
      level += (j&1 ? -a[j] : a[j]);
      if (level < 0) break;
    }
  }
  cout << ans << endl;
}