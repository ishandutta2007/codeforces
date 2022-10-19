#include <bits/stdc++.h>
using namespace std;

vector<int> primes;
const int N = 2e7+2;
bool is_prime[N];
int counts[N];
long long dp[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  fill(is_prime, is_prime+N, 1);
  for (int i = 2; i < N; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
      for (int j = 2*i; j < N; j += i) {
        is_prime[j] = 0;
      }
    }
  }

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    counts[a]++;
  }
  for (int p: primes) {
    for (int i = (N-1)/p; i >= 1; i--) {
      counts[i] += counts[i*p];
    }
  }
  for (int i = N-1; i >= 1; i--) {
    if (counts[i]) {
      dp[i] = 1LL*i*counts[i];
      for (int p: primes) {
        int j = p*i;
        if (j >= N) break;
        dp[i] = max(dp[i], dp[j] + 1LL*i*(counts[i]-counts[j]));
      }
    }
  }
  cout << dp[1] << '\n';
}