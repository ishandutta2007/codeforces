#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 2e5+5;
int p2[N];

int add(int x, int y) {
  x += y;
  return (x >= MOD ? x-MOD : x);
}

int sub(int x, int y) {
  x -= y;
  return (x < 0 ? x+MOD : x);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  p2[0] = 1;
  for (int i = 1; i < N; i++) {
    p2[i] = 2LL*p2[i-1] % MOD;
  }
  string n;
  cin >> n;
  int k = n.size();
  int nmod = 0;
  // count triples (a, b, c)
  for (int i = 0; i < k; i++) {
    if (n[k-1-i] == '1') {
      nmod = add(nmod, p2[i]);
    }
  }
  int ans = 1;
  for (int j = 0; j < 3; j++) {
    ans = 1LL*ans*(nmod+1) % MOD;
  }

  // count triples where (a^b) == (b^c)+(c^a)
  vector<vector<int>> dp(k+1, vector<int>(8));
  // mask[0] = a < n
  // mask[1] = b < n
  // mask[2] = c < n
  dp[0][0] = 1;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < 8; j++) {
      for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
          for (int c = 0; c < 2; c++) {
            if (a == b && a != c) continue;
            if (n[i] == '0') {
              if (!(j&1) && a == 1) continue;
              if (!(j&2) && b == 1) continue;
              if (!(j&4) && c == 1) continue;
            }
            int nj = j;
            if (n[i] == '1' && a == 0) nj |= 1;
            if (n[i] == '1' && b == 0) nj |= 2;
            if (n[i] == '1' && c == 0) nj |= 4;
            dp[i+1][nj] = add(dp[i+1][nj], dp[i][j]);
          }
        }
      }
    }
  }

  int z = 0;
  for (int x: dp[k]) z = add(z, x);
  for (int j = 0; j < 3; j++) {
    ans = sub(ans, z);
  }

  // count triples where b == c
  z = (1LL*(nmod+1)*(nmod+1)) % MOD;
  for (int j = 0; j < 3; j++) {
    ans = add(ans, z);
  }

  // count triples where a = b = c
  ans = sub(ans, nmod+1);
  if (ans >= MOD) ans -= MOD;
  if (ans < 0) ans += MOD;
  cout << ans << '\n';
}