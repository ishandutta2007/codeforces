#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

deque <int> dq;
int n, q, a[N], ptr;
pair <int, int> ans[N];

int main() {
  cin >> n >> q;
  int mx = -69;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    mx = max(mx, a[i]);
    dq.emplace_back(a[i]);
  }
  while (dq.front() < mx) {
    int u = dq.front(); dq.pop_front();
    int v = dq.front(); dq.pop_front();
    ans[++ptr] = make_pair(u, v);
    if (u < v) swap(u, v);
    dq.emplace_front(u);
    dq.emplace_back(v);
  }
  n = 0;
  while (!dq.empty()) {
    a[++n] = dq.front(); dq.pop_front();
  }
  while (q--) {
    long long at;
    scanf("%lld", &at);
    if (at <= ptr) {
      printf("%d %d\n", ans[at].first, ans[at].second);
    } else {
      long long rem = (at - ptr - 1) % (n - 1);
      printf("%d %d\n", mx, a[rem + 2]);
    }
  }
  return 0;
}