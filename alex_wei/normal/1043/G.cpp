#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define fi first
#define se second
#define TIME 1e3 * clock() / CLOCKS_PER_SEC
bool Mbe;
constexpr int K = 18;
constexpr int N = 2e5 + 5;
char s[N];
int n, q, lg[N], nxt[N], pre[N], pos[128], st[K][N];
struct SA {
  int sa[N], rk[N], ork[N], buc[N], id[N], mi[K][N];
  bool cmp(int a, int b, int w) {return ork[a] == ork[b] && ork[a + w] == ork[b + w];}
  void build(char *s) {
    int m = 1 << 7, p = 0;
    for(int i = 1; i <= n; i++) buc[rk[i] = s[i]]++;
    for(int i = 1; i <= m; i++) buc[i] += buc[i - 1];
    for(int i = n; i; i--) sa[buc[rk[i]]--] = i;
    for(int w = 1; ; w <<= 1, m = p, p = 0) {
      for(int i = n - w + 1; i <= n; i++) id[++p] = i;
      for(int i = 1; i <= n; i++) if(sa[i] > w) id[++p] = sa[i] - w;
      memset(buc, 0, sizeof(buc));
      memcpy(ork, rk, sizeof(rk));
      p = 0;
      for(int i = 1; i <= n; i++) buc[rk[i]]++;
      for(int i = 1; i <= m; i++) buc[i] += buc[i - 1];
      for(int i = n; i; i--) sa[buc[rk[id[i]]]--] = id[i];
      for(int i = 1; i <= n; i++) rk[sa[i]] = cmp(sa[i - 1], sa[i], w) ? p : ++p;
      if(p == n) break;
    }
    for(int i = 1, k = 0; i <= n; i++) {
      if(k) k--;
      while(s[i + k] == s[sa[rk[i] - 1] + k]) k++;
      mi[0][rk[i]] = k;
    }
    for(int i = 1; i <= lg[n]; i++)
      for(int j = 1; j + (1 << i) - 1 <= n; j++)
        mi[i][j] = min(mi[i - 1][j], mi[i - 1][j + (1 << i - 1)]);
  }
  int lcp(int a, int b) {
    assert(a != b);
    if((a = rk[a]) > (b = rk[b])) swap(a, b);
    int d = lg[b - a++];
    return min(mi[d][a], mi[d][b - (1 << d) + 1]);
  }
} sa, rev;
struct dsu {
  int fa[N], val[N];
  void init() {
    for(int i = 1; i <= n + 1; i++) fa[i] = i; // n -> n + 1
    memset(val, 0x3f, sizeof(val)); // add this line
  }
  int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
  void modify(int l, int r, int v) {
    if(l > r) return; // add this line
    while(1) {
      int p = find(l);
      if(p > r) break;
      val[p] = v, fa[p] = p + 1;
    }
  }
} lft, rt;
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  ios::sync_with_stdio(0);
  cin >> n >> s + 1;
  for(int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
  for(int i = 1; i <= n; i++) pre[i] = pos[s[i]], pos[s[i]] = i;
  memset(pos, 0x3f, sizeof(pos)); // 0 -> 0x3f
  for(int i = n; i; i--) nxt[i] = pos[s[i]], pos[s[i]] = i;
  sa.build(s);
  reverse(s + 1, s + n + 1);
  rev.build(s);
  lft.init(), rt.init();
  for(int i = 1; i * 2 <= n; i++)
    for(int p = i, q = i + i; q <= n; p += i, q += i) {
      int L = rev.lcp(n - p + 1, n - q + 1), R = sa.lcp(p, q);
      int l = p - L + 1, r = q + R - 1;
      lft.modify(l, r - 2 * i + 1, i * 2);
      rt.modify(l + 2 * i - 1, r, i * 2);
    }
  for(int i = 1; i <= n; i++) st[0][i] = i + lft.val[i] - 1;
  for(int i = 1; i <= lg[n]; i++)
    for(int j = 1; j + (1 << i) - 1 <= n; j++)
      st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
  int B = 300;
  cin >> q;
  for(int i = 1; i <= q; i++) {
    int l, r, L;
    cin >> l >> r, L = r - l + 1;
    bool found = 0;
    for(int j = l; j < r && !found; j++) found |= nxt[j] <= r;
    if(!found) {cout << "-1\n"; continue;}
    found = 0;
    for(int d = 1; d * d <= L; d++)
      if(L % d == 0) {
        found |= sa.lcp(l, l + d) >= L - d;
        if(d != 1) found |= sa.lcp(l, l + L / d) >= L - L / d;
      }
    if(found) {cout << "1\n"; continue;}
    if(l + lft.val[l] - 1 <= r || r - rt.val[r] + 1 >= l) {cout << "2\n"; continue;}
    int lim = min(L - 1, B);
    for(int i = 1; i <= lim; i++) found |= sa.lcp(l, r - i + 1) >= i;
    if(found) {cout << "2\n"; continue;}
    int lcp = N;
    for(int i = sa.rk[l] - 1; i && !found; i--) {
      if(sa.mi[0][i + 1] < B) break;
      int q = sa.sa[i];
      lcp = min(lcp, sa.mi[0][i + 1]);
      found |= q > l && q <= r && q + lcp - 1 >= r;
    }
    lcp = N;
    for(int i = sa.rk[l] + 1; i <= n && !found; i++) {
      if(sa.mi[0][i] < B) break;
      int q = sa.sa[i];
      lcp = min(lcp, sa.mi[0][i]);
      found |= q > l && q <= r && q + lcp - 1 >= r;
    }
    if(found) {cout << "2\n"; continue;}
    if(nxt[l] <= r || pre[r] >= l) {cout << "3\n"; continue;}
    int d = lg[L];
    if(min(st[d][l], st[d][r - (1 << d) + 1]) <= r) cout << "3\n";
    else cout << "4\n";
  }
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/8/28
author: Alex_Wei
start coding: 6:44
finish debugging: 7:40
*/