#include <bits/stdc++.h>

template<typename Val, 
         typename VV = std::plus<Val>>
class fenwick_tree {
public:
  typedef std::size_t size_type;

protected:
  const Val E;

  size_type n;
  std::vector<Val> val;

  VV fun;

public:
  fenwick_tree() : fenwick_tree(0) {}

  fenwick_tree(size_type _n)
  : E(), n(_n), val(n + 1, E) {}

  fenwick_tree(size_type _n, const Val &_E)
  : E(_E), n(_n), val(n + 1, E) {}

  size_type size() const {
    return n;
  }

  void modify(size_type x, const Val &v) {
    for (++x; x <= n; x += x & -x) {
      val[x] = fun(val[x], v);
    }
  }

  Val query(size_type x) {
    Val s = E;
    for (; x; x ^= x & -x) {
      s = fun(s, val[x]);
    }
    return s;
  }
};

template<typename Tp, typename Comp>
class geometry {
public:
  static int sgn(const Tp &a, const Tp &b = Tp()) {
    static Comp cmp;
    return cmp(a, b) ? -1 : (cmp(b, a) ? 1 : 0);
  }

  static Tp safe_sqrt(const Tp &a) {
    if (!sgn(a)) {
      return Tp();
    } else {
      return std::sqrt(a);
    }
  }

  struct point {
    Tp x, y;

    point() : x(), y() {}

    point(const Tp &t_x, const Tp &t_y) : x(t_x), y(t_y) {}

    Tp len2() const {
      return x * x + y * y;
    }

    Tp len() const {
      return safe_sqrt(len2());
    }

    point unit2() const {
      Tp l = len2();
      if (!sgn(l)) {
        return point();
      }
      return point(x / l, y / l);
    }

    point unit() const {
      Tp l = len();
      if (!sgn(l)) {
        return point();
      }
      return point(x / l, y / l);
    }

    Tp angle() const {
      return std::atan2(y, x);
    }

    point rotate(Tp th) const {
      return point(x * std::cos(th) - y * std::sin(th),
                   y * std::cos(th) + x * std::sin(th));
    }

    point rotate90() const {
      return point(-y, x);
    }

    point &operator+=(const point &rhs) {
      x += rhs.x, y += rhs.y;
      return *this;
    }

    point &operator-=(const point &rhs) {
      x -= rhs.x, y -= rhs.y;
      return *this;
    }

    point &operator*=(const Tp &rhs) {
      x *= rhs, y *= rhs;
      return *this;
    }

    point &operator/=(const Tp &rhs) {
      x /= rhs, y /= rhs;
      return *this;
    }

    friend point operator+(const point &lhs, const point &rhs) {
      return point(lhs.x + rhs.x, lhs.y + rhs.y);
    }

    friend point operator-(const point &lhs, const point &rhs) {
      return point(lhs.x - rhs.x, lhs.y - rhs.y);
    }

    friend point operator*(const point &lhs, const Tp &rhs) {
      return point(lhs.x * rhs, lhs.y * rhs);
    }

    friend point operator*(const Tp &lhs, const point &rhs) {
      return point(lhs * rhs.x, lhs * rhs.y);
    }

    friend point operator/(const point &lhs, const Tp &rhs) {
      return point(lhs.x / rhs, lhs.y / rhs);
    }

    friend bool operator==(const point &lhs, const point &rhs) {
      return !sgn(lhs.x, rhs.x) && !sgn(lhs.y, rhs.y);
    }

    friend bool operator<(const point &lhs, const point &rhs) {
      int t = sgn(lhs.x, rhs.x);
      if (t) {
        return t < 0;
      } else {
        return sgn(lhs.y, rhs.y) < 0;
      }
    }

    friend std::istream &operator>>(std::istream &in, point &p) {
      return in >> p.x >> p.y;
    }

    friend std::ostream &operator<<(std::ostream &out, const point &p) {
      return out << p.x << " " << p.y;
    }
  };

