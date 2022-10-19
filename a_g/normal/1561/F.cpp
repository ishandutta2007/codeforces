#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
using namespace __gnu_pbds;
using namespace std;

const ll MOD = 998244353;
const int maxn = 4e5+5;

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

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  vector<ll> fact(maxn);
  vector<ll> invfact(maxn);
  fact[0] = 1;
  for (int i = 1; i < maxn; i++) {
    fact[i] = fact[i-1]*i % MOD;
  }
  invfact[maxn-1] = inversemod(fact[maxn-1], MOD);
  for (int i = maxn-2; i >= 0; i--) {
    invfact[i] = invfact[i+1]*(i+1) % MOD;
  }
  
  set<int> marked;
  set<int> erased;
  ordered_set a;
  for (int i = 1; i < maxn; i++) {
    a.insert(i);
  }
  while (T--) {
    marked.clear();
    erased.clear();
    int n, m;
    cin >> n >> m;
    vector<int> insertions(m);
    while (m--) {
      int x, y;
      cin >> x >> y;
      insertions[m] = y;
    }
    for (int y: insertions) {
      int p = *a.find_by_order(y-1);
      int q = *a.find_by_order(y);
      marked.insert(q);
      erased.insert(p);
      a.erase(p);
    }
    int k = marked.size();
    for (int k: erased) {
      a.insert(k);
    }
    ll ans = (((fact[2*n-1-k] * invfact[n]) % MOD) * invfact[n-1-k]) % MOD;
    cout << ans << endl;
  }
}