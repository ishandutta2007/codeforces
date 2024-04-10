// Author: wlzhouzhuan
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
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

const int N = 105;
struct bset { // 128  bitset 
  ull x, y;
  bset () { x = y = 0; }
  void set() { x = -1, y = -1; }
  void set(int bit) {
    if (bit <= 63) y |= 1ull << bit;
    else x |= 1ull << (bit - 64);
  }
  void flip(int bit) {
    if (bit <= 63) y ^= 1ull << bit;
    else x ^= 1ull << (bit - 64);
  }
  bool test(int bit) {
    if (bit <= 63) return y >> bit & 1;
    else return x >> (bit - 64) & 1;
  }
  int _Find_last() {
    for (int i = 63; i >= 0; i--) if (x >> i & 1) return 64 + i;
    for (int i = 63; i >= 0; i--) if (y >> i & 1) return i;
    return -1;
  }
  bool operator < (const bset &rhs) const {
    if (x ^ rhs.x) return x < rhs.x;
    else return y < rhs.y;
  }
};
vector<int> adj[N];
int n;

bset f[N];
bool check(vector<int> tmp, bset x) {
  priority_queue<pair<bset, int>> pq;
  for (auto it: tmp) pq.push(make_pair(f[it], it));
  for (int i = n; i >= 0 && !pq.empty(); i--) if (x.test(i)) {
    bset bt = pq.top().fir; int u = pq.top().sec; pq.pop();
    int high_bit = bt._Find_last();
    if (high_bit > i) return 0;
    if (high_bit == i) bt.flip(i), pq.push(make_pair(bt, u));
  }
  return pq.empty();
}
map<pair<int, int>, int> edge, vis;
void down(vector<int> tmp, bset x, int rt) {
  priority_queue<pair<bset, int>> pq;
  for (auto it: tmp) pq.push(make_pair(f[it], it));
  for (int i = n; i >= 0 && !pq.empty(); i--) if (x.test(i)) {
    bset bt = pq.top().fir; int u = pq.top().sec; pq.pop();
    int high_bit = bt._Find_last();
    assert(high_bit <= i);
    if (high_bit == i) bt.flip(i), pq.push(make_pair(bt, u));
    else edge[make_pair(rt, u)] = edge[make_pair(u, rt)] = i;
  }
}
void dfs1(int u, int fa) {
  vector<int> tmp; 
  for (auto v: adj[u]) {
    if (v == fa) continue;
    dfs1(v, u);
    tmp.pb(v);
  }
  for (int i = 0; i <= n; i++) f[u].set(i);
  for (int i = n; i >= 0; i--) {
    f[u].flip(i);
//    printf("f[%d]: ", u);
//    f[u].print();
    if (!check(tmp, f[u])) f[u].flip(i);
  }
  down(tmp, f[u], u);
}
pii maxx;
void dfs2(int u, int fa) {
  for (auto v: adj[u]) {
    if (v == fa || vis[make_pair(u, v)]) continue;
    if (maxx.sec == -1 || edge[maxx] < edge[make_pair(u, v)]) {
      maxx = make_pair(u, v);
    }
    dfs2(v, u);
  }
}
int solve(int u) {
  maxx = make_pair(-1, -1), dfs2(u, 0);
  if (maxx.sec == -1) return u; // 
  vis[maxx] = vis[make_pair(maxx.sec, maxx.fir)] = 1;
  printf("? %d %d\n", maxx.fir, maxx.sec), fflush(stdout);
  int x; scanf("%d", &x);
  return solve(x);
}

int main() {
  n = read();
  for (int i = 1; i < n; i++) {
    int u = read(), v = read();
    adj[u].pb(v), adj[v].pb(u);
  }
  dfs1(1, 0);
//  for (auto it: edge) {
//    printf("%d %d : %d\n", it.fir.fir, it.fir.sec, it.sec);
//  }
  int ans = solve(1);
  printf("! %d\n", ans), fflush(stdout);
  return 0;
}