  static Tp dot(const point &a, const point &b) {
    return a.x * b.x + a.y * b.y;
  }

  static Tp cross(const point &a, const point &b) {
    return a.x * b.y - a.y * b.x;
  }

  static Tp angle(const point &a, const point &b) {
    return std::atan2(cross(a, b), dot(a, b));
  }

  static Tp distance2(const point &a, const point &b) {
    return (a - b).len2();
  }

  static Tp distance(const point &a, const point &b) {
    return (a - b).len();
  }

  struct line {
    point a, b;

    line() : a(), b() {}

    line(const point &t_a, const point &t_b) : a(t_a), b(t_b) {}

    Tp get_Y(const Tp &X) const {
      if (sgn(a.x, b.x) == 0) {
        return a.y;
      }
      return (a + (X - a.x) / (b.x - a.x) * (b - a)).y;
    }
  };

  static bool parallel(const line &a, const line &b) {
    return !sgn(cross(a.b - a.a, b.b - b.a));
  }

  static std::vector<point> line_cross(const line &a, const line &b) {
    if (parallel(a, b)) {
      return {};
    }
    point u = a.a - b.a, v = a.b - a.a, w = b.b - b.a;
    return {a.a + cross(w, u) / cross(v, w) * v};
  }

  static std::vector<point> segment_cross(const line &a, const line &b) {
    Tp t1 = cross(b.a - a.a, a.b - a.a), t2 = cross(b.b - a.a, a.b - a.a);
    Tp t3 = cross(a.a - b.a, b.b - b.a), t4 = cross(a.b - b.a, b.b - b.a);
    if (!sgn(t1) && !sgn(t2) && !sgn(t3) && !sgn(t4)) {
      if (sgn(std::min(a.a.x, a.b.x), std::max(b.a.x, b.b.x)) > 0) {
        return {};
      }
      if (sgn(std::min(b.a.x, b.b.x), std::max(a.a.x, a.b.x)) > 0) {
        return {};
      }
      if (sgn(std::min(a.a.y, a.b.y), std::max(b.a.y, b.b.y)) > 0) {
        return {};
      }
      if (sgn(std::min(b.a.y, b.b.y), std::max(a.a.y, a.b.y)) > 0) {
        return {};
      }
      return {
        std::max(std::min(a.a, a.b), std::min(b.a, b.b)),
        std::min(std::max(a.a, a.b), std::max(b.a, b.b))
      };
    }
    if (sgn(t1) * sgn(t2) > 0) {
      return {};
    }
    if (sgn(t3) * sgn(t4) > 0) {
      return {};
    }
    return line_cross(a, b);
  }

  static std::vector<point> segment_set_cross(const std::vector<line> &s) {
    using pointer = typename std::vector<line>::const_iterator;

    std::vector<std::tuple<Tp, bool, pointer>> op;
    for (pointer it = s.begin(); it != s.end(); ++it) {
      if (sgn(it->a.x, it->b.x) > 0) {
        op.emplace_back(it->a.x, true, it);
        op.emplace_back(it->b.x, false, it);
      } else {
        op.emplace_back(it->a.x, false, it);
        op.emplace_back(it->b.x, true, it);
      }
    }
    std::sort(op.begin(), op.end(), [&](const auto &a, const auto &b) {
      int t = sgn(std::get<0>(a), std::get<0>(b));
      if (t) {
        return t < 0;
      }
      return std::get<1>(a) < std::get<1>(b);
    });

    Tp now = 0;

    std::function<bool(pointer, pointer)> cmp = [&](pointer i, pointer j) {
      int t = sgn(i->get_Y(now), j->get_Y(now));
      if (t) {
        return t < 0;
      }
      return i < j;
    };

    std::set<pointer, decltype(cmp)> S(cmp);
    bool ok = false;
    point ans;

    auto upd = [&](pointer i, pointer j) {
      auto tmp = segment_cross(*i, *j);
      if (!tmp.empty()) {
        if (!ok) {
          ok = true;
          ans = *tmp.begin();
        } else {
          ans = std::min(ans, *tmp.begin());
        }
      }
      return tmp;
    };

    for (auto p : op) {
      now = std::get<0>(p);
      if (ok && sgn(ans.x, now) < 0) {
        break;
      }
      pointer it = std::get<2>(p);
      if (std::get<1>(p)) {
        S.erase(it);
        auto nx = S.upper_bound(it);
        if (nx != S.begin() && nx != S.end()) {
          upd(*std::prev(nx), *nx);
        }
      } else {
        auto nx = S.upper_bound(it);
        if (nx != S.end()) {
          upd(it, *nx);
        }
        if (nx != S.begin()) {
          upd(*std::prev(nx), it);
        }
        S.insert(it);
      }
    }
    if (ok) {
      return {ans};
    } else {
      return {};
    }
  }

