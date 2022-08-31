#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void failure () {
  cout << -1 << endl;
  exit(0);
}

const int INF = 1e9 + 5;
const int AVIS = INF + 1;

struct Seg {
  pair<int, int> mn; // value, last
  int mn_un;

  Seg (pair<int, int> _mn = make_pair(INF, -1), int _mn_un = INF) : mn(_mn), mn_un(_mn_un) {
  }
};

Seg merge (const Seg &l, const Seg &r) {
  return Seg(min(l.mn, r.mn), min(l.mn_un, r.mn_un));
}

void apply (Seg &seg, pair<int, int> lazy) {
  seg.mn = min(seg.mn, lazy);
  if (seg.mn_un != AVIS) {
    seg.mn_un = min(seg.mn_un, lazy.first);
  }
}

struct Segtree {
  int n;
  vector<Seg> tree;
  vector<pair<int, int>> lazy;
  vector<int> lfend;
  vector<int> rgend;

  void propagate (int u) {
    apply(tree[u], lazy[u]);
    if (u < n) {
      lazy[2 * u] = min(lazy[u], lazy[2 * u]);
      lazy[2 * u + 1] = min(lazy[u], lazy[2 * u + 1]);
    }
    lazy[u] = make_pair(INF, -1);
  }
  
public:
  Segtree (int _n) {
    n = 1;
    while (n < _n) {
      n *= 2;
    }

    tree = vector<Seg> (2 * n, Seg());
    lazy = vector<pair<int, int>> (2 * n, make_pair(INF, -1));
    lfend = vector<int> (2 * n);
    rgend = vector<int> (2 * n);

    for (int i = n; i < 2 * n; i++) {
      lfend[i] = i - n;
      rgend[i] = i - n;
    }

    for (int i = n - 1; i > 0; i--) {
      lfend[i] = lfend[2 * i];
      rgend[i] = rgend[2 * i + 1];
    }
  }

  void update (int ql, int qr, pair<int, int> x, int u = 1) {
    propagate(u);

    ql = max(ql, lfend[u]);
    qr = min(qr, rgend[u]);

    if (ql > qr) return;
    if (ql == lfend[u] && qr == rgend[u]) {
      lazy[u] = x;
      propagate(u);
      return;
    }

    update(ql, qr, x, 2 * u);
    update(ql, qr, x, 2 * u + 1);

    tree[u] = merge(tree[2 * u], tree[2 * u + 1]);
  }

  // <position, seg value>
  pair<int, int> pop (int u = 1) {
    propagate(u);

    if (tree[u].mn_un == AVIS) {
      return make_pair(-1, INF);
    }

    if (u >= n) {
      tree[u].mn_un = AVIS;
      return make_pair(u - n, tree[u].mn.first);
    }

    pair<int, int> ans;
    if (tree[2 * u].mn_un != AVIS) {
      ans = pop(2 * u);
    } else {
      ans = pop(2 * u + 1);
    }

    tree[u] = merge(tree[2 * u], tree[2 * u + 1]);
    return ans;
  }

  Seg get (int pos, int u = 1) {
    propagate(u);

    if (u >= n) {
      return tree[u];
    }

    if (pos <= rgend[2 * u]) {
      return get(pos, 2 * u);
    } else {
      return get(pos, 2 * u + 1);
    }
  }
};

const int MAX_N = 3e5 + 5;
const int START = -2;

int up [MAX_N], dn [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> up[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> dn[i];
  }

  reverse(up, up + n);
  reverse(dn, dn + n);

  Segtree tree (n);
  tree.update(0, 0, make_pair(0, -2));

  while (true) {
    auto pr = tree.pop();
    int pos = pr.first;
    int jumps = pr.second;

    if (pos == -1 || jumps == INF) {
      failure();
    }

    int dpos = max(0, pos - dn[pos]);
    if (dpos + up[dpos] >= n) {
      vector<int> ans (1, n);
      int cur = pos;
      while (cur > 0) {
        ans.push_back(cur);
        cur = tree.get(cur).mn.second;
      }

      reverse(ans.begin(), ans.end());
      cout << (int) ans.size() << '\n';
      for (int u : ans) {
        cout << n - u << " ";
      }
      cout << '\n';
      return 0;
    }

    int l = max(0, dpos);
    int r = min(n - 1, dpos + up[dpos]);
    tree.update(l, r, make_pair(1 + jumps, pos));
  }
}