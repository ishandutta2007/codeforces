#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, a[N], rev[N];
pair <int, int> b[N];

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    b[i] = make_pair(a[i], i);
  }
  sort(b + 1, b + n + 1);
  for (int i = 1; i <= n; ++i) {
    a[i] = lower_bound(b + 1, b + n + 1, make_pair(a[i], i)) - b;
  }
  for (int i = 1; i <= n; ++i) rev[a[i]] = i;
  vector <pair <int, int>> ans;
  for (int i = n; i > 1; --i) {
    for (int j = a[i] + 1; j <= i; ++j) {
      int cur = a[i];
      ans.emplace_back(rev[j], i);
      swap(a[i], a[rev[j]]), swap(rev[cur], rev[j]);
    }
  }
  cout << ans.size() << '\n';
  for (auto it : ans) printf("%d %d\n", it.first, it.second);
  return 0;
}