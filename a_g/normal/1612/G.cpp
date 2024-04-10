#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 1e6+5;
vector<ll> fact(maxn); 

const ll MOD = 1000000007;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  fact[0] = 1;
  for (int i = 1; i < maxn; i++) {
    fact[i] = i*fact[i-1] % MOD;
  }

  int m;
  cin >> m;
  vector<ll> c(m);
  for (int i = 0; i < m; i++) cin >> c[i];
  sort(c.begin(), c.end());
  vector<ll> codd;
  vector<ll> ceven;
  for (ll i: c) {
    if (i&1) codd.push_back(i);
    else ceven.push_back(i);
  }

  vector<ll> counts(maxn, 0);
  ll ways = 1;
  for (int n = 1; n <= maxn/2; n++) {
    ll count = ceven.end()-lower_bound(ceven.begin(), ceven.end(), 2*n);
    counts[2*n-1] = count;
    ways *= (fact[count]*fact[count] % MOD);
    ways %= MOD;
  }
  for (int n = 0; n <= maxn/2; n++) {
    ll count = codd.end()-lower_bound(codd.begin(), codd.end(), 2*n);
    counts[2*n] = count;
    if (n == 0) ways *= fact[count];
    else ways *= (fact[count]*fact[count] % MOD);
    ways %= MOD;
  }
  ll maxf = 0;
  ll total = counts[0];
  for (ll i = 1; i <= maxn; i++) {
    maxf += (i*counts[i] % MOD)*(total+counts[i]) % MOD;
    total += 2*counts[i];
    total %= MOD;
    maxf %= MOD;
  }
  cout << maxf << " " << ways << endl;
  
}