/*
result of thinking: Pure.

start coding: 8:31
AC:
*/
#include <bits/stdc++.h>
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
    if (it == LEN) fwrite(s, 1, LEN, stdout), it = 0;
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
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 100005
int n, m;
vector<int> adj[maxn][10]; 
queue<vector<int>> que;
// vectordis 
int prvv[maxn], prvw[maxn];

void printAns() {
  string dis;
  vector<int> path;
  for (int i = 1; i != n; i = prvv[i]) {
    dis.push_back(prvw[i] + '0');
    path.push_back(i);
  }
  while (dis.size() > 1 && dis.back() == '0')
    dis.pop_back();
  for (int i = dis.size() - 1; i >= 0; i--)
    bufo.put(dis[i]);
  bufo.put('\n');
  path.push_back(n);
  putint(path.size(), '\n');
  for (auto i : path)
    putint(i - 1, ' ');
  bufo.put('\n');
}

int main() {
  n = getint(), m = getint();
  for (int i = 1; i <= m; i++) {
    int u = getint() + 1, v = getint() + 1, w = getint();
    adj[u][w].push_back(v);
    adj[v][w].push_back(u);
  }
  
  memset(prvv, -1, sizeof(prvv));
  memset(prvw, -1, sizeof(prvw));
  prvv[n] = prvw[n] = 0;
  queue<int> queLocal;
  queLocal.push(n);
  vector<int> ends;
  while (!queLocal.empty()) {
    int u = queLocal.front();
    queLocal.pop();
    ends.push_back(u);
    for (auto v : adj[u][0]) {
      if (prvv[v] == -1) {
        prvv[v] = u;
        prvw[v] = 0;
        queLocal.push(v);
      }
    }
  }
  if (~prvv[1]) {
    printAns();
    bufo.flush();
    return 0;
  }
  
  que.push(ends);
  while (!que.empty()) {
    vector<int> S = que.front();
    
//    for (auto i : S) {
//      cout << i << " ";
//    }
//    cout << endl;
//    system("pause");
    
    que.pop();
    for (int i = 0; i < 10; i++) {
      vector<int> T;
      for (auto u : S) {
        for (auto v : adj[u][i]) {
          if (prvv[v] == -1) {
            prvv[v] = u;
            prvw[v] = i;
            T.push_back(v);
          }
        }
      }
      if (T.size()) que.push(T);
    }
  }
  printAns();
  bufo.flush();
  return 0;
}