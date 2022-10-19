#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const int M = 123;
int n, p[M];
bool used[M];

ll gcd(ll x, ll y) {
  while (x) {
    y %= x;
    swap(x, y);
  }
  return y;
}

ll lcm(ll x, ll y) {
  return x / gcd(x, y) * y;
}

void read() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
  }
}

void kill() {
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j)
      if (p[i] == p[j]) {
        cout << -1 << endl;
        exit(0);
      }

  ll ans = 1;

  for (int i = 0; i < n; ++i)
    if (!used[i]) {
      int x = i;
      int len = 0;
      while (!used[x]) {
        ++len;
        used[x] = true;
        x = p[x];
      }

      if (len % 2 == 0)
        len /= 2;

      ans = lcm(ans, len);
    }

  cout << ans << endl;
}

int main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}