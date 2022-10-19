#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int A = 13;
const int M = 1 << A;
const int N = 50500;

int n, a[M], w, m, b[M];
string s[N];

void read() {
  cin >> w >> n >> m;
  fill(a, a + M, 0);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    b[x]++;
  }

  for (int i = 0; i < m; ++i) {
    cin >> s[i];
    reverse(all(s[i]));
  }
}

bool small(char c) {
  return 'a' <= c && c <= 'z';
}

int bit(int mask, int i) {
  return (mask >> i) & 1;
}

int chg(int mask, int i) {
  return mask ^ (1 << i);
}

ll fun(string s) {
  int target = 0;
  int tot = 1 << w;
  int by = 1;

  for (int i = 0; i < w; ++i) {
    if (small(s[i])) {
      target |= (1 << i);
    }

    if (s[i] == 'O' || s[i] == 'o') {
      for (int mask = 0; mask < tot; ++mask) {
        if (bit(mask, i)) a[mask] += a[chg(mask, i)];
      }
    }

    if (s[i] == 'A' || s[i] == 'a') {
      for (int mask = 0; mask < tot; ++mask) {
        if (bit(mask, i)) a[chg(mask, i)] += a[mask];
      }
    }

    if (s[i] == 'X' || s[i] == 'x') {
      by *= 2;
      for (int mask = 0; mask < tot; ++mask) {
        if (bit(mask, i)) {
          ll x = a[mask];
          ll y = a[chg(mask, i)];
          a[mask] = y - x;
          a[chg(mask, i)] = y + x;
        }
      }
    }
  }

  for (int mask = 0; mask < tot; ++mask)
    a[mask] *= a[mask];

  for (int i = 0; i < w; ++i) {
    if (s[i] == 'O' || s[i] == 'o') {
      for (int mask = 0; mask < tot; ++mask) {
        if (bit(mask, i)) a[mask] -= a[chg(mask, i)];
      }
    }

    if (s[i] == 'A' || s[i] == 'a') {
      for (int mask = 0; mask < tot; ++mask) {
        if (bit(mask, i)) a[chg(mask, i)] -= a[mask];
      }
    }

    if (s[i] == 'X' || s[i] == 'x') {
      for (int mask = 0; mask < tot; ++mask) {
        if (bit(mask, i)) {
          ll x = a[mask];
          ll y = a[chg(mask, i)];
          a[mask] = y - x;
          a[chg(mask, i)] = y + x;
        }
      }
    }
  }

  return a[target] / by;
}

void kill() {
  int tot = 1 << w;
  for (int i = 0; i < m; ++i) {
    copy(b, b + tot, a);
    cout << fun(s[i]) << "\n";
  }
}

int main() {
#ifdef LOCAL
  assert(freopen("f.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}