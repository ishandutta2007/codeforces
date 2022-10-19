#include <bits/stdc++.h>
using namespace std;

const int K = 18;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> D(n);
  for (int i = 0; i < n; i++) {
    cin >> D[i].first >> D[i].second;
  }
  vector<int> endpt(n), R(n);
  stack<int> stk;
  for (int i = n-1; i >= 0; i--) {
    endpt[i] = D[i].first+D[i].second;
    R[i] = i+1;
    while (!stk.empty() && D[stk.top()].first <= endpt[i]) {
      endpt[i] = max(endpt[i], endpt[stk.top()]);
      R[i] = max(R[i], R[stk.top()]);
      stk.pop();
    }
    stk.push(i);
  }
  vector<vector<pair<int, int>>> jmp(n, vector<pair<int, int>>(K));
  for (int i = 0; i < n; i++) {
    jmp[i][0] = make_pair(R[i], (R[i] == n ? 0 : D[R[i]].first-endpt[i]));
  }
  for (int k = 1; k < K; k++) {
    for (int i = 0; i < n; i++) {
      int j = jmp[i][k-1].first;
      if (j == n) jmp[i][k] = make_pair(n, 0);
      else jmp[i][k] = make_pair(jmp[j][k-1].first, jmp[i][k-1].second + jmp[j][k-1].second);
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    int ans = 0;
    for (int k = K-1; k >= 0; k--) {
      if (jmp[x][k].first <= y) {
        ans += jmp[x][k].second;
        x = jmp[x][k].first;
      }
    }
    cout << ans << '\n';
  }
}