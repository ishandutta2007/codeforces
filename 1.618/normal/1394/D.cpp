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

#define maxn 200005
int n, h[maxn];
ll t[maxn];
vector<int> adj[maxn];
ll f[maxn][3];

void dfs(int u, int p) {
  int in = 0, out = 0;
  ll cst = 0;
  vector<ll> deltaIn, deltaOut;
  for (auto v : adj[u]) {
    if (v == p) continue;
    dfs(v, u);
    if (h[v] < h[u]) {
      in++;
      cst += f[v][2];
    } else if (h[v] > h[u]) {
      out++;
      cst += f[v][0];
    } else {
      if (f[v][0] <= f[v][2]) {
        out++;
        cst += f[v][0];
        deltaOut.push_back(f[v][2] - f[v][0]); 
      } else {
        in++;
        cst += f[v][2];
        deltaIn.push_back(f[v][0] - f[v][2]);
      }
    }
  }
  sort(deltaIn.begin(), deltaIn.end());
  sort(deltaOut.begin(), deltaOut.end());
  
  int tmpIn = in + 1, tmpOut = out; ll tmpCst = cst;
  f[u][0] = tmpCst + max(tmpIn, tmpOut) * t[u];
  if (tmpIn > tmpOut) {
    for (auto d : deltaIn) {
      tmpIn--;
      tmpOut++;
      tmpCst += d;
      f[u][0] = min(f[u][0], tmpCst + max(tmpIn, tmpOut) * t[u]);
    }
  } else if (tmpIn < tmpOut) {
    for (auto d : deltaOut) {
      tmpIn++;
      tmpOut--;
      tmpCst += d;
      f[u][0] = min(f[u][0], tmpCst + max(tmpIn, tmpOut) * t[u]);
    }
  }
  
  tmpIn = in, tmpOut = out, tmpCst = cst;
  f[u][1] = tmpCst + max(tmpIn, tmpOut) * t[u];
  if (tmpIn > tmpOut) {
    for (auto d : deltaIn) {
      tmpIn--;
      tmpOut++;
      tmpCst += d;
      f[u][1] = min(f[u][1], tmpCst + max(tmpIn, tmpOut) * t[u]);
    }
  } else if (tmpIn < tmpOut) {
    for (auto d : deltaOut) {
      tmpIn++;
      tmpOut--;
      tmpCst += d;
      f[u][1] = min(f[u][1], tmpCst + max(tmpIn, tmpOut) * t[u]);
    }
  }
  
  tmpIn = in, tmpOut = out + 1, tmpCst = cst;
  f[u][2] = tmpCst + max(tmpIn, tmpOut) * t[u];
  if (tmpIn > tmpOut) {
    for (auto d : deltaIn) {
      tmpIn--;
      tmpOut++;
      tmpCst += d;
      f[u][2] = min(f[u][2], tmpCst + max(tmpIn, tmpOut) * t[u]);
    }
  } else if (tmpIn < tmpOut) {
    for (auto d : deltaOut) {
      tmpIn++;
      tmpOut--;
      tmpCst += d;
      f[u][2] = min(f[u][2], tmpCst + max(tmpIn, tmpOut) * t[u]);
    }
  }
}

int main() {
  n = getint();
  for (int i = 1; i <= n; i++) t[i] = getint();
  for (int i = 1; i <= n; i++) h[i] = getint();
  for (int i = 1; i < n; i++) {
    int u = getint(), v = getint();
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0);
  putll(f[1][1], '\n');
  bufo.flush();
  return 0;
}