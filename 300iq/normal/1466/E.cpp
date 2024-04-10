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

const int M = 1e9 + 7;

void add(int &a, int b) {
  a += b;
  if (a >= M) a -= M;
}

int mul(int a, int b) {
  return (a * (ll) b) % M;
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <ll> x(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i];
    }
    vector <int> have(60);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 60; j++) {
        if ((x[i] >> j) & 1) {
          have[j]++;
        }
      }
    }
    vector <int> l(60), r(60);
    vector <int> pw(60);
    pw[0] = 1;
    int ans = 0;
    for (int i= 1; i < 60; i++) pw[i] = mul(pw[i - 1], 2);
    for (int j = 0; j < n; j++) {
      for (int i = 0; i < 60; i++) l[i] = r[i] = 0;
      for (int i = 0; i < 60; i++) {
        if ((x[j] >> i) & 1) {
          l[i] += have[i];
          r[i] += n;
        } else {
          r[i] += have[i];
        }
      }
      int l_sum = 0, r_sum = 0;
      for (int i = 0; i < 60; i++) {
        add(l_sum, mul(l[i], pw[i]));
        add(r_sum, mul(r[i], pw[i]));
      }
      add(ans, mul(l_sum, r_sum));
    }
    cout << ans << '\n';
  }
}