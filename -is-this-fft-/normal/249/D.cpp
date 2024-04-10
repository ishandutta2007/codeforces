#include <iostream>
#include <vector>
#include <climits>
#include <tuple>
#include <algorithm>
#include <complex>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Point;
#define x first
#define y second

ll cross (Point p, Point q) {
  return p.x * q.y - p.y * q.x;
}

ll norm (Point p) {
  return p.x * p.x + p.y * p.y;
}

struct OrderedPoint {
  Point transf;
  ll dist;
};

bool operator< (OrderedPoint p, OrderedPoint q) {
  return p.dist > q.dist;
}

// Fully overloaded any dimensional BIT, use any type for
// coordinates, elements, return_value. Includes
// coordinate compression.
template <class E_T, class C_T, C_T n_inf, class R_T>
struct BIT {
  vector<C_T> pos;
  vector<E_T> elems;
  bool act = false;

  BIT () {
    pos.push_back(n_inf);
  }
  
  void init () {
    if (act) {
      for (E_T &c_elem : elems) c_elem.init();
    } else {
      act = true;
      sort(pos.begin(), pos.end());
      pos.resize(unique(pos.begin(), pos.end()) - pos.begin());
      elems.resize(pos.size());
    }
  }
  
  template <typename... loc_form>
  void update (C_T cx, loc_form... args) {
    if (act) {
      int x = lower_bound(pos.begin(), pos.end(), cx) - pos.begin();
      for (; x < (int)pos.size(); x += x & -x)
        elems[x].update(args...);
    } else {
      pos.push_back(cx);
    }
  }
  
  template <typename... loc_form>
  R_T query (C_T cx, loc_form... args) { // sum in (-inf, cx)
    R_T res = 0;
    int x = lower_bound(pos.begin(), pos.end(), cx) - pos.begin() - 1;
    for (; x > 0; x -= x & -x)
      res = max(res, elems[x].query(args...));
    return res;
  }
};

template <typename I_T>
struct wrapped {
  I_T a = 0;
  void update(I_T b) { a = max(a, b); }
  I_T query() { return a; }
  // Should never be called, needed for compilation
  void init() { }
  void update() { }
};

OrderedPoint create_ordered (Point p, Point va, Point vb) {
  OrderedPoint transf;
  transf.transf = Point(-cross(va, p), cross(vb, p));
  transf.dist = norm(p);
  return transf;
}

Point parse_frac (string frac) {
  for (int i = 0; i < (int) frac.size(); i++) {
    if (frac[i] == '/') {
      frac[i] = ' ';
    }
  }

  stringstream sin (frac);
  Point P;
  sin >> P.y >> P.x;
  return P;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  
  string ab, cd;
  cin >> ab >> cd;

  Point va = parse_frac(ab);
  Point vb = parse_frac(cd);

  vector<OrderedPoint> pts;
  for (int i = 0; i < n; i++) {
    Point p;
    cin >> p.x >> p.y;

    auto transf = create_ordered(p, va, vb);
    pts.push_back(transf);
  }

  Point zero (0, 0);
  pts.push_back(create_ordered(zero, va, vb));

  BIT<BIT<wrapped<ll>, ll, LLONG_MIN, ll>, ll, LLONG_MIN, ll> fenwick;
  int dim = 2;
  for (int i = 0; i < dim; ++i) {
    for (auto &pt : pts) {
      fenwick.update(pt.transf.x, pt.transf.y);
    }
    fenwick.init();
  }

  int ans = 0;
  sort(pts.begin(), pts.end());
  for (auto pt : pts) {
    auto dp = 1 + fenwick.query(pt.transf.x, pt.transf.y);
    fenwick.update(pt.transf.x, pt.transf.y, dp);
    ans = dp;
  }

  cout << ans - 1 << endl;
}