#include <bits/stdc++.h>
using namespace std;

const int N = 17;
const int M = 1005;
const int MOD = 998244353;
int dp[N+1][1<<N];
int pw[N+1][M];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  for (int i = 1; i <= N; i++) {
    pw[i][0] = 1;
    for (int j = 1; j < M; j++) {
      pw[i][j] = 1LL * i * pw[i][j-1] % MOD;
    }
  }

  int n;
  string s;
  cin >> n >> s;
  int choices = 0;
  for (char c: s) if (c == '?') choices++;
  for (int i = 1; i <= N; i++) {
    // string has i characters
    int mask = 0;
    int free = choices;
    auto modify = [&] (int x, int y) {
      if (s[x] == '?' && s[y] == '?') {
        free--;
      }
      else if (s[x] == '?') {
        mask |= 1<<(s[y]-'a');
        free--;
      }
      else if (s[y] == '?') {
        mask |= 1<<(s[x]-'a');
        free--;
      }
      else if (s[x] != s[y]) return false;
      dp[i][mask] = (dp[i][mask]+pw[i][free])%MOD;
      return true;
    };

    for (int j = 0; j < n; j++) {
      // palindromes centered at j
      mask = 0;
      free = choices;
      dp[i][mask] = (dp[i][mask]+pw[i][free])%MOD;
      for (int k = 1; k <= j && j+k < n; k++) {
        if (!modify(j-k, j+k)) break;
      }
    }


    for (int j = 0; j < n-1; j++) {
      // palindromes with j at left of center
      mask = 0;
      free = choices;
      if (!modify(j, j+1)) continue;
      for (int k = 1; k <= j && j+k+1 < n; k++) {
        if (!modify(j-k, j+k+1)) break;
      }
    }

    for (int j = 0; j < N; j++) {
      for (int mask = 0; mask < (1<<N); mask++) {
        if (!(mask&(1<<j))) {
          dp[i][mask|(1<<j)] = (dp[i][mask|(1<<j)]+dp[i][mask]) % MOD;
        }
      }
    }
  }

  int q;
  cin >> q;
  while (q--) {
    string t;
    cin >> t;
    int mask = 0;
    for (char c: t) {
      mask |= 1<<(c-'a');
    }
    cout << dp[t.size()][mask] << '\n';
  }
}