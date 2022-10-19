#include <bits/stdc++.h>

using namespace std;

typedef double ld;
typedef complex<ld> comp;

const int M = 300300;
const ld pi = acosl(-1.0);

struct Lin {
  comp a, b;

  Lin() {
    a = comp(1, 0);
    b = comp(0, 0);
  }

  Lin(comp a, comp b) : a(a), b(b) { }

  comp operator()(comp x) {
    return a * x + b;
  }
};

Lin apply(Lin a, Lin b) {
  Lin res;
  res.a = a.a * b.a;
  res.b = a.a * b.b + a.b;
  return res;
};

Lin t[4 * M];

void push(int v) {
  t[2 * v] = apply(t[v], t[2 * v]);
  t[2 * v + 1] = apply(t[v], t[2 * v + 1]);
  t[v] = Lin();
}

void upd(int v, int l, int r, int le, int re, Lin f) {
  if (l + 1 != r)
    push(v);
  if (l == le && r == re) {
    t[v] = apply(f, t[v]);
    return;
  }

  int m = (l + r) / 2;
  if (le < m)
    upd(2 * v, l, m, le, min(re, m), f);
  if (m < re)
    upd(2 * v + 1, m, r, max(m, le), re, f);
}

Lin get(int v, int l, int r, int at) {
  if (l + 1 == r)
    return t[v];
  
  int m = (l + r) / 2;
  Lin ans;
  if (at < m)
    ans = get(2 * v, l, m, at);
  else
    ans = get(2 * v + 1, m, r, at);

  return apply(t[v], ans);
}

int n, m;

comp get(int x) {
  Lin f = get(1, 0, n + 1, x);
  return f(comp(x, 0));
}

void read() {
  cin >> n >> m;
}

void kill() {
  for (int i = 0; i < m; ++i) {
    int type;
    cin >> type;
    if (type == 1) {
      int id;
      int len;
      cin >> id >> len;
      comp x = get(id - 1);
      comp y = get(id);
      
      ld plen = abs(y - x);
      comp v = (y - x) * (len / plen);

      Lin f(comp(1, 0), v);
      upd(1, 0, n + 1, id, n + 1, f);
    }

    if (type == 2) {
      int id;
      int ang;
      cin >> id >> ang;

      comp rot = exp(comp(0.0, ang / 360.0 * 2 * pi * -1.0)); 
      comp x = get(id - 1);

      Lin f(rot, x * (comp(1, 0) - rot));
      upd(1, 0, n + 1, id, n + 1, f);
    }

    comp x = get(n);

    cout << real(x) << " " << imag(x) << "\n";
  }

}

int main() {
  cout.precision(6);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}