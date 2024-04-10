#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

ll gcd(ll x, ll y) {
  while (x) {
    y %= x;
    swap(x, y);
  }
  return y;
}

ll s(ll x) {
  return x * (x + 1) / 2;
}

const int M = 200200;

int f[M];
bool used[M];
int q[2 * M], qs = M, qf = M;
ll a, b;

int x[M];

void bfs() {
  q[qf++] = 0;
  f[0] = 0;
  used[0] = true;
  
  while (qs < qf) {
    int v = q[qs++];
    if (v >= b && !used[v - b]) {
      q[--qs] = v - b;
      f[v - b] = f[v];
      used[v - b] = true;
    }

    if (v + a < a + b && !used[v + a]) {
      q[qf++] = v + a;
      f[v + a] = max<int>(f[v], v + a);
      used[v + a] = v + a;
    }
  }

  for (int i = 0; i < a + b; ++i)
    if (used[i])
      x[f[i]]++;
  for (int i = 1; i < a + b; ++i)
    x[i] += x[i - 1];
}

int main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  ll m;
  cin >> m >> a >> b;
  ++m;

  ll g = gcd(a, b);

  ll ans = 0;

  bfs();
  for (int i = 0; i < a + b && i < m; ++i) {
    ans += x[i];
    //cerr << i << " : " << x[i] << "\n";
  }

  ll t = a + b;

  if (m >= t) {
    while (m % g != 0) {
      ans += ((m - 1) / g) + 1;
      --m;
    }

    ans += (s(m / g) - s(t / g)) * g;
  }

  cout << ans << "\n";
}