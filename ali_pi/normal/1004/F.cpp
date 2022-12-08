#include <bits/stdc++.h>

#define F first
#define S second
#define Pii pair<int, int>

using namespace std;

const int N = 101000;

int n, m, X, a[N], ty;

struct Node {
  Pii l[22], r[22];
  int lm, rm, x, L, R;
  long long ans;
  void in(int pos, int val) {
    l[rm = 1] = r[lm = 1] = make_pair(L = R = pos, val);
    ans = val < X; x = val; 
  }
  Node operator + (const Node &b) const {
    Node c; c.ans = ans + b.ans; c.x = x | b.x;
    c.L = L, c.R = b.R;
    memcpy(c.l, l, sizeof(Pii) * (lm + 1)); 
    memcpy(c.r, b.r, sizeof(Pii) * (b.rm + 1));
    c.lm = lm, c.rm = b.rm;
    for(int i = 1; i <= b.lm; i++)
      if((b.l[i].S | x) > c.l[c.lm].S)
	c.l[++c.lm] = b.l[i], c.l[c.lm].S |= x;
    for(int i = 1; i <= rm; i++)
      if((r[i].S | b.x) > c.r[c.rm].S)
	c.r[++c.rm] = r[i], c.r[c.rm].S |= b.x;
    for(int i = rm, j = 0; i; i--) {
      while(j < b.lm && (r[i].S | b.l[j + 1].S) < X) j++;
      c.ans += (i == rm ? r[i].F - L + 1 : r[i].F - r[i + 1].F) *
		(j == b.lm ? b.R - b.L + 1 : b.l[j + 1].F - b.L);
    }
    return c;
  }
}t[N * 4], P, pre;

void Build(int o, int l, int r) {
  if(l == r) { t[o].in(l, a[l]); return; }
  int mid = l + r >> 1;
  Build(o << 1, l, mid);
  Build(o << 1 | 1, mid + 1, r);
  t[o] = t[o << 1] + t[o << 1 | 1];
}

void Modify(int o, int x, int y) {
  if(t[o].L == t[o].R) {
      t[o].in(x, y);
      return; }
  int mid = t[o].L + t[o].R >> 1;
  if(x <= mid) Modify(o << 1, x, y);
  else Modify(o << 1 | 1, x, y);
  t[o] = t[o << 1] + t[o << 1 | 1];
}

void Query(int o, int l, int r) {
  if(l <= t[o].L && t[o].R <= r) {
    !P.lm ? P = t[o] : P = P + t[o];
    return;
  }
  int mid = t[o].L + t[o].R >> 1;
  if(l <= mid) 
     Query(o << 1, l, r);
  if(mid < r) 
     Query(o << 1 | 1, l, r);
}

int main(void) {
  cin>>n>>m>>X;
  for(int i = 1; i <= n; i++) {
    cin>>a[i];
  }
  Build(1, 1, n);
  for(int i = 1, x, y; i <= m; i++) {
    cin>>ty>>x>>y;
    if(ty == 1) 
       Modify(1, x, y);
    else {
      P = pre;
      Query(1, x, y);
      cout<<1LL * (y - x + 1) * (y - x + 2) / 2 - P.ans<<endl;
    }
  }
}