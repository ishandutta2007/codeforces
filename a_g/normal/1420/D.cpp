#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 6e5+100;
int fact[N];
int invfact[N];
int additions[N];
int removals[N];
int additions2[N];
int removals2[N];

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

int binommod(int n, int k) {
  if (k < 0 || k > n) return 0;
  return fact[n] * (1LL*invfact[k]*invfact[n-k] % MOD) % MOD;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = 1LL*i*fact[i-1] % MOD;
  }
  invfact[N-1] = inversemod(fact[N-1], MOD);
  for (int i = N-1; i >= 1; i--) {
    invfact[i-1] = 1LL*i*invfact[i] % MOD;
  }

  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> lamps(n);
  set<int> times;
  map<int, int> compressor;
  for (int i = 0; i < n; i++) {
    cin >> lamps[i].first >> lamps[i].second;
    times.insert(lamps[i].first);
    times.insert(lamps[i].second);
  }
  int id = 0;
  for (int time: times) {
    compressor[time] = id++;
  }

  for (int i = 0; i < n; i++) {
    lamps[i].first = compressor[lamps[i].first];
    lamps[i].second = compressor[lamps[i].second];
    additions[lamps[i].first]++;
    removals[lamps[i].second]++;
    if (lamps[i].first < lamps[i].second) {
      additions2[lamps[i].first]++;
      removals2[lamps[i].second-1]++;
    }
  }

  int ans = 0;
  int curr = 0;
  for (int i = 0; i < N; i++) {
    curr += additions[i];
    ans += binommod(curr, k);
    ans %= MOD;
    curr -= removals[i];
  }

  curr = 0;
  for (int i = 0; i < N; i++) {
    curr += additions2[i];
    ans -= binommod(curr, k);
    ans %= MOD;
    curr -= removals2[i];
  }

  cout << (ans+MOD)%MOD << '\n';
}