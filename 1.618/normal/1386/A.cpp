#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>

using namespace std;
typedef long long ll;

bool check(ll p) {
  printf("? %lld\n", p);
  fflush(stdout);
  int res;
  scanf("%d", &res);
  return res;
}
ll n, cur, dir; // dir: direction, 1 / -1.
void solve() {
  scanf("%lld", &n);
  vector<ll> rig;
  ll l = 1, r = n;
  while (l < r) {
    ll mid = (l + r - 1) / 2;
    rig.push_back(mid);
    l = mid + 1;
  }
  cur = n, dir = -1;
  reverse(rig.begin(), rig.end());
  for (auto i : rig) {
    cur += dir * i;
    dir *= -1;
  }
  check(cur);
  l = 1, r = n;
  while (l < r) {
    ll mid = (l + r - 1) / 2;
    if (check(cur + dir * mid)) r = mid;
    else l = mid + 1;
    cur += dir * mid;
    dir *= -1;
  }
  printf("= %lld\n", l);
  fflush(stdout);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}