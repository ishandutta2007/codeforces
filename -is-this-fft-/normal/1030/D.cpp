#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main () {
  ll n, m, k;
  cin >> n >> m >> k;

  if ((2 * n * m) % k != 0) {
    cout << "NO" << endl;
    return 0;
  }

  vector<int> divs;
  for (int i = 1; i * i <= k; i++) {
    if (k % i == 0) {
      divs.push_back(k / i);
      divs.push_back(i);
    }
  }

  for (int u : divs) {
    int v = k / u;
    if (2 * n % u == 0 && m % v == 0 && u != 1) {
      cout << "YES" << endl;
      cout << 2 * n / u << " " << 0 << endl;
      cout << 0 << " " << m / v << endl;
      cout << 0 << " " << 0 << endl;
      return 0;
    } else if (n % u == 0 && 2 * m % v == 0 && v != 1) {
      cout << "YES" << endl;
      cout << n / u << " " << 0 << endl;
      cout << 0 << " " << 2 * m / v << endl;
      cout << 0 << " " << 0 << endl;
      return 0;
    }
  }

  cout << "NO" << endl;
  return 0;
}