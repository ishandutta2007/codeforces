#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int tot[N], low[N];
vector<int> cnt[N];
bool vis[1<<N];
int sums[1<<N], dp[1<<N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int t = 0;
    for (char c: s) {
      if (c == '(') t++;
      else t--;
      low[i] = min(low[i], t);
    }
    cnt[i].resize(1-low[i]);

    tot[i] = 0;
    int l = 0;
    for (char c: s) {
      if (c == '(') tot[i]++;
      else tot[i]--;
      if (tot[i] <= l) {
        cnt[i][tot[i]-low[i]]++;
      }
      l = min(l, tot[i]);
    }
  }

  vector<int> que(1, 0);
  int ans = 0;
  for (int i = 0; i < (int)que.size(); i++) {
    int m = que[i];
    ans = max(ans, dp[m]);
    for (int j = 0; j < n; j++) {
      if (!(m&(1<<j))) {
        if (sums[m]+low[j] < 0) {
          ans = max(ans, dp[m]+cnt[j][-sums[m]-low[j]]);
        }
        else {
          int nm = m | (1<<j);
          sums[nm] = sums[m]+tot[j];
          if (sums[m]+low[j] == 0) {
            dp[nm] = max(dp[nm], dp[m]+cnt[j][0]);
          }
          else {
            dp[nm] = max(dp[nm], dp[m]);
          }

          if (!vis[nm]) {
            que.push_back(nm);
            vis[nm] = 1;
          }
        }
      }
    }
  }

  cout << ans << '\n';
}