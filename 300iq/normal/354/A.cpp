#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, l, r, ql, qr;
  cin >> n >> l >> r >> ql >> qr;
  vector <int> w(n);
  vector <ll> p(n);
  ll s = 0;
  for (int i = 0; i < n; i++) {
    cin >> w[i];
    s += w[i];
    p[i] = s;
  }
  auto f = [&] (int l, int r) {
    if (l > r) return 0ll;
    if (!l) return p[r];
    else return p[r] - p[l - 1];
  };
  ll ret = 1e18;
  for (int x = -1; x < n; x++) {
    int a = x + 1, b = n - 1 - x;
    ll ans = f(0, x) * (ll) l;
    ans += f(x + 1, n - 1) * (ll) r;
    if (a > b) ans += (a - b - 1) * (ll) ql;
    else if (b > a) ans += (b - a - 1) * (ll) qr;
    ret = min(ret, ans);
  }
  cout << ret << endl;
}