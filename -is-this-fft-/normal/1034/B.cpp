#include <iostream>

using namespace std;

typedef long long ll;

int one [6] = {0, 1, 2, 3, 2, 1};

int main () {
  ll n, m;
  cin >> n >> m;

  ll ans = n * m;

  if (n > m) swap(n, m);
  if (n == 1) {
    ans -= one[m % 6];
  } else if (n == 2 && m == 2) {
    ans -= 4;
  } else if (n == 2 && m == 3) {
    ans -= 2;
  } else if (n == 2 && m == 7) {
    ans -= 2;
  } else if (n % 2 == 1 && m % 2 == 1) {
    ans -= 1;
  }
  cout << ans << endl;
}