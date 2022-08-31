#include <iostream>

using namespace std;

typedef long long ll;

ll sq (ll x) {
  return x * x;
}

int main () {
  int n, m;
  cin >> n >> m;
  
  ll ans = 0;

  ll fullsum = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      if ((sq(i) + sq(j)) % m == 0) {
        fullsum++;
      }
    }
  }

  ll partsum = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n % m; j++) {
      if ((sq(i) + sq(j)) % m == 0) {
        partsum++;
      }
    }
  }

  ll corsum = 0;
  for (int i = 1; i <= n % m; i++) {
    for (int j = 1; j <= n % m; j++) {
      if ((sq(i) + sq(j)) % m == 0) {
        corsum++;
      }
    }
  }

  ll fullc = n / m;

  ans = fullc * fullc * fullsum + 2 * fullc * partsum + corsum;
  cout << ans << endl;
}