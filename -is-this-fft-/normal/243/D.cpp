#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
struct Seg {
  int mn = 0;
  void recalc(const Seg &lhs_seg, int lhs_len,
    const Seg &rhs_seg, int rhs_len) {
    mn = min(lhs_seg.mn, rhs_seg.mn);
  }
};

struct Lazy {
  int assign_val; // LLONG_MIN if no assign;
  void init() {
    assign_val = INT_MIN;
  }
  Lazy() { init(); }
  void split(Lazy &lhs_lazy, Lazy &rhs_lazy, int len) {
    lhs_lazy = *this;
    rhs_lazy = *this;
    init();
  }
  void merge(Lazy &oth, int len) {
    assign_val = max(assign_val, oth.assign_val);
  }
  void apply_to_seg(Seg &cur, int len) const {
    cur.mn = max(cur.mn, assign_val);
  }
};

struct Node { // Following code should not need to be
              // modified
  bool is_lazy = false;
  Seg seg;
  Lazy lazy;
  Node *lc = NULL, *rc = NULL;
  void init() {
    if (!lc) {
      lc = new Node{};
      rc = new Node{};
    }
  }
  Node *upd(
    int L, int R, int l, int r, Lazy &val) {
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
        lc = lc->upd(L, M, L, M, l_val);
        rc = rc->upd(M, R, M, R, r_val);
        is_lazy = false;
      }
      Lazy l_val, r_val;
      val.split(l_val, r_val, R - L);
      if (l < M) lc = lc->upd(L, M, l, r, l_val);
      if (M < r) rc = rc->upd(M, R, l, r, r_val);
      seg.recalc(lc->seg, M - L, rc->seg, R - M);
    }
    return this;
  }
  void get(int L, int R, int l, int r, Seg *&lft_res,
    Seg *&tmp) {
    if (L >= l && R <= r) {
      tmp->recalc(*lft_res, L - l, seg, R - L);
      swap(lft_res, tmp);
    } else {
      init();
      int M = (L + R) / 2;
      if (is_lazy) {
        Lazy l_val, r_val;
        lazy.split(l_val, r_val, R - L);
        lc = lc->upd(L, M, L, M, l_val);
        rc = rc->upd(M, R, M, R, r_val);
        is_lazy = false;
      }
      if (l < M)
        lc->get(L, M, l, r, lft_res, tmp);
      if (M < r)
        rc->get(M, R, l, r, lft_res, tmp);
    }
  }
};

struct SegTree { // indices start from 0, ranges are
                 // [beg, end)
  vector<Node *> roots; // versions start from 0
  int len;
  SegTree(int _len) : len(_len) {
    roots.push_back(new Node{0});
  }
  int upd(
    int l, int r, Lazy &val, bool new_ver = false) {
    Node *cur_root = roots.back()->upd(
      0, len, l, r, val);
    if (cur_root != roots.back())
      roots.push_back(cur_root);
    return roots.size() - 1;
  }
  Seg get(int l, int r, int ver = -1) {
    if (ver == -1) ver = roots.size() - 1;
    Seg seg1, seg2;
    seg1.mn = 1e9 + 5;
    seg2.mn = 1e9 + 5;
    Seg *pres = &seg1, *ptmp = &seg2;
    roots[ver]->get(
      0, len, l, r, pres, ptmp);
    return *pres;
  }
};

typedef pair<int, int> point;
#define x first
#define y second

point operator+ (point p, point q) {
  return make_pair(p.x + q.x, p.x - q.x);
}

point operator- (point p) {
  return make_pair(-p.x, -p.y);
}

point operator- (point p, point q) {
  return p + (-q);
}

ll dot (point p, point q) {
  return p.x * q.x + p.y * q.y;
}

ll sqnorm (point p) {
  return dot(p, p);
}

point perp (point p) {
  return make_pair(p.y, -p.x);
}

const int MAX_N = 1e3 + 6;

int arr [MAX_N][MAX_N];

struct cube {
  int h;
  ll l, r, t;
};

bool operator< (cube p, cube q) {
  return p.t < q.t;
}

int main () {
  ios::sync_with_stdio(false);
  
  int length;
  point dir;
  cin >> length >> dir.x >> dir.y;

  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length; j++) {
      cin >> arr[i][j];
    }
  }

  map<ll, int> compr;
  vector<cube> cubes;
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length; j++) {
      cube cur;
      
      cur.t = dot(dir, {i, j});
      cur.l = dot(perp(dir), {i, j});
      cur.r = dot(perp(dir), {i, j});
      for (int dx = 0; dx <= 1; dx++) {
        for (int dy = 0; dy <= 1; dy++) {
          cur.t = min(cur.t, dot(dir, {i + dx, j + dy}));
          cur.l = min(cur.l, dot(perp(dir), {i + dx, j + dy}));
          cur.r = max(cur.r, dot(perp(dir), {i + dx, j + dy}));
        }
      }
      cur.h = arr[i][j];

      compr[cur.l] = 0;
      compr[cur.r] = 0;
      cubes.push_back(cur);
    }
  }

  int idx = 0;
  for (auto it = compr.begin(); it != compr.end(); it++) {
    it->second = idx;
    idx++;
  }

  sort(cubes.begin(), cubes.end());

  ll ans = 0;
  SegTree stree (1 << 20);
  for (cube event : cubes) {
    ans += max(0, event.h - stree.get(compr[event.l], compr[event.r]).mn);

    Lazy tmp;
    tmp.assign_val = event.h;
    stree.upd(compr[event.l], compr[event.r], tmp);
  }

  cout << ans << '\n';
}