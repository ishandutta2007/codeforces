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
constexpr int N = 1e3 + 5;
int n, x[N], y[N];
bool chk(int *v, int bt) {
  for(int i = 1; i <= n; i++) if((v[i] & 1) ^ bt) return 0;
  return 1;
}
void add(int *v) {for(int i = 1; i <= n; i++) v[i]++;}
void cut(int *v) {for(int i = 1; i <= n; i++) v[i] /= 2;}
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
  while(1) {
    if(chk(x, 1)) add(x);
    if(chk(y, 1)) add(y);
    if(chk(x, 0) && chk(y, 0)) cut(x), cut(y);
    else break;
  }
  bool same = 1;
  for(int i = 2; i <= n; i++) same &= (x[i] + y[i] & 1) == (x[i - 1] + y[i - 1] & 1);
  vector<int> ans;
  if(same) {for(int i = 1; i <= n; i++) if(x[i] & 1) ans.push_back(i);}
  else for(int i = 1; i <= n; i++) if(x[i] + y[i] & 1) ans.push_back(i);
  cout << ans.size() << "\n";
  for(int it : ans) cout << it << " ";
  cout << "\n";
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/9/9
author: Alex_Wei
start coding at 20:40
finish debugging at 20:59
*/