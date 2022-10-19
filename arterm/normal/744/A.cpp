#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const int M = 100100;

vector<int> g[M];
int c[M];
int n, m, k;
bool used[M];
int a[M];

void read() {
  cin >> n >> m >> k;
  for (int i = 0; i < k; ++i)
    cin >> c[i];
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
}

int dfs(int v) {
  if (used[v])
    return 0;
  used[v] = true;
  int ans = 1;
  for (int to : g[v])
    ans += dfs(to);
  return ans;
}

int c2(int x) {
  return x * (x - 1) / 2;
}

void kill() {
  for (int i = 0; i < k; ++i)
    a[i] = dfs(c[i]);
  int tot = accumulate(a, a + k, 0);
  int at = max_element(a, a + k) - a;
  a[at] += n - tot;

  int ans = 0;
  for (int i = 0; i < k; ++i)
    ans += c2(a[i]);

  ans -= m;

  cout << ans << endl;
}

int main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();

}