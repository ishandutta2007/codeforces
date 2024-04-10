#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 107;


ll s, x;

void read() {
  cin >> s >> x;
}


void kill() {
  ll t = s - x;
  if (t < 0 || t % 2 != 0) {
    cout << "0\n";
    return;
  }
  t /= 2;

  if (t & x) {
    cout << "0\n";
    return;
  }

  ll ans = 1ll << __builtin_popcountll(x);
  if (x == s)
    ans -= 2;

  cout << ans << endl;
}


int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}