#include <bits/stdc++.h>

using namespace std;

const int N = 300005;

int n, z;
long long ans;
priority_queue <int> used;
priority_queue <int> unused;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &z);
    int x = 0, y = 0;
    if (not unused.empty()) {
      x = z + unused.top();
    }
    if (not used.empty()) {
      y = z + used.top();
    }
    if (x <= 0 and y <= 0) {
      unused.push(-z);
      continue;
    }
    if (x >= y) {
      ans += (long long) x;
      unused.pop();
    } else {
      ans += (long long) y;
      unused.push(used.top());
      used.pop();
    }
    used.push(-z);
  }
  printf("%lld\n", ans);
  return 0;
}