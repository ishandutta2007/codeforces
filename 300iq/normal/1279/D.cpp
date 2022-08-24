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

const int M = 998244353;

int mul(int a, int b) {
  return (a * (ll) b) % M;
}

int pw(int a, int n) {
  int res = 1;
  while (n) {
    if (n % 2 == 0) {
      a = mul(a, a);
      n/= 2;
    } else {
      res = mul(res,a);
      n--;
    }
  }
  return res;
}

int inv(int x) {
  return pw(x, M - 2);
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int mod = M;
  vector <int> a(1000000);
  int id = 0;
  vector <vector <int> > p;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    vector <int> t;
    for (int i = 0; i < k; i++) {
      int x;
      cin >> x;
      x--;
      t.push_back(x);
      a[x]++;
    }
    p.push_back(t);
    id += k;
  }
  int ans = 0;
  int kek = inv(n);
  for (int i = 0; i < n; i++) {
    int ok = inv(p[i].size());
    for (int x : p[i]) {
      int prob = mul(mul(kek, ok), mul(a[x], kek));
      ans += prob;
      if (ans >= M) ans -= M;
    }
  }
  cout << ans << endl;
}