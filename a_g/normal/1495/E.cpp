#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
long long s[2];

int seed = 0;
int base = 0;

int rnd() {
  int ret = seed;
  seed = (1LL*seed*base + 233) % MOD;
  return ret;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n), t(n), ans(n);
  int z = 0;
  for (int i = 0; i < m; i++) {
    int p, k;
    cin >> p >> k >> seed >> base;
    for (int j = z; j < p; j++) {
      t[j] = (rnd()&1);
      a[j] = (rnd()%k) + 1;
      s[t[j]] += a[j];
    }
    z = p;
  }

  int cur = 0;
  if (s[t[0]] > s[1-t[0]]) {
    a[0]--;
    ans[0]++;
    while (cur != n && t[cur] == t[0]) cur++;
  }

  if (cur != n) {
    int b = t[cur];
    long long moves = 0;
    for (int i = 0; i < 2*n; i++) {
      if (t[cur] == b) {
        moves += a[cur];
        ans[cur] += a[cur];
        a[cur] = 0;
      }
      else {
        int u = min<long long>(a[cur], moves);
        moves -= u;
        ans[cur] += u;
        a[cur] -= u;
      }
      cur = (cur == n-1 ? 0 : cur+1);
    }
  }


  int k = 1;
  for (int i = 0; i < n; i++) {
    long long u = ((ans[i]^(1LL*(i+1)*(i+1)))+1)%MOD;
    k = k*u % MOD;
  }
  cout << k << '\n';
}