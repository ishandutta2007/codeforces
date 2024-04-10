#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int N = 1000 + 7;
const int M = 998244353;

int dp[N][N];
int pref[N][N];

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector <int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int ans = 0;
  for (int x = 1; x <= 100000 / (k - 1); x++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= k; j++) {
        dp[i][j] = 0;
      }
    }
    int y = 0;
    for (int i = 0; i < n; i++) {
      while (y >= 0 && a[i] - a[y] < x) y--;
      y = min(y, i-1);
      while (y + 1 < i && a[i] - a[y + 1] >= x) y++;
      dp[i][1] = 1;
      for (int j = 1; j < k; j++) {
        if (y >= 0)
          dp[i][j + 1] = pref[y][j];
      }
      for (int j = 1; j < k;j ++)  {
        pref[i][j] = (i ? pref[i - 1][j] : 0) + dp[i][j];
        if (pref[i][j] >= M)pref[i][j] -= M;
      }
      ans += dp[i][k];
      if (ans >= M) ans -= M;
    }
  }
  cout << ans << '\n';
}