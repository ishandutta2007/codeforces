// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
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

const int N = 262144 * 4;

char a[N], ch[N];
int real_id[N], k, n;

#define ls (u << 1)
#define rs (u << 1 | 1)
int L[N], R[N];
int minn[N], mnum[N], lazy[N];
void pushup(int u) {
  minn[u] = min(minn[ls], minn[rs]);
  mnum[u] = 0;
  if (minn[ls] == minn[u]) mnum[u] += mnum[ls];
  if (minn[rs] == minn[u]) mnum[u] += mnum[rs];
}
void pushtag(int u, int lzy) {
  minn[u] += lzy, lazy[u] += lzy;
}
void pushdown(int u) {
  if (lazy[u]) {
    pushtag(ls, lazy[u]);
    pushtag(rs, lazy[u]);
    lazy[u] = 0;
  }
}
void build(int u, int l, int r) {
//  printf("u = %d, l = %d, r = %d, c = %c\n", u, l, r, ch[u]);
  L[u] = l, R[u] = r;
  if (l == r) {
    mnum[u] = 1;
    return ;
  }
  if (ch[u] == '1') {
    pushtag(ls, 1);
  }
  if (ch[u] == '0') {
    pushtag(rs, 1);
  }
  pushdown(u);
  int mid = l + r >> 1;
  build(ls, l, mid);
  build(rs, mid + 1, r);
  pushup(u);
}
void update(int u, int l, int r, char c) {
  pushdown(u);
  if (ch[u] == '1') {
    pushtag(ls, -1);
  }
  if (ch[u] == '0') {
    pushtag(rs, -1);
  }
  ch[u] = c;
  if (ch[u] == '1') {
    pushtag(ls, 1);
  }
  if (ch[u] == '0') {
    pushtag(rs, 1);
  }
}
void print(int u, int l, int r) {
  printf("[node %d, l = %d, r = %d]: %d %d\n", u, l, r, minn[u], mnum[u]);
  if (l == r) return ;
  pushdown(u);
  int mid = l + r >> 1;
  print(ls, l, mid), print(rs, mid + 1, r);
}
int main() {
  k = read(), n = 1 << k;
  scanf("%s", a + 1);
  for (int bit = 0, now = n - 1, qid = 0; bit < k; bit++) {
    int len = 1 << bit, low = now - len + 1;
    for (int j = low; j <= now; j++) {
      real_id[j] = ++qid;
      ch[qid] = a[j];
    }
    now -= len;
  }
//  for (int i = 1; i < n; i++) printf("real_id[%d] = %d\n", i, real_id[i]);
  build(1, 1, n);
//  print(1, 1, n);
  int q = read();
  while (q--) {
    int p; char c;
    scanf("%d %c", &p, &c);
    p = real_id[p];
    stack<int> stk;
    int _ = p;
    while (_ > 0) stk.push(_), _ /= 2;
    while (!stk.empty()) pushdown(stk.top()), stk.pop();
    update(p, L[p], R[p], c);
    while (p > 0) {
      pushup(p), p >>= 1;
    }
    if (minn[1] == 0) print(mnum[1], '\n');
    else puts("0");
  }
  return 0;
}