#include <bits/stdc++.h>
using namespace std;
const int K = 18;
const int N = 2e5 + 5;
int n, m, tot, x, lg[N], f[31][N];
int ht[N], mi[K][N];
char s[N], t[N], st[N];
int sa[N], rk[N], ork[N], buc[N], id[N];
bool cmp(int a, int b, int w) {return ork[a] == ork[b] && ork[a + w] == ork[b + w];}
void build() {
  int m = 1 << 7, p = 0;
  for(int i = 1; i <= tot; i++) buc[rk[i] = st[i]]++;
  for(int i = 1; i <= m; i++) buc[i] += buc[i - 1];
  for(int i = tot; i; i--) sa[buc[rk[i]]--] = i;
  for(int w = 1; ; w <<= 1, m = p, p = 0) {
    for(int i = tot - w + 1; i <= tot; i++) id[++p] = i;
    for(int i = 1; i <= tot; i++) if(sa[i] > w) id[++p] = sa[i] - w;
    memset(buc, 0, sizeof(buc));
    memcpy(ork, rk, sizeof(rk));
    p = 0;
    for(int i = 1; i <= tot; i++) buc[rk[id[i]]]++;
    for(int i = 1; i <= m; i++) buc[i] += buc[i - 1];
    for(int i = tot; i; i--) sa[buc[rk[id[i]]]--] = id[i];
    for(int i = 1; i <= tot; i++) rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
    if(p == tot) break;
  }
  for(int i = 1, k = 0; i <= tot; i++) {
    if(k) k--;
    while(st[i + k] == st[sa[rk[i] - 1] + k]) k++;
    ht[rk[i]] = k;
  }
  for(int i = 1; i <= tot; i++) mi[0][i] = ht[i];
  for(int i = 1; i <= lg[tot]; i++)
    for(int j = 1; j + (1 << i) - 1 <= tot; j++)
      mi[i][j] = min(mi[i - 1][j], mi[i - 1][j + (1 << i - 1)]);
}
int lcp(int i, int j) { // s[i] & t[j]
  if(j > m || i > n) return 0;
  j += n + 1;
  if((i = rk[i]) > (j = rk[j])) swap(i, j);
  int d = lg[j - (i++)];
  return min(mi[d][i], mi[d][j - (1 << d) + 1]);
}
int main() {
#ifdef ALEX_WEI
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);
#endif
  cin >> n >> s + 1 >> m >> t + 1;
  for(int i = 1; i <= n; i++) st[++tot] = s[i];
  st[++tot] = '#';
  for(int i = 1; i <= m; i++) st[++tot] = t[i];
  for(int i = 2; i <= tot; i++) lg[i] = lg[i >> 1] + 1;
  build();
  cin >> x;
  for(int i = 1; i <= x; i++)
    for(int j = 0; j < n; j++) {
      int L = lcp(j + 1, f[i - 1][j] + 1);
      f[i][j + L] = max(f[i][j + L], f[i - 1][j] + L);
      f[i][j + 1] = max(f[i][j + 1], f[i][j]);
    }
  if(f[x][n] == m) puts("YES");
  else puts("NO");
  return cerr << "Time: " << clock() << endl, 0;
}
/*
2022/6/15
start coding at 8:55
finish debugging at
*/