#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5, INF = 0x7f7f7f7f;

priority_queue <int> add, del;
vector <int> vec[maxN];
int dp[35][maxN], a[maxN], L[maxN];
int T, n, ans;

void insert(int x) {
  add.push(x);
}

void erase(int x) {
  del.push(x);
}

int top() {
  while (!del.empty() && add.top() == del.top()) add.pop(), del.pop();
  if (add.empty()) return -1;
  return add.top();
}

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      dp[1][i] = 0;
      L[i] = i;
      if (i != 1 && a[i - 1] == a[i]) L[i] = L[i - 1];
    }
    ans = 1;
    for (int j = 1; j <= 33; j++) {
      memset(dp[j + 1], 0x7f, (n + 1) * 4);
      while (!add.empty()) add.pop();
      while (!del.empty()) del.pop();
      int minn = INF;
      for (int i = 0; i <= n; i++) vec[i].clear();
      for (int i = n; i >= 1; i--) {
        for (auto k : vec[i]) {
          erase(a[k]);
          minn = min(minn, dp[j][k]);
        }
        if (minn <= a[i]) dp[j + 1][i] = minn;
        int res = top();
        if (res != -1) dp[j + 1][i] = min(dp[j + 1][i], 2 * a[i] - res);
        if (dp[j][i] != INF) {
          ans = max(ans, j + i - L[i]);
          int pos = lower_bound(a + 1, a + n + 1, (dp[j][i] + a[i] + 1) / 2) - a;
          insert(a[i]);
          vec[pos - 1].push_back(i);
        }
      }
    }
    printf("%d\n", n - ans);
  }
  return 0;
}