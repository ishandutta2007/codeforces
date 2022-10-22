#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

void solve(bool read = true) {
  int n;
  cin >> n;

  li S = 0;
  li SA = 0;

  li C = 0;

  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    S += a[i] * a[i];
    SA += a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    S += b[i] * b[i];
    SA += b[i];
  }

  const int maxS = 100500;
  bitset<100500> can{};
  can[0] = 1;

  for (int i = 0; i < n; ++i) {
    can = (can << a[i]) | (can << b[i]);
  }

  li minX = 1e18;

  for (int i = 0; i < maxS; ++i) {
    if (can[i]) {
      li X = (i * i + (SA - i) * (SA - i) - S);
      //cout << "can " << i << " " << X << "\n";
      //assert(X % 2 == 0);
      //X /= 2;
      minX = min(minX, X);
    }
  }

  cout << minX + S * (n - 1) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int nt = 1;
  cin >> nt;

  for (int i = 0; i < nt; ++i) {
    solve(true);
  }

  return 0;
}