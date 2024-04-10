#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+2;
int lazy[4*N], sum[4*N];
int z[N];

struct query {
  int l, r;
};

void push(int v) {
  if (lazy[v] != -1) {
    lazy[2*v+1] = lazy[v];
    lazy[2*v+2] = lazy[v];
    lazy[v] = -1;
  }
}

void combine(int v) {
  sum[v] = sum[2*v+1]+sum[2*v+2];
}

void init(string& s, int v, int tl, int tr) {
  if (tl == tr) {
    lazy[v] = s[tl]-'0';
    sum[v] = lazy[v];
    return;
  }
  lazy[v] = -1;
  int tm = (tl+tr)/2;
  init(s, 2*v+1, tl, tm);
  init(s, 2*v+2, tm+1, tr);
  combine(v);
}

int ask(int v, int tl, int tr, int l, int r) {
  //cout << v << " " << tl << " " << tr << " " << l << " " << r << endl;
  if (l > tr || r < tl) return 0;
  if (tl == tr) {
    sum[v] = lazy[v];
    return sum[v];
  }
  if (lazy[v] != -1) {
    sum[v] = (tr-tl+1)*lazy[v];
  }
  if (l <= tl && tr <= r) return sum[v];
  push(v);
  int tm = (tl+tr)/2;
  return ask(2*v+1, tl, tm, l, r)+ask(2*v+2, tm+1, tr, l, r);
}

void apply(int v, int tl, int tr, int l, int r, int k) {
  //cout << v << " " << tl << " " << tr << " " << l << " " << r << " " << k << endl;
  if (l > tr || r < tl) {
    if (lazy[v] != -1) sum[v] = (tr-tl+1)*lazy[v];
    return;
  }
  if (l <= tl && tr <= r) {
    lazy[v] = k;
    sum[v] = (tr-tl+1)*k;
    return;
  }
  push(v);
  int tm = (tl+tr)/2;
  apply(2*v+1, tl, tm, l, r, k);
  apply(2*v+2, tm+1, tr, l, r, k);
  combine(v);
}

void finalize(int v, int tl, int tr) {
  if (tl == tr) {
    z[tl] = lazy[v];
    return;
  }
  push(v);
  int tm = (tl+tr)/2;
  finalize(2*v+1, tl, tm);
  finalize(2*v+2, tm+1, tr);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, q;
    cin >> n >> q;
    string s, f;
    cin >> s >> f;
    init(f, 0, 0, n-1);
    vector<query> queries(q);
    for (int i = q-1; i >= 0; i--) {
      cin >> queries[i].l >> queries[i].r;
    }
    bool win = 1;
    for (query qr: queries) {
      int k = ask(0, 0, n-1, qr.l-1, qr.r-1);
      if (2*k == (qr.r-qr.l+1)) {
        win = 0;
        break;
      }
      if (2*k > (qr.r-qr.l+1)) {
        apply(0, 0, n-1, qr.l-1, qr.r-1, 1);
      }
      else {
        apply(0, 0, n-1, qr.l-1, qr.r-1, 0);
      }
    }
    finalize(0, 0, n-1);
    for (int i = 0; i < n; i++) {
      if (s[i]-'0' != z[i]) {
        win = 0;
        break;
      }
    }
    cout << (win ? "YES" : "NO") << '\n';
  }
}