// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#pragma GCC target("avx", "avx2")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
#define poly vector<int>
#define SZ(x) (int(x.size()))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }

namespace IO {
  const int SIZE = 1 << 16;
  char ibuf[SIZE]; int iS, iT;
  char obuf[SIZE]; int oT;
  inline char gc() {
    if (iS == iT)
      iS = 0, iT = fread(ibuf, 1, SIZE, stdin);
    return iS == iT ? EOF : ibuf[iS++];
  }
  inline void pc(char c) {
    obuf[oT++] = c;
    if (oT == SIZE)
      fwrite(obuf, 1, SIZE, stdout), oT = 0;
  }
  inline int read() {
    int x = 0, f = 0;
    char c = gc();
    while (!isdigit(c)) f |= c == '-', c = gc();
    while (isdigit(c)) x = 10 * x + c - '0', c = gc();
    return f ? -x : x; 
  }
  inline void print(int64_t x) {
    static char bufn[64];
    int len = 0;
    if (x < 0) x = -x, pc('-');
    while (x >= 10) bufn[len++] = x % 10 + '0', x /= 10;
    bufn[len++] = x + '0';
    while (len--) pc(bufn[len]);
  }
  inline void print(int64_t x, char ch) {
    print(x), pc(ch);
  }
  struct ff {
    ~ff() {
      if (oT)
        fwrite(obuf, 1, oT, stdout);
    }
  } flusher;
}
using namespace IO;

const int N = 200005;
const int B = 450;

struct Q {
  int opt, x, y;
} qry[N];

int p[N], n, m, q;

bool black[N];
vector<int> chain[N];
int bid[N], go[N]; ll bval[N];
ll a[N], sum[N];

void solve() {
  rep(i, 1, n) {
    sum[i] = sum[i - 1] + a[i];
    bid[i] = 0;
    bval[i] = 0;
    chain[i].clear(), chain[i].shrink_to_fit();
  }
  
  rep(i, 1, q) {
    qry[i].opt = read(), qry[i].x = read(), qry[i].y = read();
    if (qry[i].opt == 2) black[qry[i].x] = 1;
    if (qry[i].opt == 3) black[qry[i].x] = black[qry[i].y] = 1;
  }
  
  static bool vis[N];
  static int cyc[N], len;
  fill(vis + 1, vis + n + 1, 0);
  rep(i, 1, n) if (!vis[i]) {
    bool have_black = 0;
    { //  
      int j = i;
      len = 0;
      do {
        have_black |= black[j];
        cyc[++len] = j;
        vis[j] = 1;
        j = p[j];
      } while (j != i);
    }
    if (!have_black) continue;
    int lst = -1;
    rep(j, 1, len) if (black[cyc[j]]) { lst = cyc[j]; break; }
    assert(lst != -1);
    per(j, len, 1) { //  
      if (black[cyc[j]]) {
        go[cyc[j]] = lst;
        lst = cyc[j];
      }
      bid[cyc[j]] = lst;
    }
  }
  vector<int> used;
  rep(i, 1, n) if (black[i]) used.pb(i);
  rep(i, 1, n) if (bid[i]) chain[bid[i]].pb(i);
  /*
  printf(">>> black: ");
  rep(i, 1, n) {
    if (black[i]) printf("%d ", i);
  }
  puts("");
  
  rep(i, 1, n) {
    printf("bid[%d] = %d\n", i, bid[i]);
  }
  */
  rep(i, 1, q) {
    if (qry[i].opt == 1) {
      ll ans = sum[qry[i].y] - sum[qry[i].x - 1];
      for (auto c: used) {
        int num = upper_bound(chain[c].begin(), chain[c].end(), qry[i].y) - 
                  lower_bound(chain[c].begin(), chain[c].end(), qry[i].x);
        ans += num * bval[c];
      }
      print(ans, '\n');
    } else if (qry[i].opt == 2) {
      int j = bid[qry[i].x], jj = j;
      do {
        bval[j] += qry[i].y;
        j = go[j];
      } while (j != jj);
    } else {
//      assert(bid[qry[i].x] == qry[i].x);
//      assert(bid[qry[i].y] == qry[i].y);
      swap(go[qry[i].x], go[qry[i].y]);
    }
  }
  
  rep(i, 1, n) if (bid[i]) a[i] += bval[bid[i]];
  rep(i, 1, q) {
    if (qry[i].opt == 2) black[qry[i].x] = 0;
    if (qry[i].opt == 3) swap(p[qry[i].x], p[qry[i].y]), black[qry[i].x] = black[qry[i].y] = 0;
  }
}

int main() {
  n = read();
  rep(i, 1, n) a[i] = read();
  rep(i, 1, n) p[i] = read();
  m = read();
  while (m) {
    q = min(m, B), m -= q;
    solve();
  }
  return 0;
}