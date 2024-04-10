#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int N = 5005;
int s[N], dpr[N][N], dpl[N][N];
bool fl[N], fr[N];
vector<int> pos[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    pos[s[i]].push_back(i);
  }
  for (int i = 0; i < m; i++) {
    int f, h;
    cin >> f >> h;
    if (h > pos[f].size()) continue;
    fl[pos[f][h-1]] = 1;
    fr[pos[f][pos[f].size()-h]] = 1;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dpl[i][j] = dpl[i-1][j];
    }
    if (fl[i]) {
      dpl[i][s[i]]++;
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= n; j++) {
      dpr[i][j] = dpr[i+1][j];
    }
    if (fr[i]) {
      dpr[i][s[i]]++;
    }
  }

  int c = 0;
  int ways = 0;
  for (int i = 0; i <= n; i++) {
    int z = 0;
    for (int j = 1; j <= n; j++) {
      int p = dpl[i][j];
      int q = dpr[i+1][j];
      if (p+q == 0) continue;
      if (p == 0 || q == 0) {
        z++;
        continue;
      }
      if (p == 1 && q == 1) {
        z++;
        continue;
      }
      z += 2;
    }
    c = max(c, z);
  }

  for (int i = 0; i <= n; i++) {
    int z = 0;
    int u = 1;
    for (int j = 1; j <= n; j++) {
      int p = dpl[i][j];
      int q = dpr[i+1][j];
      if (p+q == 0) continue;
      if (p == 0 || q == 0) {
        z++;
        u = 1LL*max(p, q)*u % MOD;
        continue;
      }
      if (p == 1 && q == 1) {
        z++;
        u = 2LL*u%MOD;
        continue;
      }
      z += 2;
      u = 1LL*min(p, q)*(max(p, q)-1)*u % MOD;
    }

    if (z == c) {
      ways = (ways+u)%MOD;
    }
  }

  for (int i = 0; i < n; i++) {
    int z = 0;
    int u = 1;
    for (int j = 1; j <= n; j++) {
      int p = dpl[i][j];
      int q = dpr[i+2][j];
      if (p+q == 0) continue;
      if (p == 0 || q == 0) {
        z++;
        u = 1LL*max(p, q)*u % MOD;
        continue;
      }
      if (p == 1 && q == 1) {
        z++;
        u = 2LL*u%MOD;
        continue;
      }
      z += 2;
      u = 1LL*min(p, q)*(max(p, q)-1)*u % MOD;
    }

    if (z == c) {
      ways = (ways-u)%MOD;
    }
  }
  if (ways < 0) ways += MOD;
  cout << c << ' ' << ways << '\n';
}