#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
string perms[6] = {"abc", "acb", "bac", "bca", "cab", "cba"};
int diffs[6][N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  string s;
  cin >> n >> m >> s;
  for (int j = 0; j < 6; j++) {
    for (int i = 0; i < n+1; i++) {
      diffs[j][i] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 6; j++) {
      if (s[i] != perms[j][i % 3]) {
        diffs[j][i+1] = diffs[j][i]+1;
      }
      else {
        diffs[j][i+1] = diffs[j][i];
      }
    }
  }
  while (m--) {
    int l, r;
    cin >> l >> r;
    int ans = 9999999;
    for (int j = 0; j < 6; j++) {
      ans = min(ans, diffs[j][r]-diffs[j][l-1]);
    }
    cout << ans << '\n';
  }
}