  struct circle {
    point o;
    Tp r;

    circle() : o(), r() {}

    circle(const point &t_o, const Tp &t_r) : o(t_o), r(t_r) {}
  };

  static std::vector<point> circle_cross(const circle &a, const circle &b) {
    Tp d = distance(a.o, b.o);
    if (sgn(d, a.r + b.r) > 0 || sgn(d, std::abs(a.r - b.r)) < 0 || !sgn(d)) {
      return {};
    }
    Tp x = (a.r * a.r - b.r * b.r + d * d) / (d * 2);
    Tp h = safe_sqrt(a.r * a.r - x * x);
    point p = a.o + x * (b.o - a.o).unit();
    point v = h * (a.o - b.o).unit().rotate90();
    if (!sgn(v.x) && !sgn(v.y)) {
      return {p};
    } else {
      return {p - v, p + v};
    }
  }

  static std::vector<point> circle_tangent(const circle &a, const point &p) {
    Tp d = distance(a.o, p);
    int t = sgn(d, a.r);
    if (t < 0) {
      return {};
    } else if (t == 0) {
      return {p};
    } else {
      return circle_cross(a, circle(p, safe_sqrt(d * d - a.r * a.r)));
    }
  }
};

struct double_compare {
  constexpr bool operator()(const double &a, const double &b) const {
    return a + 1e-9 <= b;
  }
};

using geo = geometry<double, double_compare>;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cout.setf(std::ios::fixed);
  std::cout.precision(12);

  int n;
  long long m;
  std::cin >> n >> m;
  std::vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> x[i] >> y[i];
  }
  
  auto check = [&](double r) {
    geo::circle c(geo::point(), r);
    std::vector<std::pair<double, double>> a;
    std::vector<double> v;
    for (int i = 0; i < n; ++i) {
      auto tmp = geo::circle_tangent(c, geo::point(x[i], y[i]));
      if (tmp.size() == 2) {
        double l = tmp[0].angle(), r = tmp[1].angle();
        if (l > r) {
          std::swap(l, r);
        }
        a.emplace_back(l, r);
        v.emplace_back(l);
        v.emplace_back(r);
      }
    }
    std::sort(a.begin(), a.end());
    std::sort(v.begin(), v.end());
    fenwick_tree<int> T(v.size());
    long long ans = 1ll * n * (n - 1) / 2;
    for (int i = (int)a.size() - 1; i >= 0; --i) {
      int pl = std::lower_bound(v.begin(), v.end(), a[i].first) - v.begin();
      int pr = std::lower_bound(v.begin(), v.end(), a[i].second) - v.begin();
      ans -= T.query(pr);
      T.modify(pl, 1);
      T.modify(pr, -1);
    }
    return ans >= m;
  };

  double l = 0, r = 2e4;
  while (l + 1e-9 <= r) {
    double mid = (l + r) / 2;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  std::cout << r << "\n";
}