#include <iostream>

using namespace std;

typedef long long ll;

int main () {
  ll n, m, k;
  cin >> n >> m >> k;

  if (k > n + m - 2) {
    cout << -1 << endl;
    return 0;
  }

  if (n < m) swap(n, m);
  if (k <= m - 1) {
    cout << max((n / (k + 1)) * m, (m / (k + 1)) * n) << endl;
    return 0;
  } else if (k <= n - 1) {
    cout << (n / (k + 1)) * m << endl;
    return 0;
  }

  k -= n - 1;
  cout << m / (k + 1) << endl;
}