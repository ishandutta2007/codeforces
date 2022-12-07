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
}buff;
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
inline char get_char() {
  char c;
  for (c = buff.get(); c == ' ' || c == '\n' || c == '\r'; c = buff.get());
  return c;
}
#define maxn 1005
#define mp make_pair
typedef pair<int, int> P;
const ll infll = 0x3f3f3f3f3f3f3f3fll;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
int n, m, t;
char s[maxn][maxn];
queue <P> que;
ll dis[maxn][maxn];
int main() {
  n = getint(), m = getint(), t = getint();
  memset(dis, 0x3f, sizeof(dis));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      s[i][j] = get_char();
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int d = 0; d < 4; d++) {
        int ci = i + dx[d], cj = j + dy[d];
        if (ci && ci <= n && cj && cj <= m && s[ci][cj] == s[i][j]) {
          dis[i][j] = 0;
          que.push(mp(i, j));
        }
      }
    }
  }
  while (!que.empty()) {
    P p = que.front(); que.pop();
    int x = p.first, y = p.second;
    for (int d = 0; d < 4; d++) {
      int cx = x + dx[d], cy = y + dy[d];
      if (cx && cx <= n && cy && cy <= m && dis[cx][cy] == infll) {
        dis[cx][cy] = dis[x][y] + 1;
        que.push(mp(cx, cy));
      }
    }
  }
  while (t--) {
    int x = getint(), y = getint(); ll p = getll();
    if (p <= dis[x][y]) printf("%c\n", s[x][y]);
    else {
      p -= dis[x][y];
      if (p & 1) printf("%c\n", '0' + '1' - s[x][y]);
      else printf("%c\n", s[x][y]);
    }
  }
  return 0;
}