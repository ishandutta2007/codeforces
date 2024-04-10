#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> primes;
const int maxn = 5e6+2;
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  vector<int> is_prime(maxn, 1);
  for (int i = 2; i < maxn; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
      for (int j = 2*i; j < maxn; j += i) {
        is_prime[j] = 0;
      }
    }
  }
  int n;
  cin >> n;
  vector<int> rawcounts(maxn);
  vector<ll> counts(maxn);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    counts[a]++;
  }
  for (int p: primes) {
    for (int i = (maxn-1)/p; i >= 1; i--) {
      counts[i] += counts[i*p];
    }
  }
  vector<ll> dp(maxn);
  for (int i = maxn-1; i >= 1; i--) {
    dp[i] = counts[i]*i;
    if (dp[i]) {
      for (int p: primes) {
        int j = p*i;
        if (j >= maxn) break;
        dp[i] = max<ll>(dp[i], dp[j] + i*(counts[i]-counts[j]));
      }
    }
  }
  cout << dp[1] << '\n';
}