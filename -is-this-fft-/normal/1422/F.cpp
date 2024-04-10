#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7; // change if needed

struct Modint {
  ll val;
  
  Modint (ll _val = 0)
    : val(_val % MOD) {}

  Modint operator+ (Modint other) const {
    return Modint(val + other.val);
  }

  void operator+= (Modint other) {
    val += other.val;
    val %= MOD;
  }

  Modint operator- () const {
    return Modint(MOD - val);
  }

  Modint operator- (Modint other) const {
    return Modint(val + MOD - other.val);
  }

  void operator-= (Modint other) {
    val += MOD - other.val;
    val %= MOD;
  }

  Modint operator* (Modint other) const {
    return Modint(val * other.val);
  }

  void operator*= (Modint other) {
    val *= other.val;
    val %= MOD;
  }

  bool operator== (Modint other) const {
    return val == other.val;
  }

  bool operator!= (Modint other) const {
    return val != other.val;
  }
};

Modint exp (Modint a, int k) {
  if (k == 0) {
    return Modint(1);
  } else if (k % 2 == 0) {
    Modint half = exp(a, k / 2);
    return half * half;
  } else {
    return a * exp(a, k - 1);
  }
}

Modint inv (Modint a) {
  return exp(a, MOD - 2);
}

ostream& operator<< (ostream& out, Modint p) {
  out << p.val;
  return out;
}

const int MAX_N = 1 << 17;
const int BIG = 450;
const int SPC = 87;
const int MAX_PW = 20;

int sieve [BIG];
vector<int> smallp;

int arr [MAX_N];
vector<pair<int, int>> factors [MAX_N];
int red [MAX_N];

int factor (int x, vector<pair<int, int>> &ans) {
  for (int i = 0; i < (int) smallp.size(); i++) {
    int p = smallp[i];
    if (x % p == 0) {
      int cnt = 0;
      while (x % p == 0) {
        x /= p;
        cnt++;
      }
      ans.push_back(make_pair(i, cnt));
    }
  }
  return x;
}

namespace small {
  vector<int> tree [2 * MAX_N];
  int lfend [2 * MAX_N];
  int rgend [2 * MAX_N];

  vector<int> maxv (const vector<int> &p, const vector<int> &q) {
    vector<int> ans (SPC, 0);
    for (int i = 0; i < SPC; i++) {
      ans[i] = max(p[i], q[i]);
    }
    return ans;
  }

  void maxw (vector<int> &p, const vector<int> &q) {
    for (int i = 0; i < SPC; i++) {
      p[i] = max(p[i], q[i]);
    }
  }
  
  Modint pws [SPC][MAX_PW];

  void query (int ql, int qr, int u, vector<int> &v) {
    ql = max(ql, lfend[u]);
    qr = min(qr, rgend[u]);

    if (ql > qr) return;
    if (ql == lfend[u] && qr == rgend[u]) {
      maxw(v, tree[u]);
      return;
    }
    query(ql, qr, 2 * u, v);
    query(ql, qr, 2 * u + 1, v);    
  }

  Modint get (int l, int r) {
    vector<int> v (SPC, 0);
    query(l, r, 1, v);

    Modint ans (1);
    for (int i = 0; i < SPC; i++) {
      ans *= pws[i][v[i]];
    }
    return ans;
  }
  
  void build (int n) {
    for (int i = 0; i < SPC; i++) {
      pws[i][0] = Modint(1);
      for (int j = 1; j < MAX_PW; j++) {
        pws[i][j] = pws[i][j - 1] * Modint(smallp[i]);
      }
    }

    for (int i = 0; i < MAX_N; i++) {
      tree[MAX_N + i] = vector<int> (SPC, 0);
      for (auto pr : factors[i]) {
        tree[MAX_N + i][pr.first] = pr.second;
      }
      lfend[MAX_N + i] = i;
      rgend[MAX_N + i] = i;
    }

    for (int i = MAX_N - 1; i >= 1; i--) {
      tree[i] = maxv(tree[2 * i], tree[2 * i + 1]);
      lfend[i] = lfend[2 * i];
      rgend[i] = rgend[2 * i + 1];
    }
  }
}

namespace big {
  struct Seg {
    Modint prod = Modint(1);
    void recalc(const Seg &lhs_seg, int lhs_len,
                const Seg &rhs_seg, int rhs_len) {
      prod = lhs_seg.prod * rhs_seg.prod;
    }
  };

  struct Lazy {
    Modint mul;
    void init() {
      mul = Modint(1);
    }
    Lazy() { init(); }
    void split(Lazy &lhs_lazy, Lazy &rhs_lazy, int len) {
      lhs_lazy = *this;
      rhs_lazy = *this;
      init();
    }
    void merge(Lazy &oth, int len) {
      mul *= oth.mul;
    }
    void apply_to_seg(Seg &cur, int len) const {
      cur.prod *= mul;
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
    int upd(int l, int r, Lazy &val, bool new_ver = false) {
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

    int add (int l, Modint val, bool new_ver = false) {
      Lazy tmp;
      tmp.mul = val;
      return upd(l, l + 1, tmp, new_ver);
    }

    Modint mget (int l, int r) {
      r++;
      return get(l, r, r - 1).prod;
    }
  };

  SegTree tree (MAX_N);

  Modint get (int l, int r) {
    return tree.mget(l, r);
  }
  
  void build (int n) {
    map<int, int> last;

    for (int i = 1; i <= n; i++) {
      int cur = red[i];
      
      tree.add(i, Modint(cur), true);
      if (last.count(cur)) {
        tree.add(last[cur], inv(Modint(cur)), false);
      }
      last[cur] = i;
    }
  }
}

int main () {
  for (int i = 2; i < BIG; i++) {
    if (!sieve[i]) {
      smallp.push_back(i);
      for (int j = i; j < BIG; j += i) {
        sieve[j] = 1;
      }
    }
  }

  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    red[i] = factor(arr[i], factors[i]);
  }

  int last = 0;
  int qc;
  cin >> qc;

  big::build(n);
  small::build(n);

  for (int i = 0; i < qc; i++) {
    int l, r;
    cin >> l >> r;

    l = (last + l) % n + 1;
    r = (last + r) % n + 1;
    if (l > r) swap(l, r);

    Modint ans = big::get(l, r) * small::get(l, r);
    last = ans.val;
    cout << ans << '\n';
  }
}