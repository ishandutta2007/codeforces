#include <bits/stdc++.h>
using namespace std;
bool Mbe;
constexpr int K = 18;
constexpr int N = 2e5 + 5;
char s[N];
int n, q, lg[N], mi[K][N], ht[N];
int sa[N], rk[N], ork[N], buc[N], id[N];
bool cmp(int a, int b, int w) {return ork[a] == ork[b] && ork[a + w] == ork[b + w];}
void build() {
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
    for(int i = 1; i <= n; i++) buc[rk[id[i]]]++;
    for(int i = 1; i <= m; i++) buc[i] += buc[i - 1];
    for(int i = n; i; i--) sa[buc[rk[id[i]]]--] = id[i];
    for(int i = 1; i <= n; i++) rk[sa[i]] = cmp(sa[i - 1], sa[i], w) ? p : ++p;
    if(p == n) break;
  }
  for(int i = 1, k = 0; i <= n; i++) {
    if(k) k--;
    while(s[i + k] == s[sa[rk[i] - 1] + k]) k++;
    mi[0][rk[i]] = ht[rk[i]] = k;
  }
  // for(int i = 1; i <= n; i++) cout << i << " " << ht[i] << endl;
  for(int i = 1; i <= lg[n]; i++)
    for(int j = 1; j + (1 << i) - 1 <= n; j++)
      mi[i][j] = min(mi[i - 1][j], mi[i - 1][j + (1 << i - 1)]);
}
int lcp(int i, int j) { // i, j are ranks
  int d = lg[j - (i++)];
  return min(mi[d][i], mi[d][j - (1 << d) + 1]);
}
long long calc(vector<int> a, vector<int> b) {
  static int top, stc[N], wid[N];
  long long area = 0, ans = 0;
  top = 0;
  auto push = [&](int w, int h) {
    while(top && stc[top] >= h) {
      area -= 1ll * stc[top] * wid[top];
      w += wid[top--];
    }
    stc[++top] = h, wid[top] = w;
    area += 1ll * w * h;
  };
  for(int i = 0, p = -1; i < b.size(); i++) {
    while(p + 1 < a.size() && a[p + 1] < b[i]) {
      if(p >= 0) push(0, lcp(a[p], a[p + 1]));
      push(1, n - sa[a[p + 1]] + 1);
      p++;
    }
    if(p >= 0) push(0, lcp(a[p], b[i]));
    ans += area;
  }
  return ans;
}
bool Med;
int main() {
  fprintf(stderr, "%.4lf\n", (&Mbe - &Med) / 1048576.0);
#ifdef ALEX_WEI
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);
#endif
  scanf("%d%d%s", &n, &q, s + 1);
  for(int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
  build();
  for(int i = 1; i <= q; i++) {
    int k, l, w;
    vector<int> a, b;
    scanf("%d%d", &k, &l);
    long long ans = 0;
    for(int i = 1; i <= k; i++) scanf("%d", &w), a.push_back(w);
    for(int i = 1, p = -1; i <= l; i++) {
      scanf("%d", &w), b.push_back(w);
      while(p + 1 < k && a[p + 1] <= w) p++;
      if(p >= 0 && a[p] == w) ans += n - w + 1;
    }
    for(int &it : a) it = rk[it];
    for(int &it : b) it = rk[it];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    printf("%lld\n", ans + calc(a, b) + calc(b, a));
  }
  return cerr << "Time: " << clock() << "\n", 0;
}
/*
2022/6/21
start coding at 7:22
finish debugging at 13:14
*/