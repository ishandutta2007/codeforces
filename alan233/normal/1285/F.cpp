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

const int N = 100005;

int a[N], n, m = 1e5;
ll ans;

vector<int> inz[N];
int mu[N], cnt[N];
void init(int n) {
  mu[1] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j += i)
      inz[j].pb(i);
  for (int i = 1; i <= n; i++)
    for (int j = 2 * i; j <= n; j += i)
      mu[j] -= mu[i];
}

int main() {
  init(N - 5);
  n = read();
  for (int i = 1; i <= n; i++) {
    int x = read();
    a[x] = 1;
    ckmax(ans, x);
  }
  for (int i = 1; i <= m; i++) {
    for (int j = i; j <= m; j += i)
      a[i] |= a[j];
  }
  stack<int> stk;
  for (int i = m; i >= 1; i--) {
    if (!a[i]) continue;
    int now = 0;
    for (auto v: inz[i]) {
      now += mu[v] * cnt[v];
      cnt[v]++;
    }
    while (!stk.empty() && now) {
      int lst = now, u = stk.top(); stk.pop();
      for (auto v: inz[u]) {
        cnt[v]--;
        if (i % v == 0) now -= mu[v];
      }
      if (lst != now) ckmax(ans, 1ll * u * i);
    }
    stk.push(i);
  }
  print(ans, '\n');
  return 0;
}