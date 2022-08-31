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
  ll n;
  cin >> n;
  auto cost = [&] (ll x) {
    string s = "";
    while (x) {
      s += (x % 2);
      x /= 2;
    }
    reverse(s.begin(), s.end());
    int ptr = 0;
    if (s.back() == 0) s.pop_back(), ptr++;
    ll sum = 0;
    for (int len = ptr; s.size() + len <= 60; len++) {
      ll x = 0;
      for (auto c : s) {
        x = x * 2 + c;
      }
      ll y = x;
      for (int i = 0; i < len; i++) x = x * 2;
      for (int i = 0; i < len; i++) y = y * 2 + 1;
      y = min(y, n);
      sum += max(0ll, y - x + 1);
    }
    return sum;
  };
  ll k;
  cin >> k;
  ll vl = 0, vr = n;
  while (vl < vr - 1) {
    ll vm = (vl + vr) / 2;
    if (2 * vm <= n && cost(2 * vm) >= k) {
      vl = vm;
    } else {
      vr = vm;
    }
  }
  ll ans_1 = 2 * vl;
  vl = 0, vr = n;
  while (vl < vr - 1) {
    ll vm = (vl + vr) / 2;
    if (2 * vm + 1 <= n && cost(2 * vm + 1) >= k) {
      vl = vm;
    } else {
      vr = vm;
    }
  }
  ans_1 = max(ans_1, 2 * vl + 1);
  cout << ans_1 << endl;
}