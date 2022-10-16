#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define TIME 1e3 * clock() / CLOCKS_PER_SEC
using ll = long long;
using uint = unsigned int;
using ld = long double;
// using lll = __int128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
inline ll read() {
  ll x = 0, sgn = 0;
  char s = getchar();
  while(!isdigit(s)) sgn |= s == '-', s = getchar();
  while(isdigit(s)) x = x * 10 + s - '0', s = getchar();
  return sgn ? -x : x;
}
inline void print(ll x) {
  if(x < 0) return putchar('-'), print(-x);
  if(x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
bool Mbe;
ll f[6][10005];
int query(vector<ll> t) {
  cout << t.size() << " ";
  for(ll it : t) cout << it << " ";
  cout << endl;
  return read();
}
void solve(int j, ll l, ll r) {
  vector<ll> t;
  ll c = min(l, 10000ll), cur = l + f[j - 1][c] - 1;
  for(int p = 1; p <= c; p++) {
    t.push_back(++cur);
    cur += f[j - 1][min(cur + 1, 10000ll)];
  }
  int res = query(t);
  if(res == -1) return;
  if(res == 0) solve(j - 1, l, t.front() - 1);
  else if(res == t.size()) solve(j - 1, t.back() + 1, r);
  else solve(j - 1, t[res - 1] + 1, t[res] - 1);
}
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  // #ifdef ALEX_WEI
  //   FILE* IN = freopen("1.in", "r", stdin);
  //   FILE* OUT = freopen("1.out", "w", stdout);
  // #endif
  for(int i = 1; i <= 10000; i++) f[1][i] = i;
  for(int j = 2; j <= 5; j++)
    for(int i = 1; i <= 10000; i++) {
      ll cur = i + f[j - 1][i] - 1;
      for(int p = 1; p <= i; p++) {
        if(cur >= 9999) {
          cur += (i - p + 1) * (1 + f[j - 1][10000]);
          break;
        }
        cur++, cur += f[j - 1][cur + 1];
      }
      f[j][i] = cur - i + 1;
    }
  solve(5, 1, 10004205361450474);
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/10/6
author: Alex_Wei
start coding at 11:50
finish debugging at 13:31
*/