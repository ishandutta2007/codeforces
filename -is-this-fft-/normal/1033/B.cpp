#include <iostream>

using namespace std;

typedef long long ll;

bool isprime (ll num) {
  for (ll i = 2; i * i <= num; i++) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

void solve () {
  ll a, b;
  cin >> a >> b;

  if (a - b == 1) {
    if (isprime(a + b)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else {
    cout << "NO" << endl;
  }
}

int main () {
  int testc;
  cin >> testc;

  for (int t = 0; t < testc; t++) {
    solve();
  }
}