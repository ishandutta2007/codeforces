#include <bits/stdc++.h>
using namespace std;

const int N = 15;
int dp[1<<N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  int n, m, p;
  cin >> n >> m >> p;
  vector<long long> a(n);
  for (long long& x: a) {
    string s;
    cin >> s;
    for (int i = 0; i < m; i++) {
      if (s[i] == '1') x ^= 1LL<<i;
    }
  }

  long long ans = 0;
  int trials = 20;
  while (trials--) {
    long long b = a[rng()%n];
    vector<long long> submasks;
    for (long long z = b;; z = (z-1)&b) {
      submasks.push_back(z);
      if (!z) break;
    }
    reverse(submasks.begin(), submasks.end());
    for (long long x: a) {
      int k = lower_bound(submasks.begin(), submasks.end(), x&b)-submasks.begin();
      dp[k]++;
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < (1<<N); j++) {
        if ((j>>i)&1) {
          dp[j^(1<<i)] += dp[j];
        }
      }
    }
    
    for (int i = 0; i < (1<<N); i++) {
      if (dp[i] >= (n+1)/2 && __builtin_popcount(i) > __builtin_popcountll(ans)) {
        ans = submasks[i];
      }
    }
    fill(dp, dp+(1<<N), 0);
  }

  for (int i = 0; i < m; i++) {
    cout << ((ans>>i)&1);
  }
  cout << '\n';
}