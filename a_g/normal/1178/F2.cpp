#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 505;
int dp[2*N][2*N];
int c[2*N], minpos[N], maxpos[N], inter[N];
vector<int> indices[N];

// dp[l][r] = number of ways to do the interval [l, r], assuming the intervals
// [a, b] for the visible colors in [l, r] do not cross [l, r]

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  int len = 0;
  for (int i = 1; i <= m; i++) {
    int x;
    cin >> x;
    if (x == c[len]) continue;
    if (len+1 >= 2*N) break; // forgot this lol
    c[++len] = x;
    indices[x].push_back(len);
  }

  m = len;
  if (m >= 2*n) {
    cout << "0\n";
    return 0;
  }

  for (int i = 0; i < 2*N; i++) {
    fill(dp[i], dp[i]+2*N, 1);
  }

  for (int i = 1; i <= len; i++) maxpos[c[i]] = i;
  for (int i = len; i >= 1; i--) minpos[c[i]] = i;
  fill(inter, inter+N, -1);

  for (int d = 0; d < m; d++) {
    for (int l = 1; l+d <= m; l++) {
      int r = l+d;
      dp[l][r] = 0;

      int z = *min_element(c+l, c+r+1);
      if (minpos[z] >= l && maxpos[z] <= r) {
        int left = 0;
        int right = 0;
        for (int i = l-1; i < minpos[z]; i++) {
          left = (left+1LL*dp[l][i]*dp[i+1][minpos[z]-1]) % MOD;
        }
        for (int i = maxpos[z]; i <= r; i++) {
          right = (right+1LL*dp[maxpos[z]+1][i]*dp[i+1][r]) % MOD;
        }
        dp[l][r] = 1LL*left*right%MOD;
        if (inter[z] == -1) {
          inter[z] = 1;
          for (int i = 0; i < (int)indices[z].size()-1; i++) {
            inter[z] = 1LL*inter[z]*dp[indices[z][i]+1][indices[z][i+1]-1] % MOD;
          }
        }
        dp[l][r] = 1LL*dp[l][r]*inter[z]%MOD;
      }
    }
  }
  cout << dp[1][m] << '\n';
}