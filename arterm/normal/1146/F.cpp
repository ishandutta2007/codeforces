#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int mod = 998244353;

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


const int M = 200200;

int n;
vector<int> g[M];
int f[M], d[M];

void read() {
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int x;
    cin >> x;
    --x;
    g[x].push_back(i);
  }
}

void dfs(int v) {
  if (g[v].empty()) {
    f[v] = d[v] = 1;
    return;
  }

  int ps = 1, pf = 1;

  vector<int> fs;
  vector<int> ds;

  for (int u : g[v]) {
      dfs(u);

      fs.push_back(f[u]);
      ds.push_back(d[u]);

      pf = mul(pf, f[u]);
      ps = mul(ps, add(f[u], d[u]));
    }

  int m = fs.size();
  vector<int> pref(m + 1);
  vector<int> suff(m + 1);
  pref[0] = 1;
  for (int i = 0; i < m; ++i)
    pref[i + 1] = mul(pref[i], fs[i]);

  suff[m] = 1;
  for (int i = m - 1; i >= 0; --i)
    suff[i] = mul(fs[i], suff[i + 1]);

  int sum = 0;
  for (int i = 0; i < m; ++i)
    udd(sum, mul(pref[i], ds[i], suff[i + 1]));

  f[v] = sub(ps, sum);
  d[v] = sub(ps, pf);
}

void kill() {
  int root = 0;
  dfs(root);
  cout << f[root] << "\n";
}

int main() {
#ifdef LOCAL
  assert(freopen("f.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}