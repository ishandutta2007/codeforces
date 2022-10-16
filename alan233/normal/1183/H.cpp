// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
#define poly vector<int>
#define SZ(x) (int(x.size()))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 125;

char a[N];
ll dp[N][N], n, k;
int pre[26];

int main() {
    cin >> n >> k;
    scanf("%s", a + 1);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        a[i] -= 'a';
        dp[i][0] = dp[i - 1][0];
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] - (pre[a[i]] ? dp[pre[a[i]] - 1][j - 1] : 0);
            dp[i][j] = min(dp[i][j], (ll) 1e18);
        }
        pre[a[i]] = i;
    }
    ll ans = 0;
    for (int i = n; i >= 0; i--) {
        ll t = min(k, dp[n][i]);
        ans += t * (n - i);
        k -= t;
    }
    if (k) cout << -1 << '\n';
    else cout << ans;
    return 0;
}