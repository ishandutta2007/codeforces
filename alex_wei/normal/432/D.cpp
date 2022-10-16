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
constexpr int N = 1e5 + 5;
char s[N];
int n, z[N], d[N], nxt[N];
vector<int> ans;
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  ios::sync_with_stdio(0);
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for(int i = 2, l = 0, r = 0; i <= n; i++) {
    z[i] = r < i ? 0 : min(r - i + 1, z[i - l + 1]);
    while(s[1 + z[i]] == s[i + z[i]]) z[i]++;
    if(i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    d[z[i]]++;
  }
  for(int i = n; i; i--) d[i] += d[i + 1];
  for(int i = 2, j = 0; i <= n; i++) {
    while(j && s[j + 1] != s[i]) j = nxt[j];
    nxt[i] = j += s[j + 1] == s[i];
  }
  int p = n;
  while(p) ans.push_back(p), p = nxt[p];
  reverse(ans.begin(), ans.end());
  cout << ans.size() << "\n";
  for(int it : ans) cout << it << " " << d[it] + 1 << "\n";
  return 0;
}
/*
2022/9/8
author: Alex_Wei
start coding at 7:12
finish debugging at 7:16
*/