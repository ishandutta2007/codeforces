#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 7070;

int n;
ll a[M], b[M];
bool u[M];

void read() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int j = 0; j < n; ++j) {
    cin >> b[j];
  }
}

void kill() {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (j != i && a[i] == a[j]) {
        u[i] = true;
        break;
      }

  for (int i = 0; i < n; ++i)
    if (!u[i])
      for (int j = 0; j < n; ++j)
        if (u[j] && (a[i] & a[j]) == a[i]) {
          u[i] = true;
          break;
        }

  ll ans = 0;
  int m = 0;
  for (int i = 0; i < n; ++i)
    if (u[i]) {
      ans += b[i];
      m++;
    }

  if (m >= 2)
    cout << ans << "\n";
  else
    cout << "0\n";
}

int main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}