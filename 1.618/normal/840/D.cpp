#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
const int LEN = 100000;

struct fastio {
  int it, len;
  char s[LEN + 5];
  fastio() {
    it = len = 0;
  }
  char get() {
    if (it < len) return s[it++];
    it = 0, len = fread(s, 1, LEN, stdin);
    return len ? s[it++] : EOF;
  }
  bool notend() {
    char c;
    for (c = get(); c == ' ' || c == '\n' || c == '\r'; c = get());
    if (it) it--;
    return c != EOF;
  }
  void put(char c) {
    if (it == LEN) fwrite(s,1,LEN,stdout), it = 0;
    s[it++] = c;
  }
  void flush() {
    fwrite(s, 1, it, stdout);
  }
}buff, bufo;
inline int getint() {
  char c; int res = 0, sig = 1;
  for (c = buff.get(); c < '0' || c > '9'; c = buff.get()) if(c == '-') sig = -1;
  for (; c >= '0' && c <= '9'; c = buff.get()) res = res * 10 + (c - '0');
  return sig * res;
}
inline ll getll() {
  char c; ll res = 0, sig = 1;
  for (c = buff.get(); c < '0' || c > '9'; c = buff.get()) if (c == '-') sig = -1;
  for (; c >= '0' && c <= '9'; c = buff.get()) res = res * 10 + (c - '0');
  return sig * res;
}
inline void putint(int x, char suf) {
  if (!x) bufo.put('0');
  else {
    if (x < 0) bufo.put('-'), x = -x;
    int k = 0; char s[15];
    while (x) {
      s[++k] = x % 10 + '0';
      x /= 10;
    }
    for (; k; k--) bufo.put(s[k]);
  }
  bufo.put(suf);
}
inline void putll(ll x, char suf) {
  if (!x) bufo.put('0');
  else {
    if (x < 0) bufo.put('-'), x = -x;
    int k = 0; char s[25];
    while (x) {
      s[++k] = x % 10 + '0';
      x /= 10;
    }
    for (; k; k--) bufo.put(s[k]);
  }
  bufo.put(suf);
}
inline char get_char() {
  char c;
  for (c = buff.get(); c == ' ' || c == '\n' || c == '\r'; c = buff.get());
  return c;
}
template<class T> bool chmin(T &x, T y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, T y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 300005
#define mp make_pair
typedef pair<int, int> P;
int n, m, a[maxn];
vector<int> pos[maxn];

int cnt(int val, int l, int r) {
  return upper_bound(pos[val].begin(), pos[val].end(), r) - 
         lower_bound(pos[val].begin(), pos[val].end(), l);
}

namespace Sgt {
  vector<int> dat[maxn << 2];
  
  bool app[maxn];
  void build(int id, int l, int r) {
    if (l == r) dat[id].push_back(a[l]);
    else {
      int mid = (l + r) >> 1;
      build(id << 1, l, mid);
      build(id << 1 | 1, mid + 1, r);
      vector<P> tmp; // (occur_times, val).
      for (auto i : dat[id << 1]) {
        tmp.push_back(mp(cnt(i, l, r), i));
        app[i] = true;
      }
      for (auto i : dat[id << 1 | 1]) {
        if (!app[i]) tmp.push_back(mp(cnt(i, l, r), i));
      }
      sort(tmp.begin(), tmp.end(), greater<P>());
      for (int i = 0; i < min((int)tmp.size(), 4); i++) {
        dat[id].push_back(tmp[i].second);
      }
      for (auto i : dat[id << 1]) {
        app[i] = false;
      }
    }
  }
  
  void query(int &ans, int id, int l, int r, int ql, int qr, int t) {
    if (ql <= l && r <= qr) {
      for (auto i : dat[id]) {
        if (cnt(i, ql, qr) * t > qr - ql + 1) chmin(ans, i);
      }
    } else {
      int mid = (l + r) >> 1;
      if (ql <= mid) query(ans, id << 1, l, mid, ql, qr, t);
      if (mid < qr) query(ans, id << 1 | 1, mid + 1, r, ql, qr, t);
    }
  }
}

int main() {
  n = getint(), m = getint();
  for (int i = 1; i <= n; i++) {
    a[i] = getint();
    pos[a[i]].push_back(i); 
  }
  Sgt::build(1, 1, n);
  for (int i = 1; i <= m; i++) {
    int l = getint(), r = getint(), t = getint(), ans = n + 1;
    Sgt::query(ans, 1, 1, n, l, r, t);
    putint(ans <= n ? ans : -1, '\n');
  }
  bufo.flush();
  return 0;
}