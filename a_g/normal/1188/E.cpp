#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 998244353;
const int maxn = 2e6;
vector<ll> fact(maxn); 
vector<ll> invfact(maxn); 

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

ll binommod(int n, int k) {
  if (k < 0 || k > n) return 0;
  return fact[n] * (invfact[k]*invfact[n-k] % MOD) % MOD;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  fact[0] = 1;
  for (int i = 1; i < maxn; i++) {
    fact[i] = i*fact[i-1] % MOD;
  }
  invfact[maxn-1] = inversemod(fact[maxn-1], MOD);
  for (int i = maxn-1; i >= 1; i--) {
    invfact[i-1] = i*invfact[i] % MOD;
  }

  int k;
  cin >> k;
  vector<int> a(k);
  for (int i = 0; i < k; i++) cin >> a[i];
  sort(a.begin(), a.end());
  ll ans = 0;
  for (int i = 0; i < k; i++) {
    if (a[i] < i) {
      vector<int> needs(i);
      for (int j = 0; j <= i; j++) needs[a[j]]++;
      int fixedops = 0;
      for (int j = 0; j < i; j++) {
        if (fixedops > j) break;
        ans += binommod(j+k-fixedops-1, k-1);
        ans %= MOD;
        fixedops += needs[j];
      }
      cout << ans << endl;
      return 0;
    }
  }

  vector<int> rescount(k, 0);
  int blocks = 0;
  for (int val: a) {
    rescount[val % k]++;
    blocks += val/k;
  }
  for (int i = 0; i < k; i++) {
    blocks += 1-rescount[i];
    ans += binommod(blocks+k-1, k-1);
    ans %= MOD;
  }
  cout << ans << endl;
}