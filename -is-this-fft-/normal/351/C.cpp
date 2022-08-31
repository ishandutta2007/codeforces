#include <iostream>

using namespace std;

typedef long long ll;

const ll INF = 1e10;
const int MAX_D = 22;

struct Block {
  ll cost [MAX_D][MAX_D];

  Block () {
    for (int i = 0; i < MAX_D; i++) {
      for (int j = 0; j < MAX_D; j++) {
        cost[i][j] = INF;
      }
    }
  }
};

Block merge (Block p, Block q) {
  Block ans;
  for (int i = 0; i < MAX_D; i++) {
    for (int j = 0; j < MAX_D; j++) {
      for (int u = 0; u < MAX_D; u++) {
        for (int v = 0; v < MAX_D; v++) {
          int l, r;
          if (j < u) {
            l = i + u - j;
            r = v;
          } else {
            l = i;
            r = v + j - u;
          }

          if (l < MAX_D && r < MAX_D) {
            ans.cost[l][r] = min(ans.cost[l][r], p.cost[i][j] + q.cost[u][v]);
          }
        }
      }
    }
  }
  return ans;
}

const int MAX_LG = 24;
int opc [MAX_D];
int clc [MAX_D];
ll dp [MAX_D][MAX_D][MAX_D];
Block pows [MAX_LG];

int main () {
  ios::sync_with_stdio(false);

  int N, rep;
  cin >> N >> rep;

  for (int i = 0; i < N; i++) {
    cin >> opc[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> clc[i];
  }

  for (int i = 0; i < MAX_D; i++) {
    for (int j = 0; j < MAX_D; j++) {
      for (int k = 0; k < MAX_D; k++) {
        dp[i][j][k] = INF;
      }
    }
  }
  dp[0][0][0] = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < MAX_D; j++) {
      for (int k = 0; k < MAX_D; k++) {
        // put an open bracket
        if (k + 1 < MAX_D) {
          dp[i + 1][j][k + 1] = min(dp[i + 1][j][k + 1], dp[i][j][k] + opc[i]);
        }

        // put a close bracket
        if (k == 0 && j + 1 < MAX_D) {
          dp[i + 1][j + 1][k] = min(dp[i + 1][j + 1][k], dp[i][j][k] + clc[i]);
        } else {
          dp[i + 1][j][k - 1] = min(dp[i + 1][j][k - 1], dp[i][j][k] + clc[i]);
        }
      }
    }
  }

  Block base;
  for (int i = 0; i < MAX_D; i++) {
    for (int j = 0; j < MAX_D; j++) {
      base.cost[i][j] = dp[N][i][j];
    }
  }

  pows[0] = base;
  for (int i = 1; i < MAX_LG; i++) {
    pows[i] = merge(pows[i - 1], pows[i - 1]);
  }

  Block ans;
  int ans_ch = -1;
  for (int i = 0; i < MAX_LG; i++) {
    if (rep & 1 << i) {
      if (ans_ch == -1) {
        ans_ch = 0;
        ans = pows[i];
      } else {
        ans = merge(ans, pows[i]);
      }
    }
  }

  cout << ans.cost[0][0] << endl;
}