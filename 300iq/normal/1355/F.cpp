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

const int N = 701;

bool prime[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 2; i < N; i++) prime[i] = true;
  vector <ll> ans;
  for (int i = 2; i < N; i++) {
    if (prime[i]) {
      ans.push_back(i);
      for (int j = i + i; j < N; j += i) {
        prime[j] = false;
      }
    }
  }
  ll cur = 1e18;
  int qrs = 0;
  vector <ll> z;
  sort(ans.rbegin(), ans.rend());
  auto ask = [&] (ll x) {
    cout << "? " << x << endl;
    int y;
    cin >> y;
    return y;
  };
  for (ll x : ans) {
    bool good = false;
    sort(z.rbegin(), z.rend());
    for (ll &p : z) {
      if (p <= cur / x) {
        good = true;
        p *= x;
        break;
      }
    }
    if (!good) z.push_back(x);
  }
  int ts;
  cin >> ts;
  while (ts--) {
    vector <ll> ok;
    for (ll p : z) {
      int t = ask(p);
      for (int i = 2; i * i <= t; i++) {
        if (t % i == 0) {
          ok.push_back(i);
          t /= i;
        }
      }
      if (t != 1) ok.push_back(t);
    }
    int mda = 1e9;
    for (ll &x : ok) {
      ll y = x;
      while (x * y <= mda) {
        x *= y;
      }
    }
    ll ans = 1;
    for (int i = 0; i < (int) ok.size(); i += 2) {
      ll me = ok[i];
      if (i + 1 < (int) ok.size()) me *= ok[i + 1];
      ll t = ask(me);
      for (int i = 2; i * i <= t; i++) {
        int deg = 0;
        while (t % i == 0) {
          t /= i;
          deg++;
        }
        ans *= (deg + 1);
      }
      if (t != 1) ans *= 2;
    }
    cout << "! " << max(7ll,ans)+ans << endl;
  }
}