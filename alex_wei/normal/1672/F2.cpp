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
constexpr int N = 2e5 + 5;
int n, a[N], b[N], cnt[N], deg[N];
vector<int> e[N];
void solve() {
  n = read();
  for(int i = 1; i <= n; i++) cnt[i] = deg[i] = 0, e[i].clear();
  for(int i = 1; i <= n; i++) a[i] = read(), cnt[a[i]]++;
  for(int i = 1; i <= n; i++) b[i] = read();
  int arg = 0;
  for(int i = 1; i <= n; i++) if(cnt[i] > cnt[arg]) arg = i;
  for(int i = 1; i <= n; i++) if(a[i] != arg && b[i] != arg) e[a[i]].push_back(b[i]), deg[b[i]]++;
  queue<int> q;
  for(int i = 1; i <= n; i++) if(!deg[i]) q.push(i);
  while(!q.empty()) {
    int t = q.front(); q.pop();
    for(int it : e[t]) if(!--deg[it]) q.push(it);
  }
  bool ok = 1;
  for(int i = 1; i <= n; i++) ok &= !deg[i];
  if(ok) puts("AC");
  else puts("WA");
}
int main() {
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}