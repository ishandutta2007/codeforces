#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 1e5+5;
int fact[N];
int invfact[N];


int inversemod(int p, int q) {
  // assumes p > 0
  // https://codeforces.com/blog/entry/23365
  return (p > 1 ? q-1LL*inversemod(q%p, p)*q/p : 1);
}

int binommod(int n, int k) {
  if (k < 0 || k > n) return 0;
  return fact[n] * (1LL*invfact[k]*invfact[n-k] % MOD) % MOD;
}

int binary_count(vector<long long>& a, long long x) {
  return upper_bound(a.begin(), a.end(), x)-lower_bound(a.begin(), a.end(), x);
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

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x: a) cin >> x;
    vector<long long> s(n+1), sr(n+1);
    for (int i = 0; i < n; i++) {
      s[i+1] = s[i]+a[i];
      sr[i+1] = sr[i]+a[n-1-i];
    }
    vector<long long> all_vals;
    for (long long x: s) all_vals.emplace_back(x);
    for (long long x: sr) all_vals.emplace_back(x);
    sort(all_vals.begin(), all_vals.end());
    all_vals.resize(unique(all_vals.begin(), all_vals.end())-all_vals.begin());
    int ans = 1;
    for (long long x: all_vals) {
      if (2*x >= s[n]) break;
      int a = binary_count(s, x)-(x==0);
      int b = binary_count(sr, x)-(x==0);
      ans = 1LL*ans*binommod(a+b, a) % MOD;
    }
    if (s[n]%2 == 0) {
      int a = binary_count(s, s[n]/2)-2*(s[n]==0);
      for (int i = 0; i < a; i++) {
        ans = 2LL*ans % MOD;
      }
    }
    cout << ans << '\n';
  }
}