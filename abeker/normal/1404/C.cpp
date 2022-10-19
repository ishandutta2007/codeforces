#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 3e5 + 5;
const int offset = 1 << 19;

class Node {
  vector <pii> inc;
public:
  Node(vector <pii> inc) : inc(inc) {}
  Node() : inc(vector <pii> ()) {}
  vector <pii> getInc() const {
    return inc;
  }
  int getNext(int val) const {
    int pos = lower_bound(inc.begin(), inc.end(), pii(val, -1)) - inc.begin();
    return val + (pos < inc.size() ? inc[pos].second : 0);
  }
};

int N, Q;
int a[MAXN];
Node tour[2 * offset];

void load() {
  scanf("%d%d", &N, &Q);
  for (int i = 1; i <= N; i++) {
    scanf("%d", a + i);
    a[i] = i - a[i];
  }
}

Node merge(Node lhs, Node rhs) {
  vector <pii> L = lhs.getInc();
  vector <pii> R = rhs.getInc();
  vector <int> imp;
  for (auto it : L)
    imp.push_back(it.first);
  int ptr = 0;
  for (auto it : R) {
    while (ptr < L.size() && L[ptr].first + L[ptr].second <= it.first)
      ptr++;
    if (ptr < L.size())
      imp.push_back(max(it.first - L[ptr].second, ptr ? L[ptr - 1].first : -1));
  }
  imp.push_back(N);
  sort(imp.begin(), imp.end());
  imp.resize(unique(imp.begin(), imp.end()) - imp.begin());
  vector <pii> res;
  for (auto it : imp)
    res.push_back({it, rhs.getNext(lhs.getNext(it)) - it});
  return Node(res);
}

void query(int x, int lo, int hi, int from, int to, int &curr) {
  if (lo >= to || hi <= from)
    return;
  if (lo >= from && hi <= to) {
    curr = tour[x].getNext(curr);
    return;
  }
  int mid = (lo + hi) / 2;
  query(2 * x, lo, mid, from, to, curr);
  query(2 * x + 1, mid, hi, from, to, curr);
}

void solve() {
  for (int i = 1; i <= N; i++)
    tour[i + offset] = a[i] < 0 ? Node({{N, 0}}) : Node({{a[i] - 1, 0}, {N, 1}});
  for (int i = offset - 1; i >= 0; i--)
    tour[i] = merge(tour[2 * i], tour[2 * i + 1]);
  while (Q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    int ans = 0;
    query(1, 0, offset, x + 1, N - y + 1, ans);
    printf("%d\n", ans);
  }
}

int main() {
  load();
  solve();
  return 0;
}