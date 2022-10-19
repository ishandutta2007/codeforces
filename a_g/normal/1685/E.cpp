#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int p[N], pi[N], s[N], good[N][2];
int mn[4*N], argmin[4*N], lazy[4*N];
int n;
int low, high;

int val(int x) {
  if (x < n+1) return -1;
  if (x > n+1) return 1;
  return 0;
}

void combine(int v) {
  int k = (mn[2*v+1] < mn[2*v] ? 2*v+1 : 2*v);
  mn[v] = mn[k];
  argmin[v] = argmin[k];
}

void init(int v, int tl, int tr) {
  if (tl == tr) {
    mn[v] = s[tl];
    argmin[v] = tl;
    return;
  }
  int tm = (tl+tr)/2;
  init(2*v, tl, tm);
  init(2*v+1, tm+1, tr);
  combine(v);
}

void push(int v, int tl, int tr) {
  if (lazy[v]) {
    if (tl != tr) {
      lazy[2*v] += lazy[v];
      lazy[2*v+1] += lazy[v];
    }
    mn[v] += lazy[v];
    lazy[v] = 0;
  }
}

void add(int v, int tl, int tr, int l, int r, int x) {
  if (tl >= l && tr <= r) {
    lazy[v] += x;
  }

  push(v, tl, tr);

  if (r < tl || tr < l) {
    return;
  }

  if (tl >= l && tr <= r) {
    return;
  }

  int tm = (tl+tr)/2;
  add(2*v, tl, tm, l, r, x);
  add(2*v+1, tm+1, tr, l, r, x);
  combine(v);
}

int query(int v, int tl, int tr, int x) {
  if (tl == tr) {
    return lazy[v] + mn[v];
  }
  int tm = (tl+tr)/2;
  return lazy[v] +  (x <= tm ? query(2*v, tl, tm, x) : query(2*v+1, tm+1, tr, x));
}

void debug(int v, int tl, int tr) {
  cout << v << " " << tl << " " << tr << endl;
  cout << mn[v] << " " << argmin[v] << " " << lazy[v] << endl << endl;
  if (tl != tr) {
    int tm = (tl+tr)/2;
    debug(2*v, tl, tm);
    debug(2*v+1, tm+1, tr);
  }
}

int pr(int x, bool h) {
  if (h) return (x == n+1 ? 2*n+1 : x-1);
  else return (x == 1 ? n+1 : x-1);
}

int nx(int x, bool h) {
  if (h) return (x == 2*n+1 ? n+1 : x+1);
  else return (x == n+1 ? 1 : x+1);
}

void upd(int x, bool h) {
  int y = pr(x, h);
  int z = nx(x, h);
  int k = (pi[y]>pi[x])^(pi[x]>pi[z])^(pi[z]>pi[y]);
  if (!h) {
    low += k-good[x][h];
  }
  else {
    high += k-good[x][h];
  }
  good[x][h] = k;
}

void upd2(int x) {
  if (x <= n+1) {
    upd(x, 0);
    upd(pr(x, 0), 0);
    upd(nx(x, 0), 0);
  }
  if (x >= n+1) {
    upd(x, 1);
    upd(pr(x, 1), 1);
    upd(nx(x, 1), 1);
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int q;
  cin >> n >> q;
  for (int i = 1; i <= 2*n+1; i++) {
    cin >> p[i];
    pi[p[i]] = i;
    s[i] = s[i-1] + val(p[i]);
  }

  init(1, 0, 2*n);
  for (int i = 1; i <= 2*n+1; i++) {
    if (i <= n+1) upd(i, 0);
    if (i >= n+1) upd(i, 1);
  }

  while (q--) {
    int u, v;
    cin >> u >> v;
    if (u > v) swap(u, v);
    int d = val(p[v])-val(p[u]);
    swap(p[u], p[v]);
    swap(pi[p[u]], pi[p[v]]);
    upd2(p[u]);
    upd2(p[v]);
    add(1, 0, 2*n, u, v-1, d);
    int ans = -1;
    if (query(1, 0, 2*n, pi[n+1]) > mn[1]) {
      ans = argmin[1];
    }
    else if (low != n+1) {
      ans = (pi[n+1] == 2*n+1 ? 0 : pi[n+1]);
    }
    else if (high != n+1) {
      ans = pi[n+1]-1;
    }
    cout << ans << '\n';
  }
}