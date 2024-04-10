// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#pragma GCC target("avx", "avx2")
#ifdef xay
#define D(...) fprintf(stderr, "[D]" __VA_ARGS__)
#else
#define D(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
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

const int N = 15;

struct node {
  int pos[11];
  ull hsh;
  ll val;
  friend bool operator < (const node &x, const node &y) {
    return x.val < y.val;
  }
};
priority_queue<node> pq;

gp_hash_table<ull, bool> ban, vis;

ull a[N];
int len[N], c[N][200005];
int n, m;

int main() {
  n = read();
  rep(i, 1, n) {
    a[i] = rng();
    len[i] = read();
    rep(j, 1, len[i])
      c[i][j] = read();
  }
//  rep(i, 1, n) {
//    D("a[%d] = %llu\n", i, a[i]);
//  }
  m = read();
  rep(i, 1, m) {
    ull banned = 0;
    rep(i, 1, n) {
      banned += read() * a[i];
    }
    ban[banned] = 1;
  }
  node _; _.hsh = _.val = 0;
  rep(i, 1, n) _.pos[i] = len[i], _.hsh += len[i] * a[i], _.val += c[i][len[i]];
  pq.push(_);
  while (1) {
    node u = pq.top(); pq.pop();
    if (!ban[u.hsh]) {
      rep(i, 1, n) printf("%d ", u.pos[i]);
      puts("");
      return 0;
    }
    vis[u.hsh] = 1;
    rep(i, 1, n) {
      if (u.pos[i] != 1) {
        u.hsh -= a[i];
        u.val -= c[i][u.pos[i]];
        u.pos[i]--;
        u.val += c[i][u.pos[i]];
        if (!vis[u.hsh]) {
          vis[u.hsh] = 1;
          pq.push(u);
        }
        u.val -= c[i][u.pos[i]];
        u.pos[i]++;
        u.val += c[i][u.pos[i]];
        u.hsh += a[i];
      }
    }
  }
  return 0;
}