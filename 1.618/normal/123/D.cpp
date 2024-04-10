#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <set>
#include <map>
#define maxn 100005

using namespace std;
typedef long long ll;
char s[maxn];
int n, m, k, sa[maxn], rk[maxn << 1], cnt[maxn], id[maxn], tmp[maxn];
int lcp[maxn];
void calc_sa() {
  m = 'z';
  for (int i = 1; i <= n; i++) cnt[rk[i] = s[i]]++;
  for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
  for (int i = n; i >= 1; i--) sa[cnt[rk[i]]--] = i;
  m = 0;
  for (int i = 1; i <= n; i++) {
    if (rk[sa[i]] == rk[sa[i - 1]]) tmp[sa[i]] = m;
    else tmp[sa[i]] = ++m;
  }
  memcpy(rk, tmp, sizeof(tmp));
  for (int w = 1; m < n; w <<= 1) {
    k = 0;
    for (int i = n; i > n - w; i--) id[++k] = i;
    for (int i = 1; i <= n; i++) if (sa[i] > w) id[++k] = sa[i] - w;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++) cnt[lcp[i] = rk[id[i]]]++;
    for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
    for (int i = n; i >= 1; i--) sa[cnt[lcp[i]]--] = id[i];
    m = 0;
    for (int i = 1; i <= n; i++) {
      if (rk[sa[i]] == rk[sa[i - 1]] && rk[sa[i] + w] == rk[sa[i - 1] + w])
        tmp[sa[i]] = m;
      else 
        tmp[sa[i]] = ++m;
    }
    memcpy(rk, tmp, sizeof(tmp));
  }
}
void calc_lcp() {
  k = 0;
  for (int i = 1; i <= n; i++) {
    if (k) k--;
    while (s[i + k] == s[sa[rk[i] - 1] + k]) k++;
    lcp[rk[i]] = k;
  }
}
int stk[maxn], up[maxn];
int main(){
  scanf("%s", s + 1);
  n = strlen(s + 1);
  calc_sa(); calc_lcp();
  k = 0;
  for (int i = 1; i <= n; i++) {
    while (k && lcp[stk[k]] > lcp[i]) k--;
    up[i] = i - (k ? stk[k] : 1);
    stk[++k] = i;
  }
  k = 0;
  ll ans = 0;
  for (int i = n; i >= 1; i--) {
    while (k && lcp[stk[k]] >= lcp[i]) k--;
    int down = (k ? stk[k] : n + 1) - i;
    ans += (ll)up[i] * down * lcp[i];
    stk[++k] = i;
  }
  printf("%lld\n", ans + (ll)n * (n + 1) / 2);
	return 0;
}