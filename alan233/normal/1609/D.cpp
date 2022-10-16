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

const int N = 1005;

int n, d, ok;

int f[N], sz[N];
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int main() {
  n = read(), d = read();
  iota(f + 1, f + n + 1, 1);
  rep(i, 1, n) sz[i] = 1;
  while (d--) {
    int u = read(), v = read();
    u = find(u), v = find(v);
    if (u == v) ok++;
    else {
      f[u] = v;
      sz[v] += sz[u];
    }
    vector<int> zz;
    rep(i, 1, n) if (find(i) == i) zz.pb(sz[i]);
    sort(zz.begin(), zz.end(), greater<int> ());
    
//    for (auto v: zz) printf("%d ", v); puts("");
    
    int ans = 0;
    for (int i = 0; i < SZ(zz) && i <= ok; i++)
      ans += zz[i];
    print(ans - 1, '\n');
  } 
  return 0;
}