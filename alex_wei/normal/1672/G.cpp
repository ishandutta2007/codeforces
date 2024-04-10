#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
inline int read() {
  int x = 0;
  char s = getchar();
  while(!isdigit(s)) s = getchar();
  while(isdigit(s)) x = x * 10 + s - '0', s = getchar();
  return x;
}
constexpr int N = 2e3 + 5;
constexpr int M = N * N;
constexpr int mod = 998244353;
int n, m, pw[M], fa[N << 1], sz[N << 1], par[N << 1];
char s[N][N];
int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
int main() {
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  for(int i = pw[0] = 1; i < M; i++) pw[i] = 2 * pw[i - 1] % mod;
  cin >> n >> m;
  for(int i = 1; i <= n; i++) cin >> s[i] + 1;
  if(n % 2 == 0 && m % 2 == 0) {
    int cnt = 0;
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= m; j++)
        cnt += s[i][j] == '?';
    cout << pw[cnt] << "\n";
    exit(0);
  }
  if(m % 2) {
    for(int i = 1; i <= max(n, m); i++)
      for(int j = i; j <= max(n, m); j++)
        swap(s[i][j], s[j][i]);
    swap(n, m);
  }
  if(n % 2 && m % 2 == 0) {
    int parity = -1, cnt = 0;
    for(int j = 1; j <= m; j++) {
      int tot = 0, par = 0;
      for(int i = 1; i <= n; i++)
        if(s[i][j] == '?') tot++;
        else par ^= s[i][j] - '0';
      if(tot) cnt += tot - 1;
      else if(parity == -1) parity = par;
      else if(parity != par) puts("0"), exit(0);
    }
    cout << pw[cnt + (parity == -1)] << "\n";
    exit(0);
  }
  int parity = -1;
  for(int i = 1; i <= n; i++) {
    int find = 0;
    for(int j = 1; j <= m; j++)
      if(s[i][j] == '?') find = 1;
      else par[i] ^= s[i][j] - '0';
    if(!find) {
      if(parity == -1) parity = par[i];
      else if(parity != par[i]) puts("0"), exit(0);
    }
  }
  for(int j = 1; j <= m; j++) {
    int find = 0;
    for(int i = 1; i <= n; i++)
      if(s[i][j] == '?') find = 1;
      else par[j + n] ^= s[i][j] - '0';
    if(!find) {
      if(parity == -1) parity = par[j + n];
      else if(parity != par[j + n]) puts("0"), exit(0);
    }
  }
  for(int i = 1; i <= n + m; i++) sz[i] = 1, fa[i] = i;
  int ans = 0, cnt = 0;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
      if(s[i][j] == '?') {
        int u = find(i), v = find(n + j);
        if(u == v) cnt++;
        else sz[u] += sz[v], par[u] ^= par[v], fa[v] = u;
      }
  if(parity == -1 || parity == 0) {
    bool ok = 1;
    for(int i = 1; i <= n + m; i++) ok &= !par[find(i)];
    if(ok) ans = (ans + pw[cnt]) % mod;
  }
  if(parity == -1 || parity == 1) {
    bool ok = 1;
    for(int i = 1; i <= n + m; i++) ok &= par[find(i)] == (sz[find(i)] & 1);
    if(ok) ans = (ans + pw[cnt]) % mod;
  }
  cout << ans << "\n";
  return 0;
}