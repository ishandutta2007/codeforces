#include <bits/stdc++.h>

struct node {
  int x, y;
  long long v;
};

class convex {
public:
  struct line {
    long long k, b;

    line(long long k_, long long b_) : k(k_), b(b_) {}

    long long get(long long x) const {
      return k * x + b;
    }
  };

protected:
  std::vector<line> sta;
  std::size_t h;

  bool check(const line &a, const line &b, const line &c) const {
    return (__int128_t)(a.b - b.b) * (c.k - b.k) <
           (__int128_t)(b.b - c.b) * (b.k - a.k);
  }

public:
  convex() : sta(), h() {}

  void insert(const line &v) {
    while (h + 1 < sta.size() &&
           !check(sta[sta.size() - 2], sta.back(), v)) {
      sta.pop_back();
    }
    sta.push_back(v);
  }

  long long query(long long x) {
    long long lst = sta[h].get(x), v;
    while (h + 1 < sta.size() && (v = sta[h + 1].get(x)) > lst) {
      ++h;
      lst = v;
    }
    return lst;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<node> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i].x >> a[i].y >> a[i].v;
  }
  std::sort(a.begin(), a.end(), [&](const node &a, const node &b) {
    return a.x < b.x || (a.x == b.x && a.y > b.y);
  });

  std::vector<long long> f(n);
  convex T;
  T.insert(convex::line(0, 0));
  for (int i = 0; i < n; ++i) {
    f[i] = T.query(-a[i].y) + 1ll * a[i].x * a[i].y - a[i].v;
    T.insert(convex::line(a[i].x, f[i]));
  }
  std::cout << T.query(0) << "\n";
}