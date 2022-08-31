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

const int N = 2e5 + 123;
const int M = 1e9 + 7;

int fact[N];
int rfact[N];

int mul(int a, int b) {
  return (a * (ll) b) %M ;
}

int pw(int a, int n) {
  int res = 1;
  while (n) {
    if (n % 2 == 0) {
      a = mul(a, a);
      n /= 2;
    } else {
      res = mul(res, a);
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
  vector <int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  if (n == 1) {
    cout << x[0] << endl;
    return 0;
  }
  if (n % 2) {
    vector <int> y(n - 1);
    auto a = x;
    for (int i = 0; i < n - 1; i++) {
      if (i % 2) y[i] = a[i] - a[i + 1];
      else y[i] = a[i] + a[i + 1];
      if (y[i] >= M) y[i] -= M;
      if (y[i] < 0) y[i] += M;
    }
    n--;
    x = y;
  }
  fact[0] = 1;
  for (int i= 1; i <= n; i++) fact[i] = mul(fact[i - 1], i);
  for (int i = 0; i <= n; i++) rfact[i] = inv(fact[i]);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int a = n / 2 - 1;
    int b = i / 2;
    int mda = (fact[a] * (ll) ((rfact[b] * (ll) rfact[a - b]) % M)) % M;
    if (i % 2 && a % 2) mda = M - mda;
    sum += (mda * (ll) x[i]) % M;
    if (sum >= M) sum -= M;
  }
  cout << sum << endl;
}