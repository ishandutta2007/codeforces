#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 200200;
const int N = 7;
const int ROOT = 0;

typedef array<int, N> R;

int n, k;
ll sum = 0;
ll cnt[N];
vector<int> g[M];

R prop(const R &cur) {
  R ans;
  for (int i = 0; i < k; ++i)
    ans[(i + 1) % k] = cur[i];
  return ans;
}

void read() {
  cin >> n >> k;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
}

int dfs1(int v, int from) {
  int ans = 1;
  for (int to : g[v])
    if (to != from) {
      int x = dfs1(to, v);
      ans += x;
      sum += 1ll * x * (n - x);
    }
  return ans;
}

R dfs2(int v, int from) {
  R ans;
  fill(all(ans), 0); 
  ans[0] = 1;
  
  for (int to : g[v])
    if (to != from) {
      R x = dfs2(to, v);
      for (int i = 0; i < k; ++i)
        for (int j = 0; j < k; ++j)
          cnt[(i + j) % k] += 1ll * ans[i] * x[j];
      
      for (int i = 0; i < k; ++i)
        ans[i] += x[i];
    }

  return prop(ans);
}

void kill() {
  int root = ROOT % n;
  dfs1(root, -1);
  dfs2(root, -1);

  ll ans = sum;
  for (int i = 0; i < k; ++i)
    ans += 1ll * ((k - i) % k) * cnt[i];

  assert(ans % k == 0);
  ans /= k;
  cout << ans << endl;
}

int main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}