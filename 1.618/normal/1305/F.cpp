#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>
#include <ctime>
#include <random>

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
mt19937 rng;
vector<ll> pLis;
void factorize(ll x) {
  for (ll i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      pLis.push_back(i);
      while (x % i == 0) x /= i;
    }
  }
  if (x > 1) pLis.push_back(x);
}
int n;
ll ans, a[maxn];
void check(ll p) {
  ll res = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] < p) res += p - a[i];
    else res += min(a[i] % p, p - a[i] % p);
    if (res >= ans) return;
  }
  ans = res;
}
int main() {
  rng.seed(time(0));
  n = getint();
  ans = n;
  for (int i = 1; i <= n; i++) a[i] = getll();
  shuffle(a + 1, a + n + 1, rng);
  for (int i = 1; i <= min(n, 32); i++) {
    if(a[i] > 1) factorize(a[i] - 1);
    factorize(a[i]);
    factorize(a[i] + 1);
  }
  sort(pLis.begin(), pLis.end());
  pLis.erase(unique(pLis.begin(), pLis.end()), pLis.end());
  for (auto p : pLis) {
    check(p);
//    cout << p << " " << ans << endl;
  }
  putll(ans, '\n');
  bufo.flush();
  return 0;
}