#include <bits/stdc++.h>
using namespace std;

class MonotoneQueue {
  deque <int> d;
public:
  void add(int x) {
    while (!d.empty() && x < d.back())
      d.pop_back();
    d.push_back(x);
  }
  void remove(int x) {
    if (!d.empty() && x == d.front())
      d.pop_front();
  }
  int get() const {
    return d.empty() ? 0 : d.front();
  }
};

void solve() {
  int N;
  scanf("%d", &N);
  vector <int> a(N);
  for (auto &it : a)
    scanf("%d", &it);
  auto check = [&](int k) {
    MonotoneQueue Q;
    vector <bool> bio(N + 1);
    for (int i = 0; i < N; i++) {
      Q.add(a[i]);
      if (i < k - 1)
        continue;
      int curr = Q.get();
      Q.remove(a[i - k + 1]);
      if (curr > N - k + 1 || bio[curr])
        return false;
      bio[curr] = true;
    }
    return true;
  };
  int lo = 2, hi = N + 1;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (check(mid))
      hi = mid;
    else
      lo = mid + 1;
  }
  printf("%d", check(1));
  for (int i = 2; i <= N; i++)
    printf("%d", i >= lo);
  puts("");
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--)
    solve();
  return 0;
}