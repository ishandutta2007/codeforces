#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;
const ll INF = 1e18;

struct Node {
  ll mini, maks;
  Node(ll mini, ll maks) : mini(mini), maks(maks) {}
  Node() : mini(INF), maks(-INF) {}
};

class Tournament {
  int offset;
  vector <Node> tour;
public:
  Node merge(Node lhs, Node rhs) const {
    return Node(min(lhs.mini, rhs.mini), max(lhs.maks, rhs.maks));
  }
  Tournament(ll *arr, int n) {
    for (offset = 1; offset <= n; offset *= 2);
    tour.resize(2 * offset);
    for (int i = 1; i <= n; i++)
      tour[i + offset] = {arr[i], arr[i]};
    for (int i = offset - 1; i; i--)
      tour[i] = merge(tour[2 * i], tour[2 * i + 1]);
  }
  Node query(int x, int lo, int hi, int from, int to) const {
    if (lo >= to || hi <= from)
      return Node();
    if (lo >= from && hi <= to)
      return tour[x];
    int mid = (lo + hi) / 2;
    return merge(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
  }
  Node query(int from, int to) const {
    return query(1, 0, offset, from, to);
  }
};

int N, Q;
int a[MAXN], b[MAXN];
ll pref[MAXN];

void load() {
  scanf("%d%d", &N, &Q);
  for (int i = 1; i <= N; i++)
    scanf("%d", a + i);
  for (int i = 1; i <= N; i++)
    scanf("%d", b + i);
}

void solve() {
  for (int i = 1; i <= N; i++)
    pref[i] = pref[i - 1] + b[i] - a[i];
  Tournament T(pref, N);
  while (Q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    Node tmp = T.query(l, r);
    printf("%lld\n", pref[l - 1] == pref[r] && tmp.mini >= pref[l - 1] ? tmp.maks - pref[l - 1] : -1);
  }
}

int main() {
  load();
  solve();
  return 0;
}