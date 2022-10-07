#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, k;
  std::cin >> n >> k;
  std::vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::vector<std::vector<int>> w(k, std::vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      std::cin >> w[j][i];
    }
  }
  int q;
  std::cin >> q;
  std::vector<std::pair<int, long long>> Q(q);
  for (int i = 0; i < q; ++i) {
    std::cin >> Q[i].first >> Q[i].second;
    --Q[i].first;
  }
  
  auto trans = [&](std::vector<long long> pos, std::vector<int> w) {
    std::vector<long long> sum(n + 1);
    for (int i = 0; i < n; ++i) {
      sum[i + 1] = sum[i] + w[i];
    }

    using segment = std::pair<int, int>;

    auto query = [&](segment a) {
      return sum[a.second] - sum[a.first];
    };

    auto check = [&](segment a, segment b) {
      return pos[a.second - 1] + 1 == pos[b.first]
             && (query(a) > 0 || query(b) < 0);
    };

    std::vector<segment> sta;
    for (int i = 0; i < n; ++i) {
      sta.emplace_back(i, i + 1);
      while (sta.size() >= 2 && check(sta[sta.size() - 2], sta.back())) {
        sta[sta.size() - 2].second = sta.back().second;
        sta.pop_back();
      }
    }
    std::vector<int> dir(sta.size());
    for (int i = 0; i < (int)sta.size(); ++i) {
      long long s = query(sta[i]);
      if (s > 0) {
        dir[i] = 1;
      } else if (s < 0) {
        dir[i] = -1;
      } else {
        dir[i] = 0;
      }
    }
    for (int i = 0; i + 1 < (int)sta.size(); ++i) {
      if (pos[sta[i].second - 1] + 2 == pos[sta[i + 1].first]
          && dir[i] == 1 && dir[i + 1] == -1) {
        if (query(sta[i]) + query(sta[i + 1]) <= 0) {
          dir[i] = 0;
        } else {
          dir[i + 1] = 0;
        }
      }
    }
    for (int i = 0; i < (int)sta.size(); ++i) {
      for (int j = sta[i].first; j < sta[i].second; ++j) {
        pos[j] += dir[i];
      }
    }
    return pos;
  };

  std::vector<int> id(q);
  for (int i = 0; i < q; ++i) {
    id[i] = i;
  }
  std::sort(id.begin(), id.end(), [&](int i, int j) {
    return Q[i].second < Q[j].second;
  });
  std::vector<long long> ans(q);
  long long now = 0;
  auto pos = a;
  for (int r : id) {
    while (now < Q[r].second / k) {
      auto npos = pos;
      for (int i = 0; i < k; ++i) {
        npos = trans(npos, w[i]);
      }
      std::vector<long long> delta(n);
      for (int i = 0; i < n; ++i) {
        delta[i] = npos[i] - pos[i];
      }
      long long add = Q[r].second / k - now;
      for (int i = 0; i + 1 < n; ++i) {
        long long d = delta[i] - delta[i + 1];
        if (d != 0 && pos[i + 1] - pos[i] < 2 * k + 2) {
          add = 0;
          break;
        }
        if (d <= 0) {
          continue;
        }
        add = std::min(add, (pos[i + 1] - pos[i] - 2 * k - 2) / d);
      }
      if (add == 0) {
        add = 1;
      }
      for (int i = 0; i < n; ++i) {
        pos[i] += delta[i] * add;
      }
      now += add;
    }
    auto tmp = pos;
    for (int i = 0; i < Q[r].second % k; ++i) {
      tmp = trans(tmp, w[i]);
    }
    ans[r] = tmp[Q[r].first];
  }
  for (auto x : ans) {
    std::cout << x << "\n";
  }
}