#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

int main () {
  ll length, k;
  cin >> length >> k;

  ll flip = (1 << k) - 1;
  ll cum = 0;
  map<ll, ll> cnt;
  cnt[0] = 1;
  for (ll i = 0; i < length; i++) {
    ll elem;
    cin >> elem;

    cum ^= elem;
    if (cnt.count(min(cum, flip ^ cum)) == 0) {
      cnt[min(cum, flip ^ cum)] = 0;
    }
    cnt[min(cum, flip ^ cum)]++;
  }

  ll ans = (ll) (length) * (length + 1) / 2;
  for (pair<ll, ll> pr : cnt) {
    ll num = pr.second;

    ll lf = num / 2;
    ans -= lf * (lf - 1) / 2;

    ll rf = (num + 1) / 2;
    ans -= rf * (rf - 1) / 2;
  }

  cout << ans << endl;
}