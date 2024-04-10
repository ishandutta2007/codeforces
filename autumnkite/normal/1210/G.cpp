#include <bits/stdc++.h>

constexpr long long INF = std::numeric_limits<long long>::max() / 2;

class convex {
  std::multiset<int> A, B;
  int d;
  long long st;

public:
  convex() : d(), st() {}

  void insert(int x) {
    if (x < 0) {
      if (!A.empty()) {
        B.insert(*(--A.end()) - d);
        A.erase(--A.end());
      } else {
        B.insert(-d);
      }
    } else if (x > d) {
      if (!B.empty()) {
        A.insert(*B.begin() + d);
        B.erase(B.begin());
      } else {
        A.insert(d);
      }
    } else {
      if (B.empty() || x <= *B.begin() + d) {
        A.insert(x);
        A.insert(x);
        B.insert(*(--A.end()) - d);
        A.erase(--A.end());
      } else {
        B.insert(x - d);
        B.insert(x - d);
        A.insert(*B.begin() + d);
        B.erase(B.begin());
      }
    }
    st += std::abs(x);
  }

  void update(int x) {
    d += x;
  }

  long long query(int x) const {
    int k = A.size();
    int lst = 0;
    long long now = st;
    for (int p : A) {
      p = std::min(p, x);
      if (p > lst) {
        now -= 1ll * k * (p - lst);
        lst = p;
      }
      --k;
    }
    for (int p : B) {
      p += d;
      p = std::min(p, x);
      if (p > lst) {
        now += 1ll * k * (p - lst);
        lst = p;
      }
      ++k;
    }
    return now + 1ll * k * (x - lst);
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<int> v(n), d(n);
  for (int i = 0; i < n; ++i) {
    int l, r;
    std::cin >> v[i] >> l >> r;
    v[i] -= l;
    d[i] = r - l;
  }

  auto calc = [&](int x) {
    int sum = 0;
    convex f;
    for (int i = 0; i < n; ++i) {
      sum += v[i];
      f.update(d[i]);
      f.insert(sum + x);
    }
    return f.query(sum);
  };

  int l = -2e9, r = 2e9;
  while (l + 1 < r) {
    int mid = l + ((unsigned)(r - l) >> 1);
    if (calc(mid) < calc(mid - 1)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  std::cout << calc(l) << "\n";
}