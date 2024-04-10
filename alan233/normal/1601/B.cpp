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

const int N = 300005;

set<int> s;
int dis[N], pre[N];
int a[N], b[N], n;

int main() {
  n = read();
  rep(i, 1, n) a[i] = read();
  rep(i, 1, n) b[i] = read();
  rep(i, 0, n - 1) s.insert(i);
  queue<int> q;
  q.push(n);
  memset(dis, -1, sizeof(dis));
  dis[n] = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    int where = min(n, u + b[u]);
    int L = max(where - a[where], 0), R = where;
    auto it = s.lower_bound(L);
    while (it != s.end()) {
      auto go = next(it);
      dis[*it] = dis[u] + 1;
      pre[*it] = u;
      q.push(*it);
      s.erase(it);
      it = go;
    }
  }
  if (dis[0] == -1) {
    puts("-1");
    return 0;
  }
  printf("%d\n", dis[0]);
  stack<int> stk;
  int _ = 0;
  while (_ != n) {
    stk.push(_);
    _ = pre[_];
  }
  while (!stk.empty()) {
    printf("%d ", stk.top());
    stk.pop();
  }
  return 0;
}