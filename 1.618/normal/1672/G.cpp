/*
start thinking:
BULB:
result of thinking:

, flip, ,
((r-1)*(c-1)).

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

#define maxn 2005
const int mod = 998244353;
int r, c, pow2[maxn * maxn];
char s[maxn][maxn];

vector<int> adj[maxn << 1];
int w[maxn << 1];
bool vis[maxn << 1];
int siz, sumdeg, sumw;

void dfs(int u) {
  siz++, sumdeg += adj[u].size(), sumw ^= w[u];
  vis[u] = true;
  for (auto v : adj[u]) {
    if (!vis[v])
      dfs(v);
  }
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  pow2[0] = 1;
  for (int i = 1; i <= 4000000; i++)
    pow2[i] = (pow2[i - 1] << 1) % mod;
  scanf("%d%d", &r, &c);
  for (int i = 1; i <= r; i++) {
    scanf("%s", s[i] + 1);
  }
  if (r % 2 == 0 && c % 2 == 0) {
    int ans = 1;
    for (int i = 1; i <= r; i++) {
      for (int j = 1; j <= c; j++) {
        if (s[i][j] == '?')
          (ans *= 2) %= mod;
      }
    }
    printf("%d\n", ans);
    return 0;
  }
  if (r & 1) {
    for (int i = 1; i <= max(r, c); i++) {
      for (int j = 1; j < i; j++)
        swap(s[i][j], s[j][i]);
    }
    swap(r, c);
  }
  if (r % 2 == 0) {
    int rsum = -1, ans = 1;
    for (int i = 1; i <= r; i++) {
      int foo = count(s[i] + 1, s[i] + c + 1, '?');
      if (!foo) {
        int bar = count(s[i] + 1, s[i] + c + 1, '1');
        if (rsum == -1) {
          rsum = bar & 1;
        } else if (rsum != (bar & 1)) {
          puts("0");
          return 0;
        }
      } else {
        ans = (ll)ans * pow2[foo - 1] % mod;
      }
    }
    if (rsum == -1)
      (ans *= 2) %= mod;
    printf("%d\n", ans);
    return 0;
  }
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      if (s[i][j] == '?') {
        adj[i].push_back(j + r);
        adj[j + r].push_back(i);
      } else {
        w[i] ^= s[i][j] - '0';
        w[j + r] ^= s[i][j] - '0';
      }
    }
  }
  int cnt0 = 1, cnt1 = 1;
  for (int i = 1; i <= r + c; i++) {
    if (!vis[i]) {
      siz = sumdeg = sumw = 0;
      dfs(i);
      sumdeg /= 2;
      if (sumw & 1) {
        cnt0 = 0;
      } else {
        cnt0 = (ll)cnt0 * pow2[sumdeg - (siz - 1)] % mod;
      }
      if ((siz - sumw) & 1) {
        cnt1 = 0;
      } else {
        cnt1 = (ll)cnt1 * pow2[sumdeg - (siz - 1)] % mod;
      }
    }
  }
  printf("%d\n", (cnt0 + cnt1) % mod);
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}