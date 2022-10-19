#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 107;

ll n, k;

void read() {
  cin >> n >> k;
}


void kill() {
  ll ans = 0;
  for (int l = 1, r = n, i = 0; i < k && l < r; ++i, ++l, --r) {
    ans += 2 * (r - l) - 1;
  }
  cout << ans << endl;
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}