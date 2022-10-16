#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define se second
#define TIME 1e3 * clock() / CLOCKS_PER_SEC
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
inline int read() {
  int x = 0, sgn = 0;
  char s = getchar();
  while(!isdigit(s)) sgn |= s == '-', s = getchar();
  while(isdigit(s)) x = x * 10 + s - '0', s = getchar();
  return sgn ? -x : x;
}
inline void print(int x) {
  if(x < 0) return putchar('-'), print(-x);
  if(x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
bool Mbe;
constexpr int N = 1e6 + 5;
int n, vis[N], stc[N], top;
vector<int> e[N], ans;
void dfs(int id) {
  if(!ans.empty()) return;
  if(vis[id]) {
    ans.push_back(id);
    while(stc[top] != id) ans.push_back(stc[top--]);
    return;
  }
  vis[id] = 1, stc[++top] = id;
  for(int it : e[id]) dfs(it);
}
void solve() {
  n = read();
  for(int i = 1; i <= n; i++) e[i].clear(), vis[i] = 0;
  for(int i = 1; i <= n; i++) {
    int a = read();
    e[i].push_back(i - a);
  }
  ans.clear(), top = 0, dfs(1);
  print(ans.size()), putchar('\n');
  for(int it : ans) print(it), putchar(' ');
  putchar('\n');
}
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  // ios::sync_with_stdio(0);
  int T;
  cin >> T;
  while(T--) solve();
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/9/10
author: Alex_Wei
start coding at 7:30
finish debugging at 7:38
*/