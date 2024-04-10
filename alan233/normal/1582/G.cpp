// Author: wlzhouzhuan
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
#pragma GCC optimize("vpt")
#pragma GCC optimize("rename-registers")
#pragma GCC optimize("move-loop-invariants")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("function-sections")
#pragma GCC optimize("data-sections")
#pragma GCC optimize("branch-target-load-optimize")
#pragma GCC optimize("branch-target-load-optimize2")
#pragma GCC optimize("btr-bb-exclusive")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC target("avx", "avx2")
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

const int N = 1000005;

struct node {
  int pos, dlt;
};
vector<node> zz[N];  
int a[N];
char b[N];
int stk[N], top, n;

int minp[N];
void xxs(int n) {
  for (int i = 2; i <= n; i++) {
    for (int j = i; j <= n; j += i)
      if (!minp[j]) minp[j] = i;
  }
}

#define ls (u << 1)
#define rs (u << 1 | 1)
int minn[N << 2];
void update(int u, int l, int r, int ql, int qr, int lim) {
  if (ql <= l && r <= qr) {
    ckmin(minn[u], lim);
    return ;
  }
  int mid = l + r >> 1;
  if (ql <= mid) update(ls, l, mid, ql, qr, lim);
  if (qr > mid) update(rs, mid + 1, r, ql, qr, lim);
}
ll ans = 0;
void dfs(int u, int l, int r, int carry) {
  ckmin(carry, minn[u]);
  if (l == r) {
    ans += carry - l + 1;
    return ;
  }
  int mid = l + r >> 1;
  dfs(ls, l, mid, carry);
  dfs(rs, mid + 1, r, carry);
}

int main() {
  xxs(1e6);
  n = read();
  rep(i, 1, n) a[i] = read();
  scanf("%s", b + 1);
  memset(minn, 0x3f, sizeof(minn));
  rep(i, 0, 1000000) {
    zz[i].pb({0, 0});
  }
  rep(i, 1, n) {
    while (a[i] > 1) {
      int t = minp[a[i]], dlt = 0;
      while (a[i] % t == 0) a[i] /= t, dlt++;
      if (b[i] == '/') dlt = -dlt;
      zz[t].pb({i, dlt}); 
    }
  } 
  rep(i, 0, 1000000) {
    if (SZ(zz[i]) <= 1) continue;
    rep(j, 1, SZ(zz[i]) - 1) zz[i][j].dlt += zz[i][j - 1].dlt;
    zz[i].pb({n + 1, 0});
    stk[top = 0] = SZ(zz[i]) - 1;
    per(j, SZ(zz[i]) - 2, 0) {
      while (top && zz[i][stk[top]].dlt >= zz[i][j].dlt) --top;
//      printf("update %d %d %d\n", zz[i][j].pos + 1, zz[i][j + 1].pos, zz[i][stk[top]].pos - 1);
      update(1, 1, n, zz[i][j].pos + 1, min(n, zz[i][j + 1].pos), zz[i][stk[top]].pos - 1);
      stk[++top] = j;
    }
  }
  dfs(1, 1, n, n);
  print(ans, '\n');
  return 0;
}