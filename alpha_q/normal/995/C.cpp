#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

typedef long long ll;

const int N = 100005;
const ll L = 15 * 100000LL;
const ll LIM = L * L;

int n, id[N], c[N];
ll x[N], y[N];
ll a = 0, b = 0;

inline bool good (ll p, ll q) {
  return p * p + q * q <= LIM;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    id[i] = i;
    scanf("%lld %lld", x + i, y + i);
  }
  while (1) {
    random_shuffle(id + 1, id + n + 1);
    a = b = 0;
    for (int _i = 1; _i <= n; ++_i) {
      int i = id[_i];
      ll one = (a + x[i]) * (a + x[i]) + (b + y[i]) * (b + y[i]);
      ll two = (a - x[i]) * (a - x[i]) + (b - y[i]) * (b - y[i]);
      if (one <= two) {
        c[i] = +1;
        a += x[i], b += y[i];
      } else {
        c[i] = -1;
        a -= x[i], b -= y[i];
      }
    }
    if (good(a, b)) {
      for (int i = 1; i <= n; ++i) {
        printf("%d ", c[i]);
      }
      puts("");
      return 0;
    }
  }
  return 0;
}