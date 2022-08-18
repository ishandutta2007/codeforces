#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_N = 1e7 + 5;

ll pairc (ll n) {
  return (n * (n - 1)) / 2;
}

int factor [MAX_N];
int sieve [MAX_N];
int cspf [MAX_N];
int ccspf [MAX_N];
int mobius [MAX_N];

int main () {
  ll n;
  cin >> n;

  vector<ll> primes;
  for (ll i = 2; i <= n; i++) {
    if (!sieve[i]) {
      primes.push_back(i);
      for (ll j = i; j <= n; j += i) {
        factor[j] = i;
        if (!sieve[j]) {
          sieve[j] = 1;
          cspf[i]++;
        }
      }
    }
  }

  for (ll i = 2; i <= n; i++) {
    if (factor[i] == i) {
      mobius[i] = 1;
    } else if (factor[i / factor[i]] == factor[i]) {
      mobius[i] = 0;
    } else {
      mobius[i] = -mobius[i / factor[i]];
    }
  }

  ll isol = 0;
  for (ll i = 2; i <= n; i++) {
    if (factor[i] != i || 2 * i <= n) {
      isol++;
    } else {
      cspf[i]--;
    }
  }

  ccspf[n] = cspf[n];
  for (int i = n - 1; i >= 0; i--) {
    ccspf[i] = cspf[i] + ccspf[i + 1];
  }
  
  ll ans = isol * (isol - 1);

  ll bigp = 0;
  for (int p : primes) {
    if (2 * p <= n) {
      // count number of pairs (u, v) with spf(u) = p, spf(v) > p
      // and spf(u) spf(v) > n
      int s = n / p + 1; // the smallest number s.t. ps > n
      if (s <= p) s = p + 1;

      bigp += (ll) cspf[p] * (ll) ccspf[s];
    }
  }
  ans += bigp;
  
  ll smallp = 0;
  for (ll i = 2; i <= n; i++) {
    smallp += (ll) mobius[i] * pairc(n / i);
  }
  ans -= smallp;

  cout << ans << endl;
}