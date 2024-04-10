#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const int M = 1001000;
const int mod = 1e9 + 7;

bool u[M];
vector<ll> ps;

void sito() {
  for (int i = 2; i < M; ++i)
    if (!u[i]) {
      ps.push_back(i);
      for (int j = 2 * i; j < M; j += i)
        u[j] = true;
    }
}

ll n, k;

ll phi(ll n) {
  ll ans = 1;
  for (ll p : ps) {
    if (p * p > n)
      break;
    if (n % p == 0) {
      ans *= p - 1;
      n /= p;
      while (n % p == 0) {
        n /= p;
        ans *= p;
      }
    }
  }

  if (n > 1)
    ans *= n - 1;

  return ans;
}

int main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  sito();

  ll n, k;
  cin >> n >> k;
  k = (k + 1) / 2;

  while (n > 1 && k > 0) {
    n = phi(n);
    --k;
  }

  cout << n % mod << endl;
}