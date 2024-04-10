#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 1e3 + 5;

int N, K;
char mat[MAXN][MAXN];
char ans[MAXN][MAXN];
int dp[MAXN][MAXN];

void load() {
  scanf("%d%d", &N, &K);
  for (int i = 1; i <= N; i++)
    scanf("%s", mat[i] + 1);
}

void connect(pii lo_lft, pii up_rig) {
  while (1) {
    ans[lo_lft.first][lo_lft.second] = '1';
    if (lo_lft == up_rig)
      break;
    if (lo_lft.first > up_rig.first && ans[lo_lft.first - 1][lo_lft.second] == '0')
      lo_lft.first--;
    else
      lo_lft.second++;
  }
}

void solve() {
  K--;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) {
      ans[i][j] = '0';
      int dist = N - abs(i - j);
      if (dist == K)
        mat[i][j] = '0';
      else if (dist < K)
        ans[i][j] = mat[i][j] = '1';
    }
  vector <vector <pii>> groups(K + 1);
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) {
      dp[i][j] = dp[i - 1][j - 1];
      if (mat[i][j] == '0') {
        if (++dp[i][j] > K) {
          puts("NO");
          return;
        }
        groups[dp[i][j]].push_back({i, j});
      }
      dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
    }
  for (int i = 1; i <= K; i++) {
    sort(groups[i].begin(), groups[i].end(), [&](pii lhs, pii rhs) { return lhs.first == rhs.first ? lhs.second < rhs.second : lhs.first > rhs.first; });
    for (int j = 1; j < groups[i].size(); j++)
      connect(groups[i][j - 1], groups[i][j]);
  }
  puts("YES");
  for (int i = 1; i <= N; i++) {
    ans[i][N + 1] = '\0';
    puts(ans[i] + 1);
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    solve();
  }
  return 0;
}