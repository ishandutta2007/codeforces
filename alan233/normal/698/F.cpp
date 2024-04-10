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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1000005;
const int mod = 1e9 + 7;

int fac[N], qwq[N];
int ans = 1;
int pr[N >> 2], len; bool vis[N];
vector<int> jj[N];
int cnt1[N], cnt2[N];
bool ban[N];
int jiba[N], to[N], rto[N];

void deal(int n) {
  for (int i = 1; i <= n; i++) qwq[i] = 1;
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) {
      pr[++len] = i;
      for (int j = i; j <= n; j += i)
        qwq[j] *= i, jj[j].pb(i);
    }
    for (int j = 1; j <= len && pr[j] * i <= n; j++) {
      vis[pr[j] * i] = 1;
      if (i % pr[j] == 0) break;
    }
  }
  jiba[1] = 1, jj[1].pb(1); cnt2[1]++;
  for (int i = 1; i <= n; i++) cnt1[qwq[i]]++;
  for (int i = 1; i <= len; i++) cnt2[jiba[pr[i]] = n / pr[i]]++;
  // cerr << "?\n";
  for (int i = 1; i <= n; i++) {
    int _ = read();
    if (_ == 0) continue;
    int x = jj[i].back(), y = jj[_].back();
    if (jj[i].size() != jj[_].size()) {
      puts("0");
      return ;
    }
    for (int j = 0; j < jj[i].size() - 1; j++) {
      if (jj[i][j] != jj[_][j]) {
        puts("0");
        return ;
      }
    }
    if (jiba[x] != jiba[y]) {
      puts("0");
      return ;
    }
    if (to[x] && to[x] != y) {
      puts("0");
      return ;
    }
    if (rto[y] && rto[y] != x) {
      puts("0");
      return ;
    }
    if (!to[x]) ban[y] = 1, cnt2[jiba[y]]--;
    to[x] = y, rto[y] = x, cnt1[qwq[_]]--;
  }
  for (int i = 1; i <= n; i++) ans = 1ll * ans * fac[cnt1[i]] % mod;
  for (int i = 1; i <= n; i++) ans = 1ll * ans * fac[cnt2[i]] % mod;
  print(ans, '\n');
}
int n;

int main() {
  n = read();
  fac[0] = 1; rep(i, 1, n) fac[i] = 1ll * fac[i - 1] * i % mod;
  deal(n);
  return 0;
}