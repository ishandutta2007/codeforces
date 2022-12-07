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
#define mp make_pair
typedef pair<int, int> P;
int n, m, k, t;
vector <int> adj[maxn], rev[maxn], nxt[maxn];
int dis[maxn], p[maxn], pnxt[maxn];
int main() {
  n = getint(), m = getint();
  for (int i = 1; i <= m; i++) {
    int u = getint(), v = getint();
    adj[u].push_back(v);
    rev[v].push_back(u);
  }
  k = getint();
  for (int i = 1; i <= k; i++) p[i] = getint();
  t = p[k];
  
//  cout << t << endl;
  
  for (int i = 1; i < k; i++) pnxt[p[i]] = p[i + 1];
  memset(dis, 0x3f, sizeof(dis));
  queue <int> que;
  dis[t] = 0;
  que.push(t);
  while (!que.empty()) {
    int u = que.front(); que.pop();
    
//    cout << u << endl;
    
    for (int i = 0; i < (int)rev[u].size(); i++) {
      int v = rev[u][i];
      if (dis[u] + 1 < dis[v]) {
        dis[v] = dis[u] + 1;
        que.push(v);
      }
    }
  }
  int mini = 0, maxi = 0;
  for (int i = 1; i <= n; i++) {
    
//    cout << i << ":\n";
    
    for (int j = 0; j < (int)adj[i].size(); j++) {
      int v = adj[i][j];
      
//      cout << i << " " << v << endl;
      
      if (dis[i] == dis[v] + 1) {
        nxt[i].push_back(v);
        if (v == pnxt[i]) maxi++;
      }
    }
    
//    system("pause");
    
    if (nxt[i].size() == 1 && nxt[i].front() == pnxt[i]) mini++;
  }
  
//  for (int i = 1; i <= n; i++){
//    cout << dis[i] << " ";
//    for(int j = 0;j < (int)nxt[i].size();j++){
//      cout << nxt[i][j] << " ";
//    }
//    cout << endl;
//  }
//  cout << endl;
//  system("pause");
  
  putint(k - 1 - maxi, ' ');
  putint(k - 1 - mini, '\n');
  bufo.flush();
  return 0;
}