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
constexpr int N = 2e5 + 5;
constexpr int B = 450;
constexpr int W = 9e7;
ll ans;
int n, nxt[N], s[N], buc[W + N];
char t[N];
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  scanf("%s", t + 1);
  n = strlen(t + 1), t[n + 1] = '1';
  for(int i = n; i; i--) nxt[i] = t[i + 1] == '1' ? i : nxt[i + 1];
  for(int i = 1; i <= n; i++) s[i] = s[i - 1] + t[i] - '0';
  for(int d = 1; d < B; d++) {
    buc[W] = 1;
    for(int i = 1; i <= n; i++) {
      int pos = i - d * s[i] + W;
      ans += buc[pos], buc[pos]++;
    }
    for(int i = 1; i <= n; i++) buc[i - d * s[i] + W] = 0;
  }
  for(int d = 1; d < B; d++) {
    int limit = d * B;
    for(int l = 0, r = 0; l < n; l++) {
      while(r <= n && s[r] - s[l] < d) r++;
      if(r > n) break;
      int vl = r - l, vr = nxt[r] - l;
      ans += max(0, vr / d - (max(vl, limit) - 1) / d);
    }
  }
  cout << ans << "\n";
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/9/10
author: Alex_Wei
start coding at 7:10
finish debugging at 7:27
*/