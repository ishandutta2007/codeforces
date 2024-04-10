#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

LL sum(LL n) { return (n * 1ll * (n + 1)) / 2; }
LL get(LL mid, LL H) {
  LL ans = -1;
  if (mid >= H) {
    ans = sum(mid) + sum(mid) - mid - sum(H - 1);
  } else {
    ans = sum(mid);
  }
  return ans;
}
int main() {
  LL n, H;
  cin >> n >> H;
  LL low = 1, high = 2e9, mx = -1;
  while (low <= high) {
    LL mid = (low + high) >> 1;
    LL ans = get(mid, H);
    if (ans <= n) {
      mx = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  assert(mx != -1);
  LL extra = n - get(mx, H);
  LL ans = -1;
  if (mx >= H)
    ans = 2 * mx - H;
  else
    ans = mx;
  while (extra > 0) {
    extra -= mx;
    ans++;
  }
  cout << ans << endl;
}