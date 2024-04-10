#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 2e5 + 5;
const int offset = 1 << 18;

struct Node {
  pii mx1, mx2;
  Node(pii mx1, pii mx2) : mx1(mx1), mx2(mx2) {}
  Node() : mx1({-1, -1}), mx2({-1, -1}) {}
  void update(pii p) {
    if (p >= mx1) {
      mx2 = mx1;
      mx1 = p;
    }
    else if (p > mx2)
      mx2 = p;
  }
};

int N, Q;
int t[MAXN], l[MAXN], r[MAXN], x[MAXN];
int when[MAXN], mini[MAXN];
Node tour[2 * offset];

void load() {
  scanf("%d%d", &N, &Q);
  for (int i = 0; i < Q; i++) {
    scanf("%d%d", t + i, l + i);
    if (!t[i])
      scanf("%d%d", r + i, x + i);
  }
}

Node merge(Node lhs, Node rhs) {
  Node res;
  for (auto it : {lhs, rhs}) 
    for (auto elem : {it.mx1, it.mx2})
      res.update(elem);
  return res;
}

Node query(int x, int lo, int hi, int from, int to) {
  if (lo >= to || hi <= from)
    return Node();
  if (lo >= from && hi <= to)
    return tour[x];
  int mid = (lo + hi) / 2;
  return merge(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
}

void solve() {
  set <int> alive;
  for (int i = 1; i <= N; i++) {
    when[i] = mini[i] = Q;
    alive.insert(i);
  }
  for (int i = 0; i < Q; i++)
    if (!t[i] && !x[i]) 
      while (!alive.empty()) {
        auto it = alive.lower_bound(l[i]);
        if (it == alive.end() || *it > r[i])
          break;
        when[*it] = i;
        alive.erase(it);
      }
  for (int i = 1; i <= N; i++)
    tour[i + offset] = Node({when[i], i}, {-1, -1});
  for (int i = offset - 1; i; i--)
    tour[i] = merge(tour[2 * i], tour[2 * i + 1]);
  for (int i = 0; i < Q; i++) 
    if (!t[i] && x[i]) {
      Node tmp = query(1, 0, offset, l[i], r[i] + 1);
      mini[tmp.mx1.second] = min(mini[tmp.mx1.second], max(tmp.mx2.first, i));
    }
  for (int i = 0; i < Q; i++)
    if (t[i]) {
      if (when[l[i]] < i)
        puts("NO");
      else if (mini[l[i]] < i)
        puts("YES");
      else
        puts("N/A");
    }
}

int main() {
  load();
  solve();
  return 0;
}