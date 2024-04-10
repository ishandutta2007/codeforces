#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll yo[4] = {0, 2, 3, 1};

ll getOne (ll x) {
  ll lg = 0;
  while (x >= (1LL << (lg + lg))) ++lg;
  ll lim = 1LL << (lg + lg - 2);
  return lim + (x - lim) / 3; 
}

ll get (ll bit, ll x) {
  ll ret = 0;
  for (ll i = bit; i; i -= 2) {
    ll split = 1LL << (i - 2);
    if (x < split) ret |= yo[0] << (i - 2);
    else if (x < 2 * split) ret |= yo[1] << (i - 2), x -= split;
    else if (x < 3 * split) ret |= yo[2] << (i - 2), x -= 2 * split;
    else ret |= yo[3] << (i - 2), x -= 3 * split; 
  }
  return ret;
}

ll getTwo (ll x) {
  ll lg = 0;
  while (x >= (1LL << (lg + lg))) ++lg;
  ll lim = 1LL << (lg + lg - 2);
  return (lim << 1) | get(lg + lg - 2, (x - lim) / 3); 
}

int t; ll n;

int main() {
  cin >> t;
  while (t--) {
    scanf("%lld", &n);
    if (n % 3 == 1) printf("%lld\n", getOne(n));
    else if (n % 3 == 2) printf("%lld\n", getTwo(n));
    else printf("%lld\n", getOne(n - 2) ^ getTwo(n - 1));
  }
  return 0;
}