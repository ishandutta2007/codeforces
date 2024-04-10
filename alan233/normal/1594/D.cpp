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

const int N = 500005;

bool vis[N];
int f[N], sz[N];
int n, m;

int find(int x) {
  return f[x] == x ? x : f[x] = find(f[x]);
}
void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return ;
  f[x] = y, sz[y] += sz[x];
}

void solve() {
  scanf("%d%d", &n, &m);
  rep(i, 1, n + n) f[i] = i, sz[i] = i <= n, vis[i] = 0;
  while (m--) {
    int x, y; char relation[55];
    scanf("%d%d%s", &x, &y, relation);
    if (relation[0] == 'c') {
      merge(x, y);
      merge(x + n, y + n);
    } else {
      merge(x, y + n);
      merge(y, x + n);
    }
  }
  int ans = 0;
  // rep(i, 1, n + n) {
  //   printf("find(%d) = %d\n", i, find(i));
  // }
  rep(i, 1, n) {
    if (vis[find(i)]) continue;
    vis[find(i)] = vis[find(i + n)] = 1; 
    if (find(i) == find(i + n)) {
      ans = -1;
      break;
    }
    ans += max(sz[find(i)], sz[find(i + n)]);
  }
  print(ans, '\n');
}

int main() {
  int T = read();
  while (T--) {
    solve();
  }
  return 0;
}