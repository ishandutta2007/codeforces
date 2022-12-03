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

#define maxn 5005
#define mp make_pair
typedef pair<int, int> P;
int n, q;
P paint[maxn];
int main() {
  n = getint(), q = getint();
  for (int i = 1; i <= q; i++) {
    paint[i].first = getint(), paint[i].second = getint();
  }
  sort(paint + 1, paint + q + 1);
  vector<P> lis;
  int r = 0, cur = 0, ans = 0;
  lis.push_back(mp(paint[1].first - 1, paint[1].first - 1)); 
  for (int i = 1; i <= q; i++) {
    if (paint[i].second <= cur) r++;
    else {
      ans += paint[i].second - max(cur, paint[i].first - 1);
      cur = paint[i].second;
      lis.push_back(paint[i]);
    }
  }
  q = lis.size() - 1;
  lis.push_back(mp(lis[q].second + 1, lis[q].second + 1));
  
//  for (auto i : lis) { 
//    cout << i.first << " " << i.second << endl;
//  }
//  cout << ans << endl;
//  system("pause");
  
  if (r >= 2) {
    putint(ans, '\n');
  } else if (r == 1) {
    int dec = n + 1;
    for (int i = 1; i <= q; i++) {
      dec = min(dec,
        min(lis[i + 1].first, lis[i].second + 1) - max(lis[i - 1].second, lis[i].first - 1) - 1);
      dec = max(dec, 0);
    }
    putint(ans - dec, '\n');
  } else {
    int dec = n + 1;
    for (int i = 1; i < q; i++) {
      if (lis[i + 1].first > lis[i].second) {
        for (int j = i + 1; j <= q; j++) {
          dec = min(dec, 
            max(0, min(lis[i + 1].first, lis[i].second + 1) - max(lis[i - 1].second, lis[i].first - 1) - 1) +
            max(0, min(lis[j + 1].first, lis[j].second + 1) - max(lis[j - 1].second, lis[j].first - 1) - 1));
        }
      } else {
        dec = min(dec, 
          min(lis[i + 2].first, lis[i + 1].second + 1) - max(lis[i - 1].second, lis[i].first - 1) - 1);
        dec = max(dec, 0);
        for (int j = i + 2; j <= q; j++) {
          dec = min(dec, 
            max(0, min(lis[i + 1].first, lis[i].second + 1) - max(lis[i - 1].second, lis[i].first - 1) - 1) +
            max(0, min(lis[j + 1].first, lis[j].second + 1) - max(lis[j - 1].second, lis[j].first - 1) - 1));
        }
      }
    }
    putint(ans - dec, '\n');
  }
  bufo.flush();
  return 0;
}