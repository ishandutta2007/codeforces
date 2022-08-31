#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

class NotifTree {
  vector<set<int>> tree;
  vector<int> lfend;
  vector<int> rgend;
  vector<vector<int>> locs;
  int vertexc;
  
public:
  NotifTree (int _vertexc) {
    vertexc = 1;
    while (vertexc <= _vertexc) {
      vertexc *= 2;
    }

    tree = vector<set<int>> (2 * vertexc, set<int> ());
    lfend = vector<int> (2 * vertexc);
    rgend = vector<int> (2 * vertexc);
    
    for (int i = vertexc; i < 2 * vertexc; i++) {
      lfend[i] = i - vertexc;
      rgend[i] = i - vertexc;
    }

    for (int i = vertexc - 1; i > 0; i--) {
      lfend[i] = lfend[2 * i];
      rgend[i] = rgend[2 * i + 1];
    }
  }

  void add (int idx, int ql, int qr, int u) {
    ql = max(ql, lfend[u]);
    qr = min(qr, rgend[u]);

    if (ql > qr) return;
    if (ql == lfend[u] && qr == rgend[u]) {
      tree[u].insert(idx);
      locs[idx].push_back(u);
    } else {
      add(idx, ql, qr, 2 * u);
      add(idx, ql, qr, 2 * u + 1);
    }
  }

  int add_notif (int ql, int qr) {
    int idx = locs.size();
    locs.push_back(vector<int> (0));
    add(idx, ql, qr, 1);
    
    return idx;
  }

  void del_notif (int idx) {
    for (int u : locs[idx]) {
      tree[u].erase(idx);
    }
  }

  void get (int target, int cur, vector<int> &ans) {
    if (target < lfend[cur]) return;
    if (rgend[cur] < target) return;

    for (auto idx : tree[cur]) {
      ans.push_back(idx);
    }

    if (cur < vertexc) {
      get(target, 2 * cur, ans);
      get(target, 2 * cur + 1, ans);
    }
  }

  vector<int> get_notifs (int u) {
    vector<int> ans;
    get(u, 1, ans);
    return ans;
  }

  vector<int> get_and_del_notifs (int u) {
    vector<int> ans = get_notifs(u);
    for (int idx : ans) {
      del_notif(idx);
    }
    return ans;
  }
};

typedef long long ll;

const ll INF = 1e18;
const ll VISD = INF + 10;
const int MAX_N = 1 << 18;

struct Seg {
  pair<ll, int> mn = make_pair(INF, MAX_N);
  void recalc(const Seg &lhs_seg, int lhs_len,
    const Seg &rhs_seg, int rhs_len) {
    mn = min(lhs_seg.mn, rhs_seg.mn);
  }
};

struct Lazy {
  ll add;
  ll assign_val; // LLONG_MIN if no assign;
  void init() {
    add = INF;
    assign_val = -1;
  }
  Lazy() { init(); }
  void split(Lazy &lhs_lazy, Lazy &rhs_lazy, int len) {
    lhs_lazy = *this;
    rhs_lazy = *this;
    init();
  }
  void merge(Lazy &oth, int len) {
    if (oth.assign_val != -1) {
      add = 0;
      assign_val = oth.assign_val;
    }
    add = min(add, oth.add);
  }
  void apply_to_seg(Seg &cur, int len) const {
    if (assign_val != -1) {
      if (assign_val == VISD) {
        cur.mn.first = assign_val;
      } else {
        cur.mn.second = assign_val;
      }
    }

    if (cur.mn.first != VISD) {
      cur.mn.first = min(cur.mn.first, add);
    }
  }
};

struct Node { // Following code should not need to be
              // modified. An exception is the assign thing.
  int ver;
  bool is_lazy = false;
  Seg seg;
  Lazy lazy;
  Node *lc = NULL, *rc = NULL;
  void init() {
    if (!lc) {
      lc = new Node{ver};
      rc = new Node{ver};
    }
  }
  Node *upd(
    int L, int R, int l, int r, Lazy &val, int tar_ver) {
    if (ver != tar_ver) {
      Node *rep = new Node(*this);
      rep->ver = tar_ver;
      return rep->upd(L, R, l, r, val, tar_ver);
    }
    if (L >= l && R <= r) {
      val.apply_to_seg(seg, R - L);
      lazy.merge(val, R - L);
      is_lazy = true;
    } else {
      init();
      int M = (L + R) / 2;
      if (is_lazy) {
        Lazy l_val, r_val;
        lazy.split(l_val, r_val, R - L);
        lc = lc->upd(L, M, L, M, l_val, ver);
        rc = rc->upd(M, R, M, R, r_val, ver);
        is_lazy = false;
      }
      Lazy l_val, r_val;
      val.split(l_val, r_val, R - L);
      if (l < M) lc = lc->upd(L, M, l, r, l_val, ver);
      if (M < r) rc = rc->upd(M, R, l, r, r_val, ver);
      seg.recalc(lc->seg, M - L, rc->seg, R - M);
    }
    return this;
  }
  void get(int L, int R, int l, int r, Seg *&lft_res,
    Seg *&tmp, bool last_ver) {
    if (L >= l && R <= r) {
      tmp->recalc(*lft_res, L - l, seg, R - L);
      swap(lft_res, tmp);
    } else {
      init();
      int M = (L + R) / 2;
      if (is_lazy) {
        Lazy l_val, r_val;
        lazy.split(l_val, r_val, R - L);
        lc = lc->upd(L, M, L, M, l_val, ver + last_ver);
        lc->ver = ver;
        rc = rc->upd(M, R, M, R, r_val, ver + last_ver);
        rc->ver = ver;
        is_lazy = false;
      }
      if (l < M)
        lc->get(L, M, l, r, lft_res, tmp, last_ver);
      if (M < r)
        rc->get(M, R, l, r, lft_res, tmp, last_ver);
    }
  }
};

