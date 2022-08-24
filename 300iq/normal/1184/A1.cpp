#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll r;
  cin >> r;
  for (ll x = 1; x * x <= r; x++) {
    ll need = r - x * x - x - 1;
    if (need > 0 && need % 2 == 0) {
      cout << x << ' ' << need / 2 << '\n';
      return 0;
    }
  }
  cout << "NO\n";
}