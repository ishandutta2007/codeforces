#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>

using namespace std;
typedef long long ll;
const int LEN = 100000;

struct fastio {
  int it,len;
  char s[LEN + 5];
  fastio() {
    it = len = 0;
  }
  char get() {
    if(it < len) return s[it++];
    it = 0, len = fread(s, 1, LEN, stdin);
    return len ? s[it++] : EOF;
  }
  bool notend() {
    char c;
    for (c = get();c == ' ' || c == '\n';c = get());
    if (it) it--;
    return c != EOF;
  }
  void put(char c) {
    if(it == LEN) fwrite(s,1,LEN,stdout), it = 0;
    s[it++] = c;
  }
  void flush() {
    fwrite(s, 1, it, stdout);
  }
}buff, bufo;
inline int getint() {
  char c; int res = 0, sig = 1;
  for (c = buff.get(); c < '0' || c > '9'; c = buff.get()) if(c == '-') sig = -1;
  for (;c >= '0' && c <= '9';c = buff.get()) res = res * 10 + (c - '0');
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
  for (c = buff.get(); c == ' ' || c == '\n'; c = buff.get());
  return c;
}
#define maxn 200005
typedef pair<int, int> P;
int n, m, p, b[maxn], cb[maxn], minCb[maxn];
P wea[maxn]; // (a, ca).
vector<int> bs;
struct Mons{
  int x, y, z;
  bool operator < (const Mons &m) const {
    return x < m.x;
  }
}mon[maxn]; int k;
int maxi[maxn << 2], add[maxn << 2];
inline void up(int id) {
  maxi[id] = max(maxi[id << 1], maxi[id << 1 | 1]) + add[id];
}
inline void down(int id) {
  if(add[id]){
    add[id << 1] += add[id];
    maxi[id << 1] += add[id];
    add[id << 1 | 1] += add[id];
    maxi[id << 1 | 1] += add[id];
    add[id] = 0;
  }
}
void jia(int id, int l, int r, int ql, int qr, int x) {
  if (ql > qr) return;
  if (ql <= l && r <= qr) {
    maxi[id] += x;
    add[id] += x;
  } else {
    down(id);
    int mid = (l + r) >> 1;
    if (ql <= mid) jia(id << 1, l, mid, ql, qr, x);
    if (mid < qr) jia(id << 1 | 1, mid + 1, r, ql, qr, x);
    up(id);
  }
}
int main() {
  n = getint(), m = getint(), p = getint();
  for (int i = 1; i <= n; i++) {
    wea[i].first = getint(), wea[i].second = getint();
  }
  sort(wea + 1, wea + n + 1);
  for (int i = 1; i <= m; i++) {
    b[i] = getint(), cb[i] = getint();
    bs.push_back(b[i]);
  }
  for (int i = 1; i <= p; i++) {
    mon[i].x = getint(), mon[i].y = getint(), mon[i].z = getint();
  }
  sort(mon + 1, mon + p + 1);
  sort(bs.begin(), bs.end());
  bs.erase(unique(bs.begin(), bs.end()), bs.end());
  int Y = bs.size();
  memset(minCb, 0x3f, sizeof(minCb));
  for (int i = 1; i <= m; i++) {
    b[i] = lower_bound(bs.begin(), bs.end(), b[i]) - bs.begin() + 1;
    minCb[b[i]] = min(minCb[b[i]], cb[i]);
  }
  for (int i = 1; i <= p; i++) {
    mon[i].y = upper_bound(bs.begin(), bs.end(), mon[i].y) - bs.begin() + 1;
  }
  int ans = -INT_MAX;
  for (int i = 1; i <= Y; i++) jia(1, 1, Y, i, i, -minCb[i]);
  for (int i = 1; i <= n; i++) {
    while (k < p && mon[k + 1].x < wea[i].first) {
      k++;
      jia(1, 1, Y, mon[k].y, Y, mon[k].z);
    }
    ans = max(ans, maxi[1] - wea[i].second);
  }
  putint(ans, '\n');
  bufo.flush();
  return 0;
}