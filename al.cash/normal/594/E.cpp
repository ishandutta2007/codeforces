#include <bits/stdc++.h>

using namespace std;

template<class T>
int duval(const T* s, int n, int* d) {
  int r = 0;
  for (int i = 0, j, k; i < n; ) {
    for (k = i, j = i+1; j < n && s[k] <= s[j]; ++j)
      s[k] < s[j] ? k = i : ++k;
    for (d[r++] = i; i <= k; i += j-k);
  }
  return r;
}

template<class T>
void z_function(const T* s, int n, int* z) {
  z[0] = n;
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    z[i] = i > r ? 0 : min(r-i+1, z[i-l]);
    while (i+z[i] < n && s[z[i]] == s[i+z[i]]) ++z[i];
    if (i+z[i]-1 > r) l = i, r = i+z[i]-1;
  }
}

const int N = 5e6+1;
int n, k, z[2*N], d[N];
char s[2*N], ans[N], t[N];
char* cur = ans;

void add(const char* src, int l, char*& dst) {
  copy(src, src + l, dst);
  dst += l;
}

void add_suf(int l, char* dst) {
  int c = z[2*n+1-l];
  add((c >= l || s[c] > s[l-1-c]) ? s+2*n+1-l : s, l, dst);
}

int main() {
  scanf("%s%d", s, &k);
  n = strlen(s);
  copy(s, s + n, s + n+1);
  reverse_copy(s + n+1, s + 2*n+1, s);
  z_function(s, 2*n+1, z);
  int l = n, m = duval(s, n, d) - 1;
  if (k > 2) for (; 0 <= m; l = d[m], --m) {
    bool ok = true;
    for (int i = d[m]; i < l; ++i) if (s[i] != s[l-1]) ok = false;
    if (!ok) break;
  }
  if (l != n) --k;
  add(s + n+1, n-l, cur);
  for (; 0 <= m && 2 < k; l = d[m], --m, --k)
    add(s + d[m], l - d[m], cur);
  if (k == 1 || m <= 0) {
    add_suf(l, cur);
  } else {
    char* c = t;
    add(ans, n - l, c);
    add(s + d[m], l - d[m], cur);
    add_suf(d[m], cur);
    add(s + d[m-1], l - d[m-1], c);
    add_suf(d[m-1], c);
    if (strcmp(t, ans) < 0) copy(t, t + n, ans);

    int best = 1;
    for (int i = 2; i < l; ++i) {
      int p = z[2*n+1-i];
      if (p < i - best) {
        if (s[p] < s[i-1-p]) best = i;
      } else {
        p = z[i-best];
        if (p <= best && s[i-best+p] < s[p]) best = i;
      }
    }
    add(ans, n - l, c = t);
    add(s + 2*n+1-l, l-best, c);
    add(s, best, c);
    if (strcmp(t, ans) < 0) copy(t, t + n, ans);
  }
  printf("%s\n", ans);
  return 0;
}