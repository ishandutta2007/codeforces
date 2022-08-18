#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_A = 2e7 + 5;

int cnt [MAX_A];
ll dp [MAX_A];
int sieve [MAX_A];

int main () {
  vector<int> primes;
  for (int i = 2; i < MAX_A; i++) {
    if (!sieve[i]) {
      primes.push_back(i);
      for (int j = i; j < MAX_A; j += i) {
        sieve[j] = 1;
      }
    }
  }
  cerr << " primes done " << endl;
  
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    cnt[x]++;
  }

  for (int p : primes) {
    for (int i = (MAX_A + p - 1) / p - 1; i >= 1; i--) {
      cnt[i] += cnt[i * p];
    }
  }
  cerr << " supsets done " << endl;
  
  for (int i = MAX_A - 1; i >= 1; i--) {
    dp[i] = (ll) i * (ll) cnt[i];
    for (int p : primes) {
      if (p * i >= MAX_A) break;
      int k = p * i;
      dp[i] = max(dp[i], dp[k] + (ll) i * (ll) (cnt[i] - cnt[k]));
    }
  }

  cout << dp[1] << '\n';
}