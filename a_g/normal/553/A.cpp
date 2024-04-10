#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
const int MOD = 1e9+7;
int freq[N];

int fact[N], invfact[N];

int inversemod(int p, int q) {
  // assumes p > 0
  // https://codeforces.com/blog/entry/23365
  return (p > 1 ? q-1LL*inversemod(q%p, p)*q/p : 1);
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

  int k;
  cin >> k;
  int spaces = 0;
  for (int i = 0; i < k; i++) {
    cin >> freq[i];
    spaces += freq[i];
  }
  int ans = 1;
  for (int i = k-1; i >= 0; i--) {
    ans = 1LL*ans*binommod(spaces-1, freq[i]-1) % MOD;
    spaces -= freq[i];
  }
  cout << ans << '\n';
}