#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1000000007;

int inversemod(int p, int q) {
  p %= q;
  if (p < 0) p += q;
  if (p == 1) return 1;
  int k = q/p;
  int b = inversemod(q-k*p, p);
  int a = (1-1LL*b*q)/p % q;
  if (a < 0) a += q;
  return a;
}

int expmod(ll a, ll b, int m) {
  int res = 1;
  a = a % m; 
  if (a == 0) return 0;
  while (b > 0) {
    if (b & 1) {
      res = (res*a) % m;
    }
    b = b>>1;
    a = (a*a) % m;
  }
  return res;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m, rb, cb, rd, cd, p;
    cin >> n >> m >> rb >> cb >> rd >> cd >> p;
    vector<int> t1;
    vector<int> t2;
    if (rd >= rb) {
      t1.push_back(rd-rb);
      if (rd != n && rd != 1) {
        t1.push_back(rd-rb+2*(n-rd));
      }
    }
    else {
      t1.push_back(2*n-rb-rd);
      if (rd != 1) {
        t1.push_back(2*n-rb-rd + 2*(rd-1));
      }
    }
    if (cd >= cb) {
      t2.push_back(cd-cb);
      if (cd != m && cd != 1) {
        t2.push_back(cd-cb+2*(m-cd));
      }
    }
    else {
      t2.push_back(2*m-cb-cd);
      if (cd != 1) {
        t2.push_back(2*m-cb-cd + 2*(cd-1));
      }
    }
    
    int x = 2*(n-1);
    int y = 2*(m-1);
    vector<ll> res;
    for (int i: t1) {
      for (int j = 0; j < y; j++) {
        res.push_back(1LL * j * x + i);
      }
    }
    for (int j: t2) {
      for (int i = 0; i < x; i++) {
        res.push_back(1LL * i * y + j);
      }
    }
    sort(res.begin(), res.end());
    res.resize(distance(res.begin(), unique(res.begin(), res.end())));
    p = 1LL * p * inversemod(100, MOD) % MOD;
    int u = p;
    int k = res.size();
    int S = 0;
    for (int i = 0; i < k; i++) {
      S += 1LL * u * (res[i] % MOD) % MOD;
      S %= MOD;
      u = 1LL * u * (MOD+1-p) % MOD;
    }
    int v = expmod(MOD+1-p, k, MOD);
    S += v * (1LL * x * y % MOD) % MOD;
    S %= MOD;
    assert((v-1)%MOD);
    int T = 1LL * S * inversemod(MOD+1-v, MOD) % MOD;
    cout << (T+MOD)%MOD << endl;
  }
}