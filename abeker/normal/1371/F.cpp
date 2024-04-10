#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;
const int offset = 1 << 19;

struct Node {
  int len;
  int first, last;
  int pref1, pref2, suff1, suff2;
  int rightLeft, leftRight;
  int lazy;
  void flip() {
    first ^= 1;
    last ^= 1;
    swap(rightLeft, leftRight);
  }
  int maximum() {
    return max({pref1, suff1, rightLeft});
  }
};

int N, Q;
char conv[MAXN];
Node t[2 * offset];

void push(int x) {
  if (x < offset) {
    t[2 * x].lazy ^= 1;
    t[2 * x + 1].lazy ^= 1;
  }
}

void prop(int x) {
  if (t[x].lazy) {
    t[x].flip();
    t[x].lazy = 0;
    push(x);
  }
}

Node merge(Node l, Node r) {
  if (!l.len)
    return r;
  if (!r.len)
    return l;
  Node res;
  res.len = l.len + r.len;
  res.first = l.first;
  res.last = r.last;
  bool diff = l.last != r.first;
  res.pref1 = l.pref2 || diff ? l.pref1 : l.len + r.pref1;
  res.pref2 = l.pref2 ? (l.pref1 + l.pref2 < l.len || diff ? l.pref2 : l.pref2 + r.pref1) : (diff ? r.pref1 : r.pref2);
  res.suff1 = r.suff2 || diff ? r.suff1 : r.len + l.suff1;
  res.suff2 = r.suff2 ? (r.suff1 + r.suff2 < r.len || diff ? r.suff2 : r.suff2 + l.suff1) : (diff ? l.suff1 : l.suff2);
  res.rightLeft = max({l.rightLeft, r.rightLeft, diff ? (l.last ? l.suff1 + r.pref1 : 0) : (l.last ? (r.pref2 ? l.suff1 + r.pref1 + r.pref2 : 0) : (l.suff2 ? l.suff1 + l.suff2 + r.pref1 : 0))});
  res.leftRight = max({l.leftRight, r.leftRight, diff ? (l.last ? 0 : l.suff1 + r.pref1) : (l.last ? (l.suff2 ? l.suff1 + l.suff2 + r.pref1 : 0) : (r.pref2 ? l.suff1 + r.pref1 + r.pref2 : 0))});
  res.lazy = 0;
  return res;
}

void update(int x, int lo, int hi, int from, int to) {
  prop(x);
  if (lo >= to || hi <= from)
    return;
  if (lo >= from && hi <= to) {
    t[x].flip();
    push(x);
    return;
  }
  int mid = (lo + hi) / 2;
  update(2 * x, lo, mid, from, to);
  update(2 * x + 1, mid, hi, from, to);
  t[x] = merge(t[2 * x], t[2 * x + 1]);
}

Node query(int x, int lo, int hi, int from, int to) {
  prop(x);
  if (lo >= to || hi <= from)
    return t[0];
  if (lo >= from && hi <= to)
    return t[x];
  int mid = (lo + hi) / 2;
  return merge(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
}

void load() {
  scanf("%d%d%s", &N, &Q, conv + 1);
}

void solve() {
  for (int i = 1; i <= N; i++)
    t[i + offset] = {1, conv[i] == '>', conv[i] == '>', 1, 0, 1, 0, 0, 0, 0};
  for (int i = offset - 1; i; i--)
    t[i] = merge(t[2 * i], t[2 * i + 1]);
  while (Q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    update(1, 0, offset, l, r + 1);
    printf("%d\n", query(1, 0, offset, l, r + 1).maximum());
  }
}

int main() {
  load();
  solve();
  return 0;
}