struct SegTree { // indexes start from 0, ranges are
                 // [beg, end)
  vector<Node *> roots; // versions start from 0
  int len;
  SegTree(int _len) : len(_len) {
    roots.push_back(new Node{0});
  }
  int upd(
    int l, int r, Lazy &val, bool new_ver = false) {
    Node *cur_root = roots.back()->upd(
      0, len, l, r, val, roots.size() - !new_ver);
    if (cur_root != roots.back())
      roots.push_back(cur_root);
    return roots.size() - 1;
  }
  Seg get(int l, int r, int ver = -1) {
    if (ver == -1) ver = roots.size() - 1;
    Seg seg1, seg2; // if the default value of Seg isn't an identity,
    // replace those with an identity.
    Seg *pres = &seg1, *ptmp = &seg2;
    roots[ver]->get(
      0, len, l, r, pres, ptmp, roots.size() - 1);
    return *pres;
  }
};

class SegWrap {
  SegTree tree;
public:
  SegWrap () : tree(MAX_N) {
  }

  void set_indices () {
    for (int i = 0; i < MAX_N; i++) {
      Lazy tmp;
      tmp.assign_val = i;
      tree.upd(i, i + 1, tmp);
    }
  }

  bool is_visited (int u) {
    ll val = tree.get(u, u + 1).mn.first;
    return val == VISD;
  }

  void set_visited (int u) {
    Lazy tmp;
    tmp.assign_val = VISD;
    tree.upd(u, u + 1, tmp);
  }

  void set_range (int l, int r, ll x) {
    Lazy tmp;
    tmp.add = x;
    tmp.assign_val = -1;
    tree.upd(l, r + 1, tmp);
  }

  pair<ll, int> get_best (int l, int r) {
    auto ans = tree.get(l, r + 1).mn;
    return ans;
  }
};

vector<pair<int, ll>> adj [MAX_N];
vector<pair<pair<int, int>, ll>> adj_r [MAX_N];
pair<pair<pair<int, int>, int>, ll> type3s [MAX_N];

ll dist [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, q, s;
  cin >> n >> q >> s;

  NotifTree notif (n);
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;

    if (t == 1) {
      int v, u;
      ll w;
      cin >> v >> u >> w;
      adj[v].push_back(make_pair(u, w));
    } else if (t == 2) {
      int v, l, r;
      ll w;
      cin >> v >> l >> r >> w;
      adj_r[v].push_back(make_pair(make_pair(l, r), w));
    } else if (t == 3) {
      int v, l, r;
      ll w;
      cin >> v >> l >> r >> w;
      int idx = notif.add_notif(l, r);
      type3s[idx] = make_pair(make_pair(make_pair(l, r), v), w);
    }
  }

  for (int i = 1; i <= n; i++) {
    dist[i] = INF;
  }
  
  SegWrap wrap;
  wrap.set_indices();
  wrap.set_range(s, s, 0);

  while (true) {
    auto upr = wrap.get_best(1, n);
    
    int cur = upr.second;
    if (upr.first >= INF) break;
    dist[cur] = upr.first;

    vector<int> range_idxs = notif.get_and_del_notifs(cur);
    for (int idx : range_idxs) {
      int u = type3s[idx].first.second;
      ll w = type3s[idx].second;
      wrap.set_range(u, u, dist[cur] + w);
    }

    for (auto pr : adj[cur]) {
      int u = pr.first;
      ll w = pr.second;
      wrap.set_range(u, u, dist[cur] + w);
    }

    for (auto pr : adj_r[cur]) {
      int l = pr.first.first;
      int r = pr.first.second;
      ll w = pr.second;
      wrap.set_range(l, r, dist[cur] + w);
    }

    wrap.set_visited(cur);
  }

  for (int i = 1; i <= n; i++) {
    if (dist[i] == INF) {
      cout << -1 << " ";
    } else {
      cout << dist[i] << " ";
    }
  }
  cout << endl;
}