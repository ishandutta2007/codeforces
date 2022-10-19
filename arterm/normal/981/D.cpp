#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 55;

ll a[M];
int n, k;
bool d[M][M];

void read() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
}

bool can(ll mask) {
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= k; ++j)
      d[i][j] = false;
  d[0][0] = true;

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= k; ++j) {
      ll sum = 0;
      for (int t = 1; t <= i; ++t) {
        sum += a[i - t];
        if ((sum & mask) == mask)
          d[i][j] |= d[i - t][j - 1];
      }
    }

  return d[n][k];
}

void kill() {
  ll cur = 0;
  for (ll i = 60; i >= 0; --i) {
    if (can(cur | (1ll << i)))
      cur |= 1ll << i;
  }
  cout << cur << endl;
}


int main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}