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
#define lowbit(x) (x & -x)
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }

namespace IO {
  const int SIZE = 1 << 16;
  char ibuf[SIZE]; int iS, iT;
  char obuf[SIZE]; int oT;
  inline char gc() {
    if (iS == iT)
      iS = 0, iT = fread(ibuf, 1, SIZE, stdin);
    return iS == iT ? EOF : ibuf[iS++];
  }
  inline void pc(char c) {
    obuf[oT++] = c;
    if (oT == SIZE)
      fwrite(obuf, 1, SIZE, stdout), oT = 0;
  }
  inline int read() {
    int x = 0, f = 0;
    char c = gc();
    while (!isdigit(c)) f |= c == '-', c = gc();
    while (isdigit(c)) x = 10 * x + c - '0', c = gc();
    return f ? -x : x; 
  }
  inline void print(int64_t x) {
    static char bufn[64];
    int len = 0;
    if (x < 0) x = -x, pc('-');
    while (x >= 10) bufn[len++] = x % 10 + '0', x /= 10;
    bufn[len++] = x + '0';
    while (len--) pc(bufn[len]);
  }
  inline void print(int64_t x, char ch) {
    print(x), pc(ch);
  }
  struct ff {
    ~ff() {
      if (oT)
        fwrite(obuf, 1, oT, stdout);
    }
  } flusher;
}
using namespace IO;

const int N = 2000005;
int cnt;

struct EE { int u, v; } E[N];
int n, m;

int f[N], sz[N], bin[N], btop;
inline int find(int x) {
//  ++cnt;
  while (f[x] != x) x = f[x];
  return x;
}
inline bool merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return false;
  if (sz[x] > sz[y]) swap(x, y);
  bin[++btop] = x, f[x] = y, sz[y] += sz[x];
  return true;
}
inline int my_merge(int x, int y) {
  int t = merge(x, y + n);
  t += merge(x + n, y);
  return t;
}
inline void undo() {
  int x = bin[btop--];
  sz[f[x]] -= sz[x], f[x] = x;
}

struct node {
  int op, u, v, E;
};
vector<node> buf;
vector<pii> tmp[2];
int go[N], q, top;

int main() {
  n = read(), m = read(), q = read();
  rep(i, 1, m) E[i].u = read(), E[i].v = read(), E[i + m] = E[i];
  rep(i, 1, 2 * n) f[i] = i, sz[i] = 1;
  int r = 1;
//  rep(i, 1, 2 * m) {
//    printf("(i = %d, %d, %d)\n", i, E[i].u, E[i].v);
//  }
  rep(l, 1, 2 * m) {
    while (r <= 2 * m && find(E[r].u) != find(E[r].v)) {
      buf.pb({1, E[r].u, E[r].v, my_merge(E[r].u, E[r].v)}), ++r;
    }
//    printf("l = %d, r = %d\n",l,r);
    go[l] = r;
    if (!top) {
      reverse(buf.begin(), buf.end());
      for (auto &v: buf) while (v.E--) undo();
      for (auto &v: buf) ++cnt, v.op = 0, v.E = my_merge(v.u, v.v);
      top = SZ(buf);
    }
    if (buf.back().op == 1) {
      while (buf.back().op == 1) {
//        ++cnt;
        node it = buf.back(); buf.pop_back();
        tmp[1].pb({it.u, it.v});
        while (it.E--) undo();
      }
      int del = lowbit(top);
      while (del--) {
//        ++cnt;
        node it = buf.back(); buf.pop_back();
//        assert(it.op == 0);
        tmp[0].pb({it.u, it.v});
        while (it.E--) undo();
      }
      while (SZ(tmp[1])) {
//        ++cnt;
        pii it = tmp[1].back(); tmp[1].pop_back();
        buf.pb({1, it.fir, it.sec, my_merge(it.fir, it.sec)});
      }
      while (SZ(tmp[0])) {
//        ++cnt;
        pii it = tmp[0].back(); tmp[0].pop_back();
        buf.pb({0, it.fir, it.sec, my_merge(it.fir, it.sec)});
      }
    }
    node it = buf.back();
    buf.pop_back(), top--;
    while (it.E--) undo();
  } 
//  cerr << cnt / 1. / m << '\n';
//  cerr << "cnt = " << cnt << '\n';
  while (q--) {
    int l = read(), r = read();
    puts(go[r + 1] < l + m ? "YES" : "NO");
  }
  return 0;
}

/*
4 4
3 1
3 4
1 3
1 3
*/