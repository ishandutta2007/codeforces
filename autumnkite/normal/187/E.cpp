#include <bits/stdc++.h>

template<typename T>
using less_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

class set {
  std::priority_queue<long long> Q;
  less_heap<long long> R;
  long long sum;

public:
  set() : Q(), R(), sum() {}

  void insert(long long x) {
    if (!Q.empty() && x < Q.top()) {
      Q.push(x);
      sum += x;
    } else {
      R.push(x);
    }
  }

  long long query(int k) {
    while ((int)Q.size() > k) {
      sum -= Q.top();
      R.push(Q.top());
      Q.pop();
    }
    while ((int)Q.size() < k) {
      sum += R.top();
      Q.push(R.top());
      R.pop();
    }
    return sum;
  }
};

const long long INF = std::numeric_limits<long long>::max() / 2;

std::pair<long long, std::vector<int>>
solve(std::vector<long long> a, int s, int k) {
  int n = a.size();
  if (s == n - 1) {
    return std::make_pair(INF, std::vector<int>());
  }
  long long tmp = 2 * (a.back() - a.front()) + a[s];
  long long ans = INF, id = 0;
  set S;
  for (int i = s + 1; i < n; ++i) {
    int rem = k, t = std::min(s, std::max(1, rem));
    rem -= t;
    rem -= n - 1 - i;
    if (0 <= rem && rem < std::max(1, i - s - 1)) {
      long long v = S.query(rem) * 2 + tmp - a[i];
      if (v < ans) {
        ans = v;
        id = i;
      }
    }
    if (i - 1 > s) {
      S.insert(a[i] - a[i - 1]);
    }
  }
  if (ans == INF) {
    return std::make_pair(INF, std::vector<int>());
  }

  std::vector<int> p(1, s);
  int rem = k, t = std::min(s, std::max(1, rem));
  rem -= t;
  rem -= n - 1 - id;
  std::vector<std::pair<long long, int>> d;
  for (int i = id - 1; i - 1 > s; --i) {
    d.emplace_back(a[i] - a[i - 1], i);
  }
  std::sort(d.begin(), d.end());
  std::vector<int> pos;
  for (int i = 0; i < rem; ++i) {
    pos.push_back(d[i].second);
  }
  std::sort(pos.begin(), pos.end());
  for (int i = t - 1; i >= 0; --i) {
    p.push_back(i);
  }
  for (int i = t; i < s; ++i) {
    p.push_back(i);
  }
  for (int i = s + 1; i < id; ++i) {
    p.push_back(i);
  }
  for (int i = 0, j = 0; i < (int)pos.size(); i = j) {
    while (j < (int)pos.size() && pos[j] - j == pos[i] - i) {
      ++j;
    }
    std::reverse(p.begin() + pos[i] - 1, p.begin() + pos[i] + (j - i));
  }
  for (int i = n - 1; i >= id; --i) {
    p.push_back(i);
  }
  return std::make_pair(ans, p);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, lim, s;
  std::cin >> n >> lim >> s;
  --s;
  std::vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  
  auto t1 = solve(a, s, lim);

  int m = *std::max_element(a.begin(), a.end());
  for (int i = 0; i < n; ++i) {
    a[i] = m - a[i];
  }
  std::reverse(a.begin(), a.end());

  auto t2 = solve(a, n - 1 - s, n - 1 - lim);

  for (int &x : t2.second) {
    x = n - 1 - x;
  }

  auto ans = std::min(t1, t2);
  if (ans.first == INF) {
    std::cout << -1 << "\n";
    return 0;
  }
  std::cout << ans.first << "\n";
  for (int i = 1; i < n; ++i) {
    std::cout << ans.second[i] + 1 << " \n"[i == n - 1];
  }
}