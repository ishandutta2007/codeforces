#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>

using namespace std;
typedef long long ll;
const int LEN = 100000;

struct fastio {
  int it, len;
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
    for (c = get();c == ' ' || c == '\n' || c == '\r';c = get());
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
  for (c = buff.get(); c == ' ' || c == '\n' || c == '\r'; c = buff.get());
  return c;
}
#define maxn 200005
int n, a[maxn];
vector<int> b[maxn];
ll mypow(ll x, ll y) {
  ll res = 1;
  while (y--) res *= x;
  return res;
}
int main() {
  n = getint();
  for (int i = 1; i <= n; i++) {
    int a = getint();
    for (int j = 2; j * j <= a; j++) {
      if (a % j == 0) {
        int c = 0;
        while (a % j == 0) {
          c++;
          a /= j;
        }
        b[j].push_back(c);
      }
    }
    if (a > 1) {
      b[a].push_back(1);
    }
  }
  ll ans = 1;
  for (int i = 1; i <= 200000; i++) {
    
//    cout << i << ": " << b[i].size() << endl;
//    system("pause");
    
    sort(b[i].begin(), b[i].end());
    if ((int)b[i].size() < n - 1) continue;
    if ((int)b[i].size() == n - 1) ans *= mypow(i, b[i][0]);
    else ans *= mypow(i, b[i][1]);
  }
  putll(ans, '\n');
  bufo.flush();
  return 0;
}