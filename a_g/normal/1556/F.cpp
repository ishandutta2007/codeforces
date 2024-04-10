#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1000000007;

ll inversemod(ll p, ll q) {
  p %= q;
  if (p < 0) p += q;
  if (p == 1) return 1;
  ll k = q/p;
  ll b = inversemod(q-k*p, p);
  ll a = (1-b*q)/p % q;
  if (a < 0) a += q;
  return a;
}

vector<vector<ll>> w(20, vector<ll>(20));
vector<vector<ll>> u(20, vector<ll>((1<<14) + 5, 1));
vector<ll> a(20);
int n;

ll G(vector<int>& winners, vector<int>& losers) {
  ll ans = 1;
  int t = 0;
  for (int j: losers) t ^= (1<<j);
  for (int i: winners) {
    ans = ans * u[i][t] % MOD;
  }
  return ans;
}

int main () {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      w[i][j] = a[i]*inversemod(a[i]+a[j], MOD) % MOD;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < (1<<n); k++) {
      for (int j = 0; j < n; j++) {
        if ((k>>j)&1) u[i][k] = u[i][k] * w[i][j] % MOD;
      }
    }
  }
  vector<ll> P(1<<n, 1);

  ll ans = 0;
  for (int i = 1; i < (1<<n); i++) {
    vector<int> winners;
    vector<int> losers;
    for (int j = 0; j < n; j++) {
      if ((i>>j)&1) {
        winners.push_back(j);
      }
      else {
        losers.push_back(j);
      }
    }
    int m = winners.size();
    for (int j = 1; j < (1<<m)-1; j++) {
      int s = 0;
      vector<int> sub;
      vector<int> out;
      for (int k = 0; k < m; k++) {
        if ((j>>k)&1) {
          sub.push_back(winners[k]);
          s ^= (1<<winners[k]);
        }
        else {
          out.push_back(winners[k]);
        }
      }
      P[i] -= P[s]*G(sub, out);
      P[i] %= MOD;
    }
    ans += m*(P[i]*G(winners, losers) % MOD) % MOD;
    ans %= MOD;
  }
  if (ans < 0) ans += MOD;

  cout << ans << endl;
}