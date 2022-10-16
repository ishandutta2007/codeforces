#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define se second
#define TIME 1e3 * clock() / CLOCKS_PER_SEC
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using ull = unsigned long long;
inline int read() {
  int x = 0;
  char s = getchar();
  while(!isdigit(s)) s = getchar();
  while(isdigit(s)) x = x * 10 + s - '0', s = getchar();
  return x;
}
inline void print(int x) {
  if(x < 0) return putchar('-'), print(-x);
  if(x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
bool Mbe;
constexpr int N = 2e5 + 5;
constexpr int V = 1 << 20;
int n;
char s[N];
ll d[N], ans[N];
vector<int> e[N];
bool vis[N];
int R, sz[N], mx[N];
void findroot(int id, int ff, int tot) {
  sz[id] = 1, mx[id] = 0;
  for(int it : e[id]) {
    if(vis[it] || it == ff) continue;
    findroot(it, id, tot);
    sz[id] += sz[it];
    mx[id] = max(mx[id], sz[it]);
  }
  mx[id] = max(mx[id], tot - sz[id]);
  if(mx[id] < mx[R]) R = id;
}
vector<pii> info[N];
void findval(int id, int ff, int msk, int anc) {
  d[id] = 0;
  msk ^= 1 << s[id] - 'a';
  info[anc].push_back({msk, id});
  for(int it : e[id]) {
    if(vis[it] || it == ff) continue;
    findval(it, id, msk, anc);
  }
}
void flush(int id, int ff) {
  for(int it : e[id]) {
    if(vis[it] || it == ff) continue;
    flush(it, id);
    d[id] += d[it];
  }
  if(!ff) d[id] /= 2;
  ans[id] += d[id];
}
int buc[V];
void calc(vector<pii> &arr, int coef, int msk) {
  for(pii it : arr) buc[it.first] += coef;
  for(pii it : arr) {
    int cnt = buc[msk ^ it.first];
    for(int i = 0; i < 20; i++) cnt += buc[msk ^ it.first ^ (1 << i)];
    d[it.second] += cnt;
  }
  for(pii it : arr) buc[it.first] = 0;
}
void divide(int id) {
  vis[id] = 1, d[id] = 0;
  int msk = 1 << s[id] - 'a';
  info[0].clear();
  info[0].push_back({msk, id});
  for(int it : e[id]) {
    if(vis[it]) continue;
    findval(it, id, msk, it);
    calc(info[it], -1, msk);
    for(pii v : info[it]) info[0].push_back(v);
    info[it].clear();
  }
  calc(info[0], 1, msk);
  flush(id, 0);
  for(int it : e[id]) {
    if(vis[it]) continue;
    R = 0;
    findroot(it, id, sz[it]);
    divide(R);
  }
}
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  cin >> n;
  for(int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  cin >> s + 1;
  mx[0] = N;
  findroot(1, 0, n);
  divide(R);
  for(int i = 1; i <= n; i++) cout << ans[i] + 1 << " ";
  cout << "\n";
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/9/14
author: Alex_Wei
start coding at 12:38
finish debugging at 13:02
*/