#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int n; ll L; scanf("%d%lld", &n, &L);
  vector<ll> a(n), b(n);
  for(ll &x : a) scanf("%lld", &x);
  for(ll &y : b) scanf("%lld", &y);
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for(int i = 0; i < n * 2; i++) {
    b.push_back(b[i] + L);
  }

  ll ans = L / 2;
  ll low = 0, high = L/2 - 1;
  while(low <= high) {
    ll mid = (low + high) >> 1;

    bool good = true;
    int l = -1, r = 1e9;
    for(int i = 0; i < n; i++) {
      int x = int(lower_bound(b.begin(), b.end(), a[i]+L - mid) - b.begin()) - i;
      int y = int(upper_bound(b.begin(), b.end(), a[i]+L + mid) - b.begin()) - i-1;
      if(x > y) good = false;
      l = max(l, x);
      r = min(r, y);
    }
    if(l > r) good = false;

    if(good) {
      ans = mid;
      high = mid - 1;
    }else {
      low = mid + 1;
    }
  }

  printf("%lld\n", ans);
  return 0;
}