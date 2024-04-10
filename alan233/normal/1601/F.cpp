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

const int B = 1000000;
const int mod1 = 998244353;
const int mod2 = 1e9 + 7;

vector<int> va[7]; int sum[7];
ll cnt, n, ans;

int calc(ll x) {
  return (x % mod1 + mod1) % mod1;
}

void dfs1(int dep, int val) {
  ++cnt;
  va[dep].pb(calc(cnt - val));
  if (dep == 6) return ;
  for (int i = 0; i < 10; i++)
    dfs1(dep + 1, 10 * val + i);
}
void dfs2(int dep, ll val) {
  if (val > n) return ;
  if (dep >= 1) {
    if (val * B > n / 10 && (val + 1) * B - 1 <= n) {
      int tmp = 1;
      for (int i = 0; i < 7; i++) {
        int coef = calc(cnt - val * tmp);
        int pos = lower_bound(va[i].begin(), va[i].end(), mod1 - coef) - va[i].begin();
        ans = (ans + 1ll * coef * SZ(va[i]) + sum[i] - 1ll * mod1 * (SZ(va[i]) - pos)) % mod2;
        tmp *= 10;
      }
      for (int i = 0; i < 7; i++) cnt += SZ(va[i]);
      return ;
    }
    ++cnt; ans = (ans + calc(cnt - val)) % mod2;
  }
  for (int i = !dep; i < 10; i++)
    dfs2(dep + 1, 10 * val + i);
}

int main() {
  cin >> n;
  dfs1(0, 0);
  for (int dep = 0; dep < 7; dep++) {
    sort(va[dep].begin(), va[dep].end());
    for (auto v: va[dep]) sum[dep] = (sum[dep] + v) % mod2;
    // printf("sum[%d] = %lld\n", dep, sum[dep]);
  }
  cnt = 0;
  dfs2(0, 0);
  cout << (ans + mod2) % mod2 << '\n';
  return 0;
}