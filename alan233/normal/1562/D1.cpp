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

const int N = 300005;
char a[N];
int sum[N], n, q;

void solve() {
  map<int, set<int>> mp;
  scanf("%d%d%s", &n, &q, a + 1);
  for (int i = 1; i <= n; i++) {
    a[i] = a[i] == '+' ? 1 : -1;
    if (i & 1) sum[i] = sum[i - 1] + a[i];
    else sum[i] = sum[i - 1] - a[i];
    mp[sum[i] + sum[i - 1]].insert(i);
  } 
  while (q--) {
    int l = read(), r = read();
    if (sum[r] - sum[l - 1] == 0) {
      puts("0"); continue;
    }
    int qwq = sum[l - 1] + sum[r];
    auto it = mp[qwq].lower_bound(l);
    if (it != mp[qwq].end() && *it <= r) puts("1");
    else puts("2");
  }
}

int main() {
  int T = read();
  while (T--) {
    solve();
  }
  return 0;
}