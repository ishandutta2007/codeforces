#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <random>
#include <ctime>
#define maxn 1005

using namespace std;
typedef long long ll;
 
int T;
int pri[maxn], k;
bool notp[maxn];
int calcExp(ll p) {
  int res = log(1e9) / log(p);
  while (pow(p, res) > 1e9) res--;
  while (pow(p, res + 1) <= 1e9) res++;
  return res;
}
vector<ll> qs;
vector<int> fac;
void factorize(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      fac.push_back(i);
      while (x % i == 0) x /= i;
    }
  }
  if (x > 1) fac.push_back(x);
}
int d(int x) {
  int cnt = 0;
  for (int i = 1; i * i <= x; i++) {
    if (x % i == 0) {
      cnt++;
      if (i * i < x) cnt++;
    }
  }
  return cnt;
}
int query(ll x) {
  printf("? %lld\n", x);
  fflush(stdout);
  int res;
  scanf("%d", &res);
  return res;
}
void solve() {
  fac.clear();
  for (auto q : qs) factorize(query(q));
  int ans = 1; ll res = 1;
  for (auto p : fac) {
    ll cur = pow(p, calcExp(p));
    if (1.0 * res * cur > 3e18 || res * cur > (ll)1e18) {
      ans *= d(query(res));
      res = 1;
    }
    res *= cur;
  }
  if (res > 1) ans *= d(query(res));
  printf("! %d\n", max(ans + 7, ans * 2));
  fflush(stdout);
}
int main() {
  scanf("%d", &T);
  notp[1] = true;
  for (int i = 2; i <= 1000; i++) {
    if (!notp[i]) pri[++k] = i;
    for (int j = 1; j <= k && pri[j] * i <= 1000; j++) {
      notp[pri[j] * i] = true;
      if (i % pri[j] == 0) break;
    }
  }
  int j = 1; ll res;
  for (int i = 1; i <= 16; i++) {
    res = 1;
    while (1.0 * res * pri[j] <= 1e18 && res * pri[j] <= (ll)1e18) {
      res *= pri[j++];
    }
    qs.push_back(res);
  }
  while (T--) solve();
  return 0;
}