#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

const ll INF = 1e18 + 200;

class Segtree {
  int n;
  vector<ll> tree;
  vector<int> lend;
  vector<int> rend;

  void update (int u) {
    if (u == 0) {
      return;
    }

    tree[u] = max(tree[2 * u], tree[2 * u + 1]);
    update(u / 2);
  }
  
public:
  Segtree (int _n) {
    n = 1;
    while (n < _n) {
      n *= 2;
    }

    tree = vector<ll> (2 * n);
    lend = vector<int> (2 * n);
    rend = vector<int> (2 * n);

    for (int i = n; i < 2 * n; i++) {
      lend[i] = i - n;
      rend[i] = i - n;
    }

    for (int i = n - 1; i > 0; i--) {
      lend[i] = lend[2 * i];
      rend[i] = rend[2 * i + 1];
    }
  }

  void set (int pos, ll val) {
    tree[n + pos] = val;
    update((n + pos) / 2);
  }

  ll query (int ql, int qr, int u = 1) {
    ql = max(ql, lend[u]);
    qr = min(qr, rend[u]);

    if (ql > qr) {
      return -INF;
    }

    if (ql == lend[u] && qr == rend[u]) {
      return tree[u];
    }

    return max(query(ql, qr, 2 * u),
               query(ql, qr, 2 * u + 1));
  }
};

const int MAX_N = 3e5 + 5;

int height [MAX_N];
ll beauty [MAX_N];

struct Range {
  int l, r;
  ll maxdp;
  int mn;
};

ll value (const Range &p) {
  return beauty[p.mn] + p.maxdp;
}

bool operator< (const Range &p, const Range &q) {
  if (value(p) != value(q)) {
    return value(p) < value(q);
  }
  return p.mn < q.mn;
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> height[i];
  }

  for (int i = 1; i <= n; i++) {
    cin >> beauty[i];
  }

  Segtree dp (n + 5);
  
  vector<Range> stk;
  set<Range> rangeset;
  
  for (int i = 1; i <= n; i++) {
    while (!stk.empty() && height[stk.back().mn] > height[i]) {
      rangeset.erase(stk.back());
      stk.pop_back();
    }

    Range cur;
    cur.l = stk.empty() ? 1 : stk.back().r + 1;
    cur.r = i;
    cur.maxdp = dp.query(cur.l - 1, cur.r - 1);
    cur.mn = i;

    stk.push_back(cur);
    rangeset.insert(cur);

    ll cur_dp = value(*rangeset.rbegin());
    dp.set(i, cur_dp);
  }

  cout << dp.query(n, n) << '\n';
}