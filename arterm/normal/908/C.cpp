#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;

const int M = 1010;

ll n;
ll r;
ll x[M];
ld y[M];

void read() {
  cin >> n >> r;
  for (int i = 0; i < n; ++i)
    cin >> x[i];
}

void kill() {
  for (int i = 0; i < n; ++i) {
    y[i] = r;
    for (int j = 0; j < i; ++j) {
      ll d = abs(x[i] - x[j]);
      if (d <= 2 * r) {
        y[i] = max(y[i], y[j] + sqrtl(4 * r * r - d * d));
      }
    }
    cout << y[i] << " ";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
#ifdef LOCAL
  freopen("b.in", "r", stdin);
#endif

  cout.precision(9);
  cout << fixed;

  read();
  kill();
    
  return 0;
}