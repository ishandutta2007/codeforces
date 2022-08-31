#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll INF = 1e18 + 2000;

ll cost (const vector<ll> &hs, int i) {
  return max(0LL, 1 + max(hs[i - 1], hs[i + 1]) - hs[i]);
}

void solve () {
  int n;
  cin >> n;

  vector<ll> hs (n);
  for (int i = 0; i < n; i++) {
    cin >> hs[i];
  }

  ll ans;
  if (n % 2 == 1) {
    ans = 0;
    for (int i = 1; i < n - 1; i += 2) {
      ans += cost(hs, i);
    }
  } else {
    vector<ll> dp (n);
    dp[1] = cost(hs, 1);
    dp[2] = cost(hs, 2);
    for (int i = 3; i < n - 1; i++) {
      if (i % 2 == 0) {
        dp[i] = min(dp[i - 2], dp[i - 3]);
      } else {
        dp[i] = dp[i - 2];
      }

      dp[i] += cost(hs, i);
    }
    ans = min(dp[n - 2], dp[n - 3]);
  }
  
  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}