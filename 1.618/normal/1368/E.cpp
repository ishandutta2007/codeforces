#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <set>

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
int T, n, m;
vector<int> adj[maxn];
set<int> S, ans;
int deg[maxn];

//void printData() {
//  for (int i = 1; i <= n; i++) {
//    putint(i, ':');
//    for (auto j : adj[i]) putint(j, ' ');
//  }
//}

void solve() {
  n = getint(), m = getint();
  S.clear(); ans.clear();
  for (int i = 1; i <= n; i++) {
    deg[i] = 0;
    adj[i].clear();
    S.insert(i);
  }
  // Sdangerous path 
  for (int i = 1; i <= m; i++) {
    int u = getint(), v = getint();
    adj[u].push_back(v);
    deg[v]++;
  }
  
//  for (int i = 1; i <= n; i++) cout << deg[i] << " ";
//  cout << endl;
//  system("pause");
  
  while (!S.empty()) {
    int u = *S.begin();
    if (deg[u]) {
      for (auto v : adj[u]) {
        if (ans.count(v)) continue;
        ans.insert(v);
        S.erase(v);
        for (auto w : adj[v]) deg[w]--;
      }
    }
    S.erase(u);
    
//    cout << "S: ";
//    for (auto v : S) cout << v << " ";
//    cout << endl;
//    for (int i = 1; i <= n; i++) cout << deg[i] << " ";
//    cout << endl;
//    system("pause");
    
  }
  
//  if (n == 10 && m == 17 && ans.size() == 2) printData();
  
  putint(ans.size(), '\n');
  for (auto u : ans) putint(u, ' ');
  bufo.put('\n');
}
int main() {
  T = getint();
  while (T--) solve();
  bufo.flush();
  return 0;
}