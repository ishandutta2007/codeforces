#include <cmath>
#include <functional>
#include <fstream>
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

const int M = 998244353;

bool ok[2][2];

vector <int> get_ans(ll cnt, ll a, ll b) {
  if (cnt == 0) {
    return {1, 0};
  } else {
    if (cnt % 2 == 0) {
      auto x = get_ans(cnt / 2, a, b);
      vector <int> ret(2);
      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
          int val = (x[i] * (ll) x[j]) % M;
          ret[i ^ j] += val;
          if (ret[i ^ j] >= M) ret[i ^ j] -= M;//????
        }
      }
      return ret;
    } else {
      a %= M, b %= M;
      auto x = get_ans(cnt - 1, a, b);
      vector <int> ret(2);
      for (int i = 0; i < 2; i++) {
        ret[i] += (x[i] * (ll) a) % M;
        if (ret[i] >= M) ret[i] -= M;
        ret[i ^ 1] += (x[i] * (ll) b) % M;
        if (ret[i ^ 1] >= M) ret[i ^ 1] -= M;
      }
      return ret;
    }
  }
};

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n, m, l, r;
  cin >> n >> m >> l >> r;
  if ((n * m) % 2) {
    auto ok = get_ans(n * m, r - l + 1, 0);
    cout << ok[0] << '\n';
    return 0;
  } else {
    auto f = [&] (ll l, ll r) {
      return r / 2 - (l - 1) / 2;
    };
    auto flex = [&] (ll cnt, ll l, ll r, int need_parity) {
      ll even = f(l, r);
      ll odd = (r - l + 1) - even;
      return (ll) get_ans(cnt, even, odd)[need_parity];
    };
    cout << flex(n * m, l, r, 0) << endl;
    return 0;
  }
}