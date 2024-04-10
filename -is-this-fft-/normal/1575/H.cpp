#include <iostream>
#include <vector>

using namespace std;

vector<int> calc_lps (const string &s) {
  int p = s.size();
  vector<int> lps (p, 0);
  
  int len = 0;
  int i = 1;
  while (i < p) {
    if (s[i] == s[len]) {
      len++;
      lps[i] = len;
      i++;
    } else {
      if (len != 0) {
        len = lps[len - 1];
      } else {
        lps[i] = 0;
        i++;
      }
    }
  }

  return lps;
}

const int INF = 1e9 + 5;
const int MAX_N = 505;

int nxt [MAX_N][2];
int dp [MAX_N][MAX_N][MAX_N]; // cnt, kmp cnt, # matches

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n, m;
  cin >> n >> m;

  string s, b;
  cin >> s >> b;

  auto lps = calc_lps(b);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 2; j++) {
      if (b[i] == '0' + j) {
        nxt[i][j] = i + 1;
      } else if (i == 0) {
        nxt[i][j] = 0;
      } else {
        int cur = i;
        do {
          cur--;
          cur = lps[cur];
          if (b[cur] == '0' + j) {
            nxt[i][j] = cur + 1;
            break;
          }
        } while (cur > 0);
      }
    }
  }

  for (int i = 0; i < MAX_N; i++) {
    for (int j = 0; j < MAX_N; j++) {
      for (int k = 0; k < MAX_N; k++) {
        dp[i][j][k] = INF;
      }
    }
  }

  dp[0][0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < n - m + 2; k++) {
        for (int a = 0; a < 2; a++) {
          int nj = nxt[j][a];
          int nk = k;
          if (nj == m) {
            nj = lps[m - 1];
            nk++;
          }

          int add = s[i] != '0' + a;
          dp[i + 1][nj][nk] = min(dp[i + 1][nj][nk], dp[i][j][k] + add);
        }
      }
    }
  }

  for (int i = 0; i < n - m + 2; i++) {
    int ans = INF;
    for (int j = 0; j < m; j++) {
      ans = min(ans, dp[n][j][i]);
    }
    cout << (ans == INF ? -1 : ans) << " ";
  }
  cout << endl;
}