#include <iostream>

using namespace std;

typedef long long ll;
typedef long double ld;

ll choose (ll n, int k) {
  ll p = 1, q = 1;
  
  for (int i = 0; i < k; i++) {
    p *= n - i;
    q *= i + 1;
  }

  return p / q;
}

bool is_good (ll n, ll m, ll P) {
  ll L = 2 * choose(m, 3) + 2 * choose(m, 2) * choose(n - m, 1)
    + choose(m, 1) * choose(n - m, 2);
  L *= 10000;
  ll R = 2 * P * choose(n, 3);
  return L >= R;
}

int main () {
  int n;
  ld dP;
  cin >> n >> dP;

  ll P = 10000 * dP + 0.5;
  for (int i = 0; i <= n; i++) {
    if (is_good(n, i, P)) {
      cout << i << endl;
      return 0;
    }
  }
}