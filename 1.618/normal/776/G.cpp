/*
start thinking:
BULB:
result of thinking: Pure.

#dp
digit, digit1.

start coding:
AC:
*/
#include <bits/stdc++.h>

#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template<class T1, class T2> bool chmin(T1 &x, const T2 &y) {
  return x > y ? (x = y, true) : false;
}
template<class T1, class T2> bool chmax(T1 &x, const T2 &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

ll lim;
int maxdigit;
ll f[25][2][2];

ll dfs(int pos, bool tight, bool maxapp) {
  if (pos < 0)
    return maxapp;
  if (f[pos][tight][maxapp] != -1)
    return f[pos][tight][maxapp];
  auto &ans = f[pos][tight][maxapp];
  ans = 0;
  for (int i = 0; i <= maxdigit; i++) {
    if (tight && i > (lim >> (pos * 4) & 15))
      continue;
    if (maxdigit >= pos * 4 && maxdigit < (pos + 1) * 4
        && !(i & (1 << (maxdigit - pos * 4))))
      continue;
    ans += dfs(pos - 1, tight && i == (lim >> (pos * 4) & 15),
                maxapp || i == maxdigit);
  }
  return ans;
}

ll calc(ll x) {
  if (x <= 0)
    return 0;
  lim = x;
  ll ans = 0;
  for (maxdigit = 0; maxdigit < 16; maxdigit++) {
    memset(f, -1, sizeof(f));
    ans += dfs(14, true, false);
  }
  return ans;
}

void solve() {
  ll l, r;
  scanf("%llx%llx", &l, &r);
  printf("%lld\n", calc(r) - calc(l - 1));
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}