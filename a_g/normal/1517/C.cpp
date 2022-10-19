#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> ans(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    int x = i;
    int y = i;
    for (int z = 0; z < k; z++) {
      ans[x][y] = k;
      if (y > 0 && !ans[x][y-1]) y--;
      else x++;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      cout << ans[i][j] << " \n"[j==i];
    }
  }
}