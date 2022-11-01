#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 400010;

ll b[N], x[N];
int n, q, p[N], cmd[N], ass[N];

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", x + i);
    cmd[i] = 1, p[i] = i;
  }
  cin >> q;
  for (int i = n + 1; i <= n + q; ++i) {
    scanf("%d", cmd + i);
    if (cmd[i] == 1) scanf("%d %lld", p + i, x + i);
    else scanf("%lld", x + i);
  }
  ll mx = -69696969;
  for (int i = n + q; i >= 1; --i) {
    if (cmd[i] == 1) {
      int pos = p[i];
      if (ass[pos]) continue;
      b[pos] = max(mx, x[i]);
      ass[pos] = 1;
    } else {
      mx = max(mx, x[i]);
    }
  }
  for (int i = 1; i <= n; ++i) printf("%lld ", b[i]);
  puts("");
  return 0;
}