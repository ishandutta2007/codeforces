// Author: wlzhouzhuan
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
  inline ll read() {
    ll x = 0, f = 0;
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

const int N = 1000005;

ll a[N], popc[N];
int n;

struct SMT {
  int a[N], b[N];
  inline void clear() {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
  }
  inline void add(int x, int dlt) {
    for (int i = x; i <= n; i += i & -i) {
      a[i] += dlt;
      b[i] += dlt * x;
    }
  }
  inline int qry(int x) {
    int ret = 0;
    for (int i = x; i; i ^= i & -i) {
      ret += (x + 1) * a[i] - b[i]; 
    }
    return ret;
  }
  inline void add(int l, int r, int dlt) {
    add(l, dlt);
    add(r + 1, -dlt);
  }
  inline int ask(int l, int r) {
    return qry(r) - qry(l - 1);
  }
} A, B;

int stkA[N], topA;
int stkB[N], topB;

int main() {
  n = read();
  rep(i, 1, n) {
    a[i] = read();
    popc[i] = __builtin_popcountll(a[i]);
  }
  ll ans = 0;
  rep(bit, 0, 60) {
    A.clear();
    B.clear();
    topA = topB = 0;
    ll cur = 0;
    rep(i, 1, n) {
      while (topA && a[stkA[topA]] <= a[i]) {
        if (popc[stkA[topA]] == bit) {
          cur -= B.ask(stkA[topA - 1] + 1, stkA[topA]);
          A.add(stkA[topA - 1] + 1, stkA[topA], -1);
        }
        topA--;
      }
      while (topB && a[stkB[topB]] >= a[i]) {
        if (popc[stkB[topB]] == bit) {
          cur -= A.ask(stkB[topB - 1] + 1, stkB[topB]);
          B.add(stkB[topB - 1] + 1, stkB[topB], -1);
        }
        topB--;
      }
      stkA[++topA] = i;
      stkB[++topB] = i;
      if (popc[i] == bit) {
        A.add(stkA[topA - 1] + 1, stkA[topA], 1);
        cur += B.ask(stkA[topA - 1] + 1, stkA[topA]);
        B.add(stkB[topB - 1] + 1, stkB[topB], 1);
        cur += A.ask(stkB[topB - 1] + 1, stkB[topB]);
      }
      ans += cur;
    }
  }
  print(ans, '\n');
  return 0;
}