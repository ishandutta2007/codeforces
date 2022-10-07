#include <bits/stdc++.h>

struct rain {
  int x, v, id;

  rain(int t_x, int t_v, int t_id) : x(t_x), v(t_v), id(t_id) {}

  bool operator<(const rain &rhs) const {
    return x < rhs.x;
  }
};

struct cmp0 {
  bool operator()(rain a, rain b) const {
    return a.v + a.x > b.v + b.x;
  }
};

struct cmp1 {
  bool operator()(rain a, rain b) const {
    return a.v - a.x > b.v - b.x;
  }
};

template<typename Cmp>
using rain_heap = std::priority_queue<rain, std::vector<rain>, Cmp>;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<rain> a;
    for (int i = 0; i < n; ++i) {
      int x, v;
      std::cin >> x >> v;
      a.emplace_back(x, v, i);
    }
    std::sort(a.begin(), a.end());
    
    std::vector<long long> s(n);
    
    {
      rain_heap<cmp0> Q;
      long long sum = 0;
      for (int i = 0; i < n; ++i) {
        Q.push(a[i]);
        sum += a[i].v + a[i].x;
        while (!Q.empty() && Q.top().v + Q.top().x - a[i].x < 0) {
          sum -= Q.top().v + Q.top().x;
          Q.pop();
        }
        s[i] += sum - 1ll * (int)Q.size() * a[i].x;
      }
    }
    {
      rain_heap<cmp1> Q;
      long long sum = 0;
      for (int i = n - 1; i >= 0; --i) {
        while (!Q.empty() && Q.top().v - Q.top().x + a[i].x < 0) {
          sum -= Q.top().v - Q.top().x;
          Q.pop();
        }
        s[i] += sum + 1ll * (int)Q.size() * a[i].x;
        Q.push(a[i]);
        sum += a[i].v - a[i].x;
      }
    }

    std::string ans(n, '1');
    {
      rain_heap<cmp0> Q;
      for (int i = 0; i < n; ++i) {
        Q.push(a[i]);
        if (s[i] > m) {
          while (!Q.empty() && Q.top().v + Q.top().x - a[i].x < s[i] - m) {
            ans[Q.top().id] = '0';
            Q.pop();
          }
        }
      }
    }
    {
      rain_heap<cmp1> Q;
      for (int i = n - 1; i >= 0; --i) {
        Q.push(a[i]);
        if (s[i] > m) {
          while (!Q.empty() && Q.top().v - Q.top().x + a[i].x < s[i] - m) {
            ans[Q.top().id] = '0';
            Q.pop();
          }
        }
      }
    }
    std::cout << ans << "\n";
  }
}