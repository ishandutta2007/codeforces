#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

#define int long long

const int MAXN = 100005;

int l, n;
int a[MAXN];
int save[MAXN];

int check(int x, int y) {
  int l = 0, r = 0;
  int lx[n], rx[n];
  for(int i = 0; i < n; i++) {
    int r2 = std::min(r + y, a[i+1]);
    int l2 = std::max(l + x, a[i]);
    if(r2 < l2)
      return 0;
    if(i == n-1 && r2 < a[i+1])
      return 0;
    l = l2;
    r = r2;
    lx[i] = l;
    rx[i] = r;
  }
  save[n-1] = a[n];
  for(int i = n-2; i >= 0; i--) {
    int l2 = save[i+1]-y;
    int r2 = save[i+1]-x;
    save[i] = std::min(r2, rx[i]);
  }
  return 1;
}

int test(int x) {
  int lo = x, hi = l+1;
  while(lo < hi) {
    int mid = (lo+hi)/2;
    if(check(x, mid))
      hi = mid;
    else
      lo = mid+1;
  }
  return lo-x;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cin >> l >> n;

  a[n] = l;
  std::vector<int> tests;

  for(int i = 0; i < n; i++)
    std::cin >> a[i];

  int lo = 1, hi = l+1;
  while(lo < hi) {
    int mid = (lo+hi)/2;
    if(check(mid, l+1))
      lo = mid+1;
    else
      hi = mid;
  }

  int mn = lo-1;
  lo = mn, hi = l+1;
  while(lo < hi) {
    int mid = (lo+hi)/2;
    if(check(mn, mid))
      hi = mid;
    else
      lo = mid+1;
  }

  check(mn, lo);

  /*
  std::pair<int, std::pair<int, int> > best = {l+1, {-1, -1}};
  for(int j = 1; j <= l; j++) {
    for(int k = j; k <= l; k++) {
      if(check(j, k)) {
        best = std::min(best, {k-j, {j, k}});
        break;
      }
    }
  }
  check(best.second.first, best.second.second);
  */

  int max = save[0];
  int min = save[0];
  std::cout << 0 << " " << save[0] << "\n";
  for(int i = 1; i < n; i++) {
    std::cout << save[i-1] << " " << save[i] << "\n";
    max = std::max(max, save[i]-save[i-1]);
    min = std::min(min, save[i]-save[i-1]);
  }

  return 0;
}