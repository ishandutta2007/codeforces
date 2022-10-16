// Author: wlzhouzhuan
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
#define poly vector<int>
#define SZ(x) (int(x.size()))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 300005;
const int mod = 998244853;
const int base = 137;

int pw[N];

char s[N];
int where[N << 1], go[N];
int pre[N], n;

int who[N]; //  
int dep[N], f[N][19], hsh[N][19];

bool cmp(int u, int v) { // u < v ? 
//  printf("ini u = %d, v = %d\n", u, v);
  for (int i = 18; i >= 0; i--) {
    if (dep[u] >= (1 << i) && dep[v] >= (1 << i)) {
      if (hsh[u][i] == hsh[v][i])
        u = f[u][i], v = f[v][i];
    }    
  }
//  printf("u = %d, v = %d\n", u, v);
//  printf("dep = (%d, %d)\n", dep[u], dep[v]);
  if (!dep[v]) return 1;
  return s[u] < s[v];
}

int main() {
//  printf("%d %d\n", '(', ')');
  pw[0] = 1; rep(i, 1, N - 1) pw[i] = 1ll * pw[i - 1] * base % mod;
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + (s[i] == '(' ? 1 : -1);
  }
  for (int i = n + 1; i >= 1; i--) { // go[i]  [i, go[i])  
    go[i] = i;
    if (s[i] == '(' && where[pre[i - 1] + N]) go[i] = where[pre[i - 1] + N];
    where[pre[i - 1] + N] = i;
  }
//  for (int i = 1; i <= n + 1; i++) printf("go[%d] = %d\n", i, go[i]); system("pause");
  who[n + 1] = n + 1;
  for (int i = n; i >= 1; i--) {
    f[i][0] = who[i + 1];
    hsh[i][0] = (s[i] == '(' ? 1 : 0);
    dep[i] = dep[who[i + 1]] + 1;
    for (int j = 1; j < 19; j++) {
      f[i][j] = f[f[i][j - 1]][j - 1];
      hsh[i][j] = (1ll * hsh[i][j - 1] * pw[1 << j - 1] + hsh[f[i][j - 1]][j - 1]) % mod;
    }
    who[i] = (go[i] != i && cmp(who[go[i]], i)) ? who[go[i]] : i;
//    printf("who[%d] = %d\n", i, who[i]);
  }
  int pos = who[1];
  while (pos != n + 1) {
//    printf("pos = %d\n", pos);
//    system("pause");
    putchar(s[pos]);
    pos = f[pos][0];
  }
  puts("");
  return 0;
}