#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

const int N = 2e5 + 5;

typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long

typedef class Node {
  public:
    Node *lc, *rc, *fa;
    ordered_set ls, rs;

    ll cnt;

    void remove(int, int);
    void insert(int, int);
} Node;

Node pool[N << 1];
Node* _top = pool;

int n, q;
int a[N], b[N];
Node* leaf[N];

ll ans;

#define sz(tr) ((signed ll) tr.size())

void Node::remove(int dir, int x) {
  ans -= min(cnt, sz(ls) * sz(rs) - cnt);
  if (dir == 0) { // left
    cnt -= rs.order_of_key(x);
    ls.erase(x);
  } else {      // right
    cnt -= ls.size() - ls.order_of_key(x);
    rs.erase(x);
  }
  ans += min(cnt, sz(ls) * sz(rs) - cnt);
//  cerr << cnt << " " << ls.size() * rs.size() << '\n';
}
void Node::insert(int dir, int x) {
  ans -= min(cnt, sz(ls) * sz(rs) - cnt);
  if (dir == 0) {
    cnt += rs.order_of_key(x);
    ls.insert(x);
  } else {
    cnt += ls.size() - ls.order_of_key(x);
    rs.insert(x);
  }
  ans += min(cnt, sz(ls) * sz(rs) - cnt);
//  cerr << cnt << " " << ls.size() * rs.size() << '\n';
}

void build(Node*& p, int l, int r) {
  p = _top++;
  if (l == r) {
    leaf[l] = p;
    return;
  }
  int mid = l;
  for (int i = l + 1; i < r; i++) {
    if (b[i] < b[mid]) {
      mid = i;
    }
  }
  build(p->lc, l, mid);
  build(p->rc, mid + 1, r);
  p->lc->fa = p->rc->fa = p;
  for (int i = mid + 1; i <= r; i++) {
    p->rs.insert(a[i]);
  }
  for (int i = l; i <= mid; i++) {
    p->ls.insert(a[i]);
    p->cnt += p->rs.order_of_key(a[i]);
  }
  ans += min(p->cnt, sz(p->ls) * sz(p->rs) - p->cnt);
//  cerr << p->cnt << " " << p->ls.size() * p->rs.size() << '\n';
}

void update_remove(int idx) {
  int x = a[idx];
  for (Node* p = leaf[idx], *q; (q = p->fa); p = q) {
    q->remove(p == q->rc, x);
  }
}
void update_insert(int idx) {
  int x = a[idx];
  for (Node* p = leaf[idx], *q; (q = p->fa); p = q) {
    q->insert(p == q->rc, x);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 1; i < n; i++) {
    scanf("%d", b + i);
  }
  Node* rt;
  build(rt, 1, n);
  int x, y;
  scanf("%d", &q);
  while (q--) {
    scanf("%d%d", &x, &y);
    update_remove(x);
    update_remove(y);
    swap(a[x], a[y]);
    update_insert(x);
    update_insert(y);
    printf("%lld\n", ans);
  }
  return 0;
}