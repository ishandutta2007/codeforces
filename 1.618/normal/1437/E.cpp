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
    it = 0;
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

#define maxn 500005
const int inf = 0x3f3f3f3f;
int n, k, a[maxn], b[maxn];
int f[maxn];

int solve(vector<int> a) {
  
//  for (auto i : a) {
//    cout << i << " ";
//  }
//  cout << endl;
//  system("pause");
  
  for (int i = 1; i <= (int)a.size() + 1; i++) f[i] = inf;
  for (auto i : a) {
    *upper_bound(f + 1, f + a.size() + 1, i) = i;
  }
  return lower_bound(f + 1, f + a.size() + 1, inf) - f - 1;
}
  
int main() {
  n = getint(), k = getint();
  a[0] = -inf;
  for (int i = 1; i <= n; i++) a[i] = getint() - i;
  a[n + 1] = inf;
  for (int i = 1; i <= k; i++) b[i] = getint();
  b[0] = 0, b[k + 1] = n + 1;
  int ans = k;
  for (int i = 1; i <= k + 1; i++) {
    if (a[b[i]] < a[b[i - 1]]) {
      puts("-1");
      return 0;
    }
    vector<int> tmp;
    for (int j = b[i - 1] + 1; j < b[i]; j++) {
      if (a[j] >= a[b[i - 1]] && a[j] <= a[b[i]]) tmp.push_back(a[j]); 
    }
    
//    cout << b[i - 1] << " " << b[i] << ": " << solve(tmp) << endl;
//    system("pause");
    
    ans += solve(tmp);
  }
  putint(n - ans, '\n');
  bufo.flush();
  return 0;
}