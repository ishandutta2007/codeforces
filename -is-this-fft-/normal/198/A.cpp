#include <iostream>

using namespace std;

typedef long long ll;

int main () {
  ll k, b, n, t;
  cin >> k >> b >> n >> t;

  ll u = 0, cur = 1, kp = 1;
  while (u < n) {
    ll nxt = kp * (k + b - 1) + cur;
    if (nxt > t) {
      break;
    }

    kp *= k;
    u++;
    cur = nxt;
  }

  cout << n - u << endl;
}