#include <iostream>
#include <set>

using namespace std;

const int MAX_N = 2e5 + 5;

bool spec [MAX_N];
int dp [MAX_N];

void solve () {
  int n;
  cin >> n;

  for (int i = 'a'; i <= 'z'; i++) {
    spec[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    dp[i] = -1;
  }

  string s;
  cin >> s;

  int K;
  cin >> K;

  for (int i = 0; i < K; i++) {
    char c;
    cin >> c;

    spec[c] = 1;
  }

  int ans = 0;
  for (int i = n - 2; i >= 0; i--) {
    if (spec[s[i + 1]]) {
      dp[i] = 1;
    } else if (dp[i + 1] != -1) {
      dp[i] = 1 + dp[i + 1];
    }

    ans = max(ans, dp[i]);
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