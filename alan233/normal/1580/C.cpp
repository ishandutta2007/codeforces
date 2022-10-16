// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
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

const int N = 1000005;

int x[N], y[N], las[N];
int cnt[1005][1005], dlt[N], sum;
int n, m, B;

int now;
inline void upd(int i, int d, int delta) {
  int s = x[i] + y[i];
  if ((now - d) % s >= x[i]) sum += delta;
  if (s <= B) {
    cnt[s][d % s] -= delta;
    cnt[s][(d + x[i]) % s] += delta;
  } else {
    for (int j = 0; d + j * s + x[i] <= m; j++) {
      dlt[d + j * s + x[i]] += delta;
      dlt[d + j * s + s] -= delta;
    }
  }
}

int main() {
  n = read(), m = read(), B = sqrt(m);
  rep(i, 1, n) {
    x[i] = read(), y[i] = read();
    ckmin(x[i], m + 1), ckmin(y[i], m + 1);
  }
  rep(i, 1, m) {
    now = i;
    int opt = read(), k = read();
    sum += dlt[i];
    rep(j, 1, B) sum += cnt[j][i % j];
    if (opt == 1) las[k] = i, upd(k, i, 1);
    else upd(k, las[k], -1);
    print(sum, '\n');
  }
  return 0;
}