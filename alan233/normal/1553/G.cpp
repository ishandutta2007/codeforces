// Author: wlzhouzhuan
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

int a[N];
int n, q;

int pr[N >> 2], len; bool vis[N];
vector<int> primes[N];
void xxs(int n) {
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) pr[++len] = i;
    for (int j = 1; j <= len && pr[j] * i <= n; j++) {
      vis[pr[j] * i] = 1;
      if (i % pr[j] == 0) break;
    }
  }
  for (int i = 1; i <= len; i++) {
    for (int j = pr[i]; j <= n; j += pr[i])
      primes[j].pb(pr[i]);
  } 
}

struct DSU {
  int f[N];
  void init(int n) { iota(f + 1, f + n + 1, 1); }
  int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
  void merge(int x, int y) { f[find(x)] = find(y); }
} dsu;

set<pii> edge;

int main() {
  xxs(N - 1);
  n = read(), q = read();
  dsu.init(1000000);
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    for (auto v: primes[a[i]])
      dsu.merge(v, a[i])/*, printf("premerge %d %d\n", v, a[i])*/;
  }
//  cerr << "ok!\n";
  for (int i = 1; i <= n; i++) {
    int k1 = a[i] + 1; // "xay  k1" 
    vector<int> tmp;
    tmp.pb(dsu.find(a[i]));
    for (auto v: primes[k1])
      tmp.pb(dsu.find(v));
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    int len = SZ(tmp);
    for (int i1 = 0; i1 < len; i1++)
      for (int i2 = 0; i2 < len; i2++)
        edge.insert({tmp[i1], tmp[i2]});
  }
  while (q--) {
    int x = read(), y = read();
    x = a[x], y = a[y];
    x = dsu.find(x), y = dsu.find(y);
    if (x > y) swap(x, y);
    if (x == y) puts("0");
    else if (edge.find(make_pair(x, y)) != edge.end()) puts("1");
    else puts("2");
  }
  return 0;
}