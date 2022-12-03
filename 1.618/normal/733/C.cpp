#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
using namespace std;
typedef long long ll;
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
#define maxn 505
#define mp make_pair
typedef pair<int, int> P; 
int a[maxn], suma[maxn], b[maxn], l[maxn], r[maxn], n, k; 
int main() {
  n = getint();
  for (int i = 1; i <= n; i++) suma[i] = suma[i - 1] + (a[i] = getint());
  k = getint();
  for (int i = 1; i <= k; i++) b[i] = getint();
  int j = 0;
  for (int i = 1; i <= k; i++) {
    int p = i;
    while (p <= n && suma[p] - suma[j] < b[i]) p++;
    if (p > n || suma[p] - suma[j] > b[i]) {
      puts("NO");
      return 0;
    }
    l[i] = j + 1, r[i] = p;
    j = p;
  }
  if (r[k] != n) {
    puts("NO");
    return 0;
  }
  vector<P> ans;
  for (int i = k; i >= 1; i--) {
    if (l[i] == r[i]) continue;
    int maxPos = l[i];
    for (int j = l[i] + 1; j <= r[i]; j++) {
      if (a[maxPos] < a[j]) maxPos = j;
    }
    if (a[maxPos] == *min_element(a + l[i], a + r[i] + 1)) {
      puts("NO");
      return 0;
    }
    if (maxPos == l[i] && a[l[i]] == a[l[i] + 1]) {
      while (a[maxPos + 1] == a[maxPos]) maxPos++;
      for (int j = maxPos; j < r[i]; j++) ans.push_back(mp(maxPos, 1));
      for (int j = maxPos; j > l[i]; j--) ans.push_back(mp(j, 0));
    } else {
      for (int j = maxPos; j > l[i]; j--) ans.push_back(mp(j, 0));
      for (int j = maxPos; j < r[i]; j++) ans.push_back(mp(l[i], 1));
    }
  }
  puts("YES");
  for (auto p : ans) {
    if (p.second == 0) printf("%d L\n", p.first);
    else printf("%d R\n", p.first);
  }
  return 0;
}