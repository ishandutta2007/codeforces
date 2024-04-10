// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#ifdef xay
#define D(...) fprintf(stderr, "[D]" __VA_ARGS__)
#else
#define D(...) ((void)0)
#endif
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

const int N = 100005;
const int mod = 1e9 + 7;

int a[N], n;

vector<int> inz[N];
int mu[N], coef[N], pr[N >> 2], len;
bool vis[N];

void xxs(int n) {
  mu[1] = 1;
  rep(i, 2, n) {
    if (!vis[i]) pr[++len] = i, mu[i] = -1;
    for (int j = 1; j <= len && pr[j] * i <= n; j++) {
      vis[pr[j] * i] = 1;
      if (i % pr[j] == 0) break;
      mu[pr[j] * i] = -mu[i];
    }
  }
  rep(i, 1, n) {
    rep(j, 1, n / i) {
      inz[i * j].pb(i);
    }
  }
  rep(i, 1, n) {
    for (auto v: inz[i]) 
      coef[i] = (coef[i] + 1ll * mu[v] * i / v) % mod;
  }
}

int cnt[N];
int gao(vector<int> f) {
  int ans = 0;
  for (auto a: f) {
    for (auto v: inz[a]) {
      int dlt = 2 * cnt[v] + 1;
      ans = (ans + 1ll * dlt * coef[v]) % mod;
      cnt[v]++;
    }
  }
  for (auto a: f) {
    for (auto v: inz[a]) {
      cnt[v] = 0;
    }
  }
  return ans;
}

int main() {
  xxs(1e5);
  n = read();
  rep(i, 1, n) a[i] = read();
  int ans = 0;
  rep(T, 1, n) {
    vector<int> f;
    for (int i = T; i <= n; i += T) f.pb(a[i]);
    ans = (ans + 1ll * coef[T] * gao(f)) % mod; 
  }
  print((ans + mod) % mod, '\n');
  return 0;
}