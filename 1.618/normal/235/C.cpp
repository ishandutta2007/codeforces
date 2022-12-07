// CF 235C
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#define maxn 1000005
#define maxx 2000005

using namespace std;
typedef long long ll;

// m: |x_i|
// q: number of queries ( = 'n' in the statement)
int m, q;
namespace SAM {
  struct node {
    int link, len, nxt[26];
  }a[maxn << 1];
  int n, V, lst;
  char s[maxn];
  void init() {
    V = lst = a[0].len = 0;
    a[0].link = -1;
  }
  void append(char c) {
    c -= 'a';
    int cur = ++V, p = lst;
    a[cur].len = a[p].len + 1;
    while (~p && !a[p].nxt[c]) {
      a[p].nxt[c] = cur;
      p = a[p].link;
    }
    if (p == -1) {
      a[cur].link = 0;
    } else {
      int q = a[p].nxt[c];
      if (a[p].len + 1 == a[q].len) {
        a[cur].link = q;
      } else {
        int tmp = ++V;
        a[tmp] = a[q];
        a[tmp].len = a[p].len + 1;
        while (~p && a[p].nxt[c] == q) {
          a[p].nxt[c] = tmp;
          p = a[p].link;
        }
        a[q].link = a[cur].link = tmp;
      }
    }
    lst = cur;
  }
  int siz[maxn << 1], cnt[maxn], topo[maxn << 1];
  void calcSiz() {
    int u = 0;
    for (int i = 1; i <= n; i++) {
      u = a[u].nxt[s[i] - 'a'];
      siz[u] = 1;
    }
    for (int i = 0; i <= V; i++) cnt[a[i].len]++;
    for (int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
    for (int i = V; i >= 0; i--) topo[--cnt[a[i].len]] = i;
    for (int i = V; i >= 1; i--) {
      u = topo[i];
      siz[a[u].link] += siz[u];
    }
  }
}
namespace KMP {
  char x[maxx];
  int n, nxt[maxx];
  void init() {
    n = 0;
    nxt[0] = -1;
  }
  void calcNxt() {
    for (int i = 1; i <= n; i++) {
      int u = nxt[i - 1];
      while (~u && x[u + 1] != x[i]) u = nxt[u];
      nxt[i] = u + 1;
    }
  }
  int calcMin() {
    calcNxt();
    
//    for (int i = 0; i <= n; i++) cout << nxt[i] << " ";
//    cout << endl;
//    system("pause");
    
    int u = n;
    for (int i = 1; i <= n; i++) {
      while (~u && x[u + 1] != x[i]) u = nxt[u];
      u++;
      
//      cout << i << ": " << u << endl;
      
      if (u == n) return i + n;
    }
  }
}
int main() {
  scanf("%s", SAM::s + 1);
  SAM::n = strlen(SAM::s + 1);
  SAM::init();
  for (int i = 1; i <= SAM::n; i++) SAM::append(SAM::s[i]);
  SAM::calcSiz();
  scanf("%d", &q);
  while (q--) {
    KMP::init();
    scanf("%s", KMP::x + 1);
    m = KMP::n = strlen(KMP::x + 1);
    int tmp = KMP::calcMin(), u = 0, l = 0, ans = 0;
    
//    cout << tmp << endl;
//    system("pause");
    
    for (int i = 1; i < m; i++) {
      while (~u && !SAM::a[u].nxt[KMP::x[i] - 'a']) {
        u = SAM::a[u].link;
        if (~u) l = SAM::a[u].len;
      }
      if (u == -1) u = 0;
      else {
        u = SAM::a[u].nxt[KMP::x[i] - 'a'];
        ++l;
      }
    }
    for (int i = m; i < tmp; i++) {
      int c = (i == m) ? KMP::x[i] - 'a' : KMP::x[i - m] - 'a';
      while (~u && !SAM::a[u].nxt[c]) {
        u = SAM::a[u].link;
        if (~u) l = SAM::a[u].len;
      }
      if (u == -1) u = 0;
      else {
        u = SAM::a[u].nxt[c];
        ++l;
      }
      while (u && SAM::a[SAM::a[u].link].len >= m) {
        u = SAM::a[u].link;
        l = SAM::a[u].len;
      }
      if (l >= m) ans += SAM::siz[u];
    }
    printf("%d\n", ans);
  }
  return 0;
}