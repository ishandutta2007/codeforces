#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<long long> l(n);
  for (long long& d: l) {
    cin >> d;
    d *= 8; // to simplify calculations (does this even work?)
  }
  string s;
  cin >> s;
  long long ans = 0;

  bool seen_water = 0;
  bool seen_grass = 0;

  long long fly_water = 0;
  long long fly_grass = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'G') {
      // trade distance spent flying over water for distance spent flying over
      // grass
      long long u = min(l[i], 2*fly_water);
      ans += u;
      fly_water -= u/2;
      fly_grass += u;
      ans += u;
      ans += 3*(l[i]-u);
      fly_grass += (l[i]-u)/2;
      seen_grass = 1;
    }
    else if (s[i] == 'W') {
      ans += 2*l[i];
      fly_water += l[i]/2;
      seen_water = 1;
    }
    else {
      long long u = min(l[i], 2*fly_water);
      ans += u;
      fly_water -= u/2;
      ans += u;
      l[i] -= u;

      u = min(l[i], 2*fly_grass);
      ans += 2*u;
      fly_grass -= u/2;
      ans += u;
      l[i] -= u;
      if (seen_water) {
        ans += 4*l[i];
        l[i] = 0;
      }
      else {
        assert(seen_grass);
        ans += 6*l[i];
      }
    }
  }
  cout << ans/8 << '\n';
}