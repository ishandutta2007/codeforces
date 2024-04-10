/*
start thinking:
BULB:
result of thinking:

#SA
: [NOI2016]  ""
border  polylog, 

start coding:
AC:

/fn SA/fn
*/
#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template <class T1, class T2> bool chmin(T1 &x, const T2 &y) {
  return x > y ? (x = y, true) : false;
}
template <class T1, class T2> bool chmax(T1 &x, const T2 &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 200005

struct SA {
  int n, m, k, sa[maxn], rk[maxn << 1], cnt[maxn], id[maxn], tmp[maxn];
  int lcp[18][maxn];
  char s[maxn];

  void calc_sa() {
    for (int i = 1; i <= n; i++)
      cnt[rk[i] = s[i]]++;
    for (int i = 1; i <= 130; i++)
      cnt[i] += cnt[i - 1];
    for (int i = n; i >= 1; i--)
      sa[cnt[rk[i]]--] = i;
    m = 0;
    for (int i = 1; i <= n; i++) {
      if (rk[sa[i]] == rk[sa[i - 1]])
        tmp[sa[i]] = m;
      else
        tmp[sa[i]] = ++m;
    }
    memcpy(rk, tmp, sizeof(tmp));
    for (int w = 1; m < n; w <<= 1) {
      k = 0;
      for (int i = n; i > n - w; i--)
        id[++k] = i;
      for (int i = 1; i <= n; i++)
        if (sa[i] > w)
          id[++k] = sa[i] - w;
      memset(cnt, 0, sizeof(cnt));
      for (int i = 1; i <= n; i++)
        cnt[rk[i]]++;
      for (int i = 1; i <= m; i++)
        cnt[i] += cnt[i - 1];
      for (int i = n; i >= 1; i--)
        sa[cnt[rk[id[i]]]--] = id[i];
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
      lcp[0][rk[i]] = k;
    }
    for (int i = 1; i <= 17; i++) {
      for (int j = 1; j + (1 << i) - 1 <= n; j++) {
        lcp[i][j] = min(lcp[i - 1][j], lcp[i - 1][j + (1 << (i - 1))]);
      }
    }
  }

  void build() { calc_sa(); calc_lcp(); }

  int qlcp(int x, int y) {
    if (x == y)
      return n - x + 1;
    x = rk[x], y = rk[y];
    if (x > y)
      swap(x, y);
    x++;
    int ro = 31 - __builtin_clz(y - x + 1);
    return min(lcp[ro][x], lcp[ro][y - (1 << ro) + 1]);
  }
} s, rev;

#define maxn 200005
const int SQRT_N = 450;
int n, nxt[maxn], pre[maxn];
char s0[maxn];

int LCP(int i, int j) { return s.qlcp(i, j); }
int LCS(int i, int j) { return rev.qlcp(n - i + 1, n - j + 1); }

struct Diff {
  vector<int> d[maxn];
  int a[maxn];
  
  void add(int l, int r, int x) {
    if (l > r)
      return;
    d[l].push_back(x);
    if (r < n)
      d[r + 1].push_back(-x);
  }

  void work() {
    set<int> foo;
    for (int i = 1; i <= n; i++)
      sort(d[i].begin(), d[i].end());
    for (int i = 1; i <= n; i++) {
      for (auto j : d[i]) {
        if (j < 0)
          foo.erase(-j);
        else
          foo.insert(j);
      }
      if (foo.size())
        a[i] = *foo.begin();
      else
        a[i] = n;
    }
  }
} fr, bk;

void getfrbk() {
  for (int i = 1; i <= n; i++) {
    for (int j = i; j + i <= n; j += i) {
      int l = min(i, LCS(j, j + i)), r = min(i, LCP(j, j + i));
      bk.add(j - l + 1, j + r - i, i);
      fr.add(j + i + i - l, j + r + i - 1, i);
    }
  }
  bk.work();
  fr.work();
}

int tbk[18][maxn];
void tbk_ini() {
  for (int i = 1; i <= n; i++) {
    tbk[0][i] = i + 2 * bk.a[i] - 1;
  }
  for (int i = 1; i <= 17; i++) {
    for (int j = 1; j + (1 << i) - 1 <= n; j++) {
      tbk[i][j] = min(tbk[i - 1][j], tbk[i - 1][j + (1 << (i - 1))]);
    }
  }
}
int tbk_qmin(int l, int r) {
  int ro = 31 - __builtin_clz(r - l + 1);
  return min(tbk[ro][l], tbk[ro][r - (1 << ro) + 1]);
}

bool bad(int l, int r) {
  if (r - l >= 26)
    return false;
  for (int i = l; i <= r; i++)
    if (nxt[i] && nxt[i] <= r)
      return false;
  return true;
}

bool check1(int l, int r) {
  int foo = r - l + 1, bar = r - l + 1;
  for (int i = 2; i * i <= foo; i++) {
    if (foo % i == 0) {
      if (LCP(l, l + bar / i) >= bar - bar / i)
        return true;
      while (foo % i == 0)
        foo /= i;
    }
  }
  if (foo == 1)
    return false;
  if (LCP(l, l + bar / foo) >= bar - bar / foo)
    return true;
  return false;
}

bool check2(int l, int r) {
  if (2 * bk.a[l] <= r - l + 1 || 2 * fr.a[r] <= r - l + 1)
    return true;
  for (int i = 1; i <= min(r - l, SQRT_N); i++) {
    if (LCP(l, r - i + 1) >= i)
      return true;
  }
  for (int i = max(s.rk[l] - SQRT_N, 1); i <= min(s.rk[l] + SQRT_N, n); i++) {
    if (s.sa[i] > l && s.sa[i] <= r) {
      if (LCP(l, s.sa[i]) >= r - s.sa[i] + 1)
        return true;
    }
  }
  return false;
}

bool check3(int l, int r) {
  if (nxt[l] && nxt[l] <= r || pre[r] && pre[r] >= l)
    return true;
  return tbk_qmin(l, r) <= r;
}

bool Med;
int main() {
  // freopen("string.in", "r", stdin);
  // freopen("string.out", "w", stdout);
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d", &n);
  scanf("%s", s0 + 1);
  static int lst[135];
  for (int i = 1; i <= n; i++) {
    if (lst[int(s0[i])]) {
      pre[i] = lst[int(s0[i])];
      nxt[lst[int(s0[i])]] = i;
    }
    lst[int(s0[i])] = i;
  }
  rev.n = s.n = n;
  strcpy(s.s + 1, s0 + 1);
  strcpy(rev.s + 1, s0 + 1);
  reverse(rev.s + 1, rev.s + n + 1);
  s.build();
  rev.build();
  getfrbk();
  tbk_ini();
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    if (bad(l, r))
      puts("-1");
    else if (check1(l, r))
      puts("1");
    else if (check2(l, r))
      puts("2");
    else if (check3(l, r))
      puts("3");
    else
      puts("4");
  }
  return 0;
}