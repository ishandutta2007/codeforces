#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <cassert>
#include <set>
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

#define maxq 200005
struct Event {
  int x, y, dir;
  // dir = 0: Right
  // dir = 1: Down
  // dir = 2: Up
  // dir = 3: Left
  bool operator < (const Event &e) const {
    if (x == e.x) return dir < e.dir;
    return x < e.x;
  }
}p[maxq];
int n, m, q;
struct BIT {
  #define SIZ 1000000
  int bit[SIZ + 5];
  void add(int pos, int x) {
    for (int i = pos; i <= SIZ; i += i & -i) bit[i] += x;
  }
  int qsum(int pos) {
    int res = 0;
    for (int i = pos; i; i -= i & -i) res += bit[i];
    return res;
  }
  int qsum(int l, int r) {
    assert(1 <= l && l <= r && r <= SIZ);
    return qsum(r) - qsum(l - 1);
  }
  #undef SIZ
}senior;
set<int> junior;

int main() {
  n = getint(), m = getint();
  for (int i = 1; i <= n; i++) {
    int y = getint(), lx = getint(), rx = getint();
    if (lx == 0) {
      p[++q] = (Event){rx, y, 3};
      senior.add(y, 1); 
    } else {
      p[++q] = (Event){lx, y, 0};
    }
  }
  senior.add(1000000, 1);
  for (int i = 1; i <= m; i++) {
    int x = getint(), ly = getint(), ry = getint();
    if (ly == 0) p[++q] = (Event){x, ry, 1};
    else p[++q] = (Event){x, ly, 2};
  }
  p[++q] = (Event){1000000, 1000000, 1};
  sort(p + 1, p + q + 1);
  ll ans = 0;
  for (int i = 1; i <= q; i++) {
    if (p[i].dir == 0) junior.insert(p[i].y);
    else if (p[i].dir == 1) {
      ans += senior.qsum(1, p[i].y);
      
//      cout << p[i].x << " " << p[i].y << " " << p[i].dir << ": " << ans << endl;
//      system("pause");
      
      auto ed = junior.upper_bound(p[i].y);
      vector<int> del;
      for (auto it = junior.begin(); it != ed; it++) {
        del.push_back(*it);
        senior.add(*it, 1);
      }
      for (auto j : del) junior.erase(j);
    } else if (p[i].dir == 2) {
      ans += senior.qsum(p[i].y, 999999);
      
//      cout << p[i].x << " " << p[i].y << " " << p[i].dir << ": " << ans << endl;
//      system("pause");
      
      vector<int> del;
      for (auto it = junior.lower_bound(p[i].y); it != junior.end(); it++) {
        del.push_back(*it);
        senior.add(*it, 1);
      }
      for (auto j : del) junior.erase(j);
    } else {
      senior.add(p[i].y, -1);
    }
  }
  putll(ans, '\n');
  bufo.flush();
  return 0;
}