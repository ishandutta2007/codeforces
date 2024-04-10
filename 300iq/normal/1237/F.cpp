#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int M = 998244353;
  
int dp[5000][5000];
int comb[5000][5000];
int fact[5000];

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int h, w, n;
  cin >> h >> w >> n;
  comb[0][0] = 1;
  fact[0] = 1;
  int ok = max(h, w);
  for (int i = 0; i <= ok; i++) {
    if (i) fact[i] = (fact[i - 1] * (ll) i) % M;
    for (int j = 0; j <= ok; j++) {
      if (i) {
        comb[i][j] += comb[i - 1][j];
      }
      if (i && j) {
        comb[i][j] += comb[i - 1][j - 1];
      }
      if (comb[i][j] >= M) {
        comb[i][j] -= M;
      }
    }
  }
  vector <bool> vis_r(h), vis_c(w);
  for (int i = 0; i < n; i++) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    r1--, c1--, r2--, c2--;
    vis_r[r1] = vis_r[r2] = true;
    vis_c[c1] = vis_c[c2] = true;
  }
  auto ans = [&] (vector <bool> vis) {
    int n = (int) vis.size();
    for (int i = 0; i <= n; i++) for (int j = 0; j <= i; j++) dp[i][j] = 0;
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        if (dp[i][j]) {
          if (!vis[i] && (i + 1 < n && !vis[i + 1])) {
            dp[i + 2][j + 1] += dp[i][j];
            if (dp[i + 2][j + 1] >= M) {
              dp[i + 2][j + 1] -= M;
            }
          }
          dp[i + 1][j] += dp[i][j];
          if (dp[i + 1][j] >= M) dp[i + 1][j] -= M;
        }
      }
    }
    vector <int> value(n + 1);
    for (int i = 0; i <= n; i++) {
      value[i] = dp[n][i];
    }
    return value;
  };
  int free_r = 0, free_c = 0;
  for (int i = 0; i < h; i++) if (!vis_r[i]) free_r++;
  for (int i = 0; i < w; i++) if (!vis_c[i]) free_c++;
  auto r = ans(vis_r);
  auto c = ans(vis_c);
  int value = 0;
  for (int i = 0; i <= h; i++) {
    for (int j = 0; j <= w; j++) {
      if (free_r - 2 * i - j >= 0 && free_c - 2 * j - i >= 0) {
        int ret = (r[i] * (ll) c[j]) % M;
        ret = (ret * (ll) comb[free_r - 2 * i][j]) % M;
        ret = (ret * (ll) comb[free_c - 2 * j][i]) % M;
        ret = (ret * (ll) fact[i]) % M;
        ret = (ret * (ll) fact[j]) % M;
        value += ret;
        if (value >= M) value -= M;
      }
    }
  }
  cout << value << endl;
}