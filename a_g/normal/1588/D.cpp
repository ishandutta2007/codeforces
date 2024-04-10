#include <bits/stdc++.h>
using namespace std;

const int K = 52;
const int N = 10;
const int INF = 1e9;
int pos[N][K][2];
int dp[K][1<<N];

struct state {
  int v, mask;
};

state pre[K][1<<N];

int to_int(char c) {
  if ('a' <= c && c <= 'z') {
    return c-'a';
  }
  return K/2+c-'A';
}

char to_char(int v) {
  if (v < K/2) return 'a'+v;
  return 'A'+v-K/2;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
      for (int j = 0; j < K; j++) {
        pos[i][j][0] = INF;
        pos[i][j][1] = INF;
      }
      for (int k = 0; k < (int)s[i].size(); k++) {
        int j = to_int(s[i][k]);
        if (pos[i][j][0] == INF) pos[i][j][0] = k;
        else pos[i][j][1] = k;
      }
    }

    function<void(int, int, int)> dfs = [&] (int v, int mask, int k) {
      if (dp[v][mask] > k) return;
      for (int i = 0; i < n; i++) {
        if (pos[i][v][(mask>>i)&1] == INF) return;
      }
      dp[v][mask] = k;
      if (k == 1) {
        pre[v][mask] = {-1, -1};
      }
      for (int u = 0; u < K; u++) {
        int nm = 0;
        bool good = 1;
        for (int i = 0; i < n; i++) {
          if (pos[i][u][1] <= pos[i][v][(mask>>i)&1]) {
            good = 0;
            break;
          }
          if (pos[i][u][0] <= pos[i][v][(mask>>i)&1]) {
            if (pos[i][u][1] == INF) {
              good = 0;
              break;
            }
            nm ^= 1<<i;
          }
        }
        if (good) {
          if (dp[u][nm] < k+1) {
            pre[u][nm] = {v, mask};
            dfs(u, nm, k+1);
          }
        }
      }
    };

    for (int i = 0; i < K; i++) {
      dfs(i, 0, 1);
    }

    state best = {-1, -1};
    int ans = 0;
    for (int i = 0; i < K; i++) {
      for (int j = 0; j < (1<<N); j++) {
        if (ans < dp[i][j]) {
          ans = max(ans, dp[i][j]);
          best = {i, j};
        }
        dp[i][j] = 0;
      }
    }
    cout << ans << '\n';
    string lcs;
    while (best.v != -1) {
      lcs.push_back(to_char(best.v));
      best = pre[best.v][best.mask];
    }
    reverse(lcs.begin(), lcs.end());
    cout << lcs << '\n';
  }
}