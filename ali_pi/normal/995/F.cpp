#include <bits/stdc++.h>

using namespace :: std;

typedef long long ll;

const int MAXN = 3333;
const int MOD = 1E9 + 7;
vector<int> ed[MAXN];
int par[MAXN];
int dp[MAXN][MAXN];
int ar[MAXN];
bool vis[MAXN];
ll fin[MAXN];
int chs[MAXN][MAXN];

int getdp(int n, int c) {
  if (c == 0) return 0;
  if (dp[n][c]) return dp[n][c];
  ll ways = 1;
  for(int e: ed[n]) if (e != par[n]) {
    ways *= getdp(e, c);
    ways %= MOD;
  }
  ways += getdp(n, c - 1);
  ways %= MOD;
  dp[n][c] = ways;
  return ways;
}

ll pw(int a, int b, int c) {
  if (b == 0) return 1;
  ll r = pw(a, b / 2, c);
  r = r * r % c;
  if (b & 1) r = r * a % c;
  return r;
}

int inv(int x, int p) {
  return pw(x, p - 2, p);
}


int main() {
  int n, d;
  cin >> n >> d;
  for(int i = 2; i <= n; ++i) {
    cin >> par[i];
    ed[par[i]].push_back(i);
  }

  ll ans = 0;
  ll p = 1;
  chs[0][0] = 1;
  for(int i = 0; i <= n; ++i) {
    for(int j = 0; j <= i; ++j) {
      chs[i][j] %= MOD;
      chs[i + 1][j] += chs[i][j];
      chs[i + 1][j + 1] += chs[i][j];
    }
  }
  for(int k = 1; k <= n; ++k) {
    ll w = getdp(1, k);
    for(int j = 1; j < k; ++j) {
      w -= fin[j] * chs[k][j];
      w %= MOD;
    }
    fin[k] = w;
    p *= d - k + 1;
    p %= MOD;
    p *= inv(k, MOD);
    p %= MOD;
    ans += w * p;
    ans %= MOD;
  }
  if (ans < 0) ans += MOD;
  cout << ans << "\n";
}