// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#pragma GCC target("avx", "avx2")
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

const int N = 500005;

char a[N], b[N];
int cnt[30], ban[30], n;
int tmp[30], occurs[30], len, lenb;

void solve() {
  mset(cnt, 0), mset(ban, 0);
  scanf("%s", a + 1), n = strlen(a + 1);
  len = 0;
  for (int i = n; i >= 1; i--) {
    a[i] -= 'a';
    if (!cnt[a[i]]) tmp[++len] = a[i];
    cnt[a[i]]++;
  }
  reverse(tmp + 1, tmp + len + 1);
  int sum = 0;
  rep(i, 1, len) {
    if (cnt[tmp[i]] % i) {
      puts("-1");
      return ;
    }
    occurs[tmp[i]] = cnt[tmp[i]] / i;
    sum += occurs[tmp[i]];
  }
  lenb = 0;
  rep(i, 1, len) {
    rep(j, 1, sum) {
      if (ban[a[j]]) continue;
      b[++lenb] = a[j];
      if (lenb > n || b[lenb] != a[lenb]) {
        puts("-1");
        return ;
      }
    }
    ban[tmp[i]] = 1;
  }
  if (lenb != n) {
    puts("-1");
    return ;
  }
  rep(j, 1, sum) printf("%c", a[j] + 'a');
  printf(" ");
  rep(j, 1, len) printf("%c", tmp[j] + 'a');
  puts("");
}

int main() {
  int T = read();
  while (T--) {
    solve();
  }
  return 0;
}