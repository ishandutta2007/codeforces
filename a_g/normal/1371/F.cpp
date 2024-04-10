#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;

struct desc {
  int le, re, lis, lds, llis, llds, rlis, rlds, len;
};

desc a[4*N];
bool f[4*N];
string s;

desc emp = {};

desc merge(desc left, desc right) {
  if (left.len == 0) return right;
  if (right.len == 0) return left;

  int le = left.le;
  int re = right.re;

  int lis = max(left.lis, right.lis);
  if (left.re <= right.le) {
    lis = max(lis, left.rlis+right.llis);
  }
  int lds = max(left.lds, right.lds);
  if (left.re >= right.le) {
    lds = max(lds, left.rlds+right.llds);
  }

  int llis = left.llis;
  if (left.llis == left.len && left.re <= right.le) {
    llis += right.llis;
  }
  int llds = left.llds;
  if (left.llds == left.len && left.re >= right.le) {
    llds += right.llds;
  }

  int rlis = right.rlis;
  if (right.rlis == right.len && left.re <= right.le) {
    rlis += left.rlis;
  }
  int rlds = right.rlds;
  if (right.rlds == right.len && left.re >= right.le) {
    rlds += left.rlds;
  }

  int len = left.len+right.len;

  return desc{le, re, lis, lds, llis, llds, rlis, rlds,  len};
}

desc flip(desc d) {
  return desc{
    1-d.le,
    1-d.re,
    d.lds,
    d.lis,
    d.llds,
    d.llis,
    d.rlds,
    d.rlis,
    d.len
  };
}

void combine(int v){
  a[v] = merge(a[2*v], a[2*v+1]);
}

void init(int v, int tl, int tr) {
  if (tl != tr) {
    int tm = (tl+tr)/2;
    init(2*v, tl, tm);
    init(2*v+1, tm+1, tr);
    combine(v);
  }
  else {
    int z = (s[tl] == '>' ? 1 : 0);
    a[v] = desc{z, z, 1, 1, 1, 1, 1, 1, 1};
  }
}

desc query(int v, int tl, int tr, int l, int r) {

  if (tl >= l && tr <= r) {
    f[v] = !f[v];
  }

  if (f[v]) {
    a[v] = flip(a[v]);
    if (tl != tr) {
      for (int i = 0; i < 2; i++) {
        f[2*v+i]=!f[2*v+1];
      }
    }
    f[v] = 0;
  }

  if (r < tl || tr < l) {
    return emp;
  }

  if (tl >= l && tr <= r) {
    return a[v];
  }

  int tm = (tl+tr)/2;
  desc ans = merge(query(2*v, tl, tm, l, r), query(2*v+1, tm+1, tr, l, r));

  combine(v);
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q >> s;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  init(1, 0, n-1);

  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << (query(1, 0, n-1, l-1, r-1).lds) << '\n';
  }
}