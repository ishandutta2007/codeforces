#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

vector <int> g[N];
vector <int> divs[N];
int n, a[N], cnt[N], ans[N];

void go (int u = 1, int pr = -1, int far = 0) {
  for (int d : divs[a[u]]) ++cnt[d];
  ans[u] = 1;
  for (int d : divs[a[u]]) if (cnt[d] >= far) ans[u] = max(ans[u], d);
  for (int d : divs[a[1]]) if (cnt[d] >= far) ans[u] = max(ans[u], d);
  for (int v : g[u]) if (v ^ pr) go(v, u, far + 1);
  for (int d : divs[a[u]]) --cnt[d];
}

int main() {
  for (int i = 1; i < N; ++i) {
    for (int j = i; j < N; j += i) {
      divs[j].emplace_back(i);
    }
  }
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 1, u, v; i < n; ++i) {
    scanf("%d %d", &u, &v);
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  go();
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
  cout << '\n';
  return 0;
}