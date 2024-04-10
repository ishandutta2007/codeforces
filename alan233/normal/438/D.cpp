// zzfy003
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 400005;

#define ls (u << 1)
#define rs (u << 1 | 1)
#define sz(u) (R[u] - L[u] + 1)
int a[N], L[N], R[N];
ll sum[N], mx[N];

void pushup(int u) {
  sum[u] = sum[ls] + sum[rs];
  mx[u] = max(mx[ls], mx[rs]);
}

void build(int u, int l, int r) {
  L[u] = l, R[u] = r;
  if (l == r) {
    sum[u] = mx[u] = a[l];
    return ;
  }
  
  int mid = (l + r) >> 1;
  build(ls, l, mid); build(rs, mid + 1, r);
  pushup(u);
}

void modify_mod(int u, int l, int r, ll p) {
  // log(n)
  if (mx[u] < p) return ;
  if (L[u] == R[u]) {
    sum[u] %= p;
    mx[u] %= p;
    return ;
  }
  
  int mid = (L[u] + R[u]) >> 1;
  if (r <= mid) modify_mod(ls, l, r, p);
  else if (l > mid) modify_mod(rs, l, r, p);
  else {
    modify_mod(ls, l, mid, p);
    modify_mod(rs, mid + 1, r, p);
  }
  pushup(u);
}

void modify(int u, int pos, ll x) {
  if (L[u] == R[u]) {
    sum[u] = mx[u] = x;
    return ;
  }
  
  int mid = (L[u] + R[u]) >> 1;
  if (pos <= mid) modify(ls, pos, x);
  else modify(rs, pos, x);
  pushup(u); 
}

ll query(int u, int l, int r) {
  if (L[u] == l && R[u] == r) {
    return sum[u];
  }
  
  int mid = (L[u] + R[u]) >> 1;
  if (r <= mid) return query(ls, l, r);
  else if (l > mid) return query(rs, l, r);
  else return query(ls, l, mid) + query(rs, mid + 1, r);
}

int n, m;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  build(1, 1, n);
  
  while (m--) {
    int opt; scanf("%d", &opt);
    int l, r; scanf("%d%d", &l, &r);
    if (opt == 1) {
      printf("%lld\n", query(1, l, r));
    }
    else if (opt == 2) {
      int x; scanf("%d", &x);
      modify_mod(1, l, r, x);
    }
    else {
      modify(1, l, r); 
    }
  }
  return 0;
}