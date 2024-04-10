#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

stack <int> s;
int n, a[N], f[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  f[1] = -1;
  s.push(1);
  for (int i = 2; i <= n; ++i) {
    f[i] = 0;
    while (not s.empty() and a[i] > a[s.top()]) {
      f[i] = max(f[i], f[s.top()] + 1);
      s.pop();
    }
    if (s.empty()) {
      f[i] = -1;
    }
    s.push(i);
  }
  int ans = -1;
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, f[i]);
  }
  printf("%d\n", ans + 1);
  return 0;
}