// Author: wlzhouzhuan
#ifdef xay
#define D(...) fprintf(stderr, "[D]" __VA_ARGS__)
#else
#define D(...) ((void)0)
#endif
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
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 55;
char a[N];
int cnt[10], n;

bool yes[10005];
void xxs(int n) {
  yes[1] = 1;
  for (int i = 2; i <= n; i++) {
    bool ok = 1;
    for (int j = 2; j * j <= i; j++) if (i % j == 0) ok = 0;
    if (ok) yes[i] = 0;
    else yes[i] = 1;
  }
}

int ans; vector<int> ansc;

void dfs(vector<int> qwq) {
  if (!SZ(qwq)) return ;
  int x = 0;
  for (auto v: qwq) x = 10 * x + v;
  if (yes[x]) {
    if (SZ(qwq) < ans) ans = SZ(qwq), ansc = qwq;
  }
  for (int i = 0; i < SZ(qwq); i++) {
    vector<int> qaq;
    for (int j = 0; j < SZ(qwq); j++) if (i != j) qaq.pb(qwq[j]);
    dfs(qaq);
  }
}
void solve() {
  mset(cnt, 0);
  scanf("%d%s", &n, a + 1);
  vector<int> bb;
  for (int i = 1; i <= n; i++) {
    a[i] -= '0';
    if (a[i] != 2 && a[i] != 3 && a[i] != 5 && a[i] != 7) {
      D("type 1\n");
      printf("1\n%d\n", a[i]);
      return ;
    }
  }
  for (int i = 1; i <= n; i++) {
    cnt[a[i]]++;
    if (cnt[a[i]] == 2) {
      D("type 2\n");
      printf("2\n%d%d\n", a[i], a[i]);
      return ;
    }
    bb.pb(a[i]);
  }
  ans = 1000;
  dfs(bb);
  D("type 3\n");
  printf("%d\n", ans);
  for (auto v: ansc) printf("%d", v);
  puts("");
}

int main() {
  xxs(1e4);
  int T = read();
  while (T--) {
    solve();
  }
  return 0;
}