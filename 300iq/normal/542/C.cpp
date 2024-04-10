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
  auto gcd = [&] (ll a, ll b) {
    while (b) {
      ll ret = a % b;
      a = b;
      b = ret;
    }
    return a;
  };
  int n;
  cin >> n;
  vector <int> f(n);
  for (int i = 0; i < n; i++) {
    cin >> f[i];
    f[i]--;
  }
  ll rofl = 1;
  int s = 0;
  vector <bool> cyc(n);
  for (int i = 0; i < n; i++) {
    int x = i;
    vector <bool> u(n);
    int mda = 0;
    vector <int> ok;
    while (!u[x]) {
      mda++;
      ok.push_back(x);
      u[x] = true;
      x = f[x];
    }
    if (x == i) {
      for (int t : ok) {
        cyc[t] = true;
      }
      rofl = rofl * mda / gcd(rofl, mda);
    }
  }
  for (int i = 0; i < n; i++) {
    int x = i;
    int ok = 0;
    while (!cyc[x]) {
      ok++;
      x = f[x];
    }
    s = max(s, ok);
  }
  ll cur = rofl;
  while (cur < s) {
    cur += rofl;
  }
  cout << cur << endl;
}