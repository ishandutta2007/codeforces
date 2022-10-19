#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int mod = 998244353;
const int ROOT = 0;

int add(int x) {  
  return x;
}

template<typename... T>
int add(int x, T... y) {  
  x += add(y...);
  if (x >= mod)
        x -= mod;
  return x;
}

template<typename... T>
int udd(int &x, T... y) { 
  return x = add(x, y...);
}

template<typename... T>
int sub(int x, T... y) { 
  return add(x, mod - add(y...));
}

int mul(int x) { 
  return x;
}

template<typename... T>
int mul(int x, T... y) { 
  return 1ll * x * mul(y...) % mod;
}

int bin(int x, int to) { 
  int y = 1;
  while (to) { 
        if (to & 1)
                  y = mul(x, y);
            x = mul(x, x);
                to >>= 1;
  }
  return y;
}

int inv(int x) { 
  assert(x != 0);
  return bin(x, mod - 2);
}

const int M = 500500;

int n;
vector<int> g[M];
int cnt[M][2], d[M][2];
int sz[M];

void read() {
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
}

void dfs(int v, int from) {
  sz[v] = 1;

  cnt[v][0] = 0;
  cnt[v][1] = 1;

  d[v][0] = 0;
  d[v][1] = 1;

  for (int u : g[v])
    if (u != from) {
      dfs(u, v);

      sz[v] += sz[u];

      //int both_u = add(cnt[u][0], cnt[u][1]); // 2 ^sz u - 1

      int c[2] = {0, 0};
      // is edge
      udd(c[0], mul(cnt[v][0], add(cnt[u][0], cnt[u][1])));
      udd(c[0], mul(cnt[v][1], cnt[u][1]));
      udd(c[1], mul(cnt[v][1], cnt[u][0]));
      // no edge
      udd(c[0], mul(cnt[v][0], add(cnt[u][0], cnt[u][1])));
      udd(c[1], mul(cnt[v][1], add(cnt[u][0], cnt[u][1])));


      int e[2] = {0, 0};
      // is edge
      udd(e[0], mul(d[v][0], add(cnt[u][0], cnt[u][1])));
      udd(e[0], mul(cnt[v][0], add(d[u][0], d[u][1])));

      udd(e[0], mul(sub(d[v][1], cnt[v][1]), cnt[u][1]));
      udd(e[0], mul(cnt[v][1], d[u][1]));

      udd(e[1], mul(d[v][1], cnt[u][0]));
      udd(e[1], mul(cnt[v][1], d[u][0]));

      // no edge
      udd(e[0], mul(d[v][0], add(cnt[u][0], cnt[u][1])));
      udd(e[0], mul(cnt[v][0], add(d[u][0], d[u][1])));

      udd(e[1], mul(d[v][1], add(cnt[u][0], cnt[u][1])));
      udd(e[1], mul(cnt[v][1], add(d[u][0], d[u][1])));

      cnt[v][0] = c[0], cnt[v][1] = c[1];
      d[v][0] = e[0], d[v][1] = e[1];
    }

  //assert(add(cnt[v][0], cnt[v][1]) == bin(2, sz[v] - 1));
}

void kill() {
  int root = ROOT % n;
  dfs(root, -1);

  int ex = add(d[root][0], d[root][1]);
  //cerr << "ex = " << ex << "\n";
  int ans = sub(mul(n, bin(2, n - 1)), ex);
  cout << mul(2, ans) << "\n";

  //cerr << "kek\n";
}

int main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}