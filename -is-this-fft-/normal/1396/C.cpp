#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 1e6 + 5;
const ll INF = 1e18 + 300;

ll monsters [MAX_N];
ll A [MAX_N];
ll B [MAX_N];

ll sfx [MAX_N];
ll dp [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  ll R1, R2, R3, D;
  cin >> R1 >> R2 >> R3 >> D;

  for (int i = 1; i <= n; i++) {
    cin >> monsters[i];
  }

  for (int i = 1; i <= n; i++) {
    A[i] = min((monsters[i] + 2) * R1, R2 + R1);
    B[i] = min(monsters[i] * R1 + R3, A[i] + 2 * D);
    A[i] += D;
  }

  sfx[n] = B[n];
  for (int i = n - 1; i >= 1; i--) {
    sfx[i] = sfx[i + 1] + A[i];
  }

  for (int i = 0; i <= n; i++) {
    dp[i] = INF;
  }
  
  ll ans = INF;
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    dp[i + 1] = min(dp[i + 1], dp[i] + B[i + 1]);
    dp[i + 2] = min(dp[i + 2], dp[i] + A[i + 1] + A[i + 2]);
    ans = min(ans, dp[i] + sfx[i + 1]);
  }
  ans = min(ans, dp[n]);

  cout << ans + (n - 1) * D << endl;
}