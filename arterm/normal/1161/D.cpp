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
 

const int M = 2010;

int n;
string s;

int p[M];
int r[M];
vector<int> g[M];
int c[M];
int comp[M];
bool ok;

void read() {
  cin >> s;
  n = s.length();
  reverse(all(s));
}

void ini() {
  iota(p, p + M, 0);
  fill(r, r + M, 0);
  for (int i = 0; i < M; ++i)
    g[i].clear();
  fill(c, c + M, -1);
  fill(comp, comp + M, -1);
  ok = true;
}

int get(int x) {
  return p[x] = p[x] == x ? x : get(p[x]);
}

int uni(int x, int y) {
  x = get(x);
  y = get(y);
  if (x == y)
    return x;
  if (r[x] < r[y]) {
    swap(x, y);
  }
  r[x]++;
  p[y] = x;
  return x;
}

void add_same(int u, int v) {
  uni(u, v);
}

void add_diff(int u, int v) {
  u = get(u);
  v = get(v);
  if (u == v) {
    ok = false;
    return;
  }
  //cerr << u << " " << v << "\n";
  g[u].push_back(v);
  g[v].push_back(u);
}

void dfs(int v, int col, int id) {
  if (c[v] != -1) {
    assert(comp[v] != -1);
    ok &= c[v] == col;
    return;
  }
  c[v] = col;
  comp[v] = id;
  for (int u : g[v])
    dfs(u, 1 - col, id);
}

int count(int m) {
  ini();

  for (int i = 0; n - i - 1 > i; ++i)
    add_same(i, n - 1 - i);

  for (int j = 0; m - j - 1 > j; ++j)
    add_same(n + j, n + (m - j - 1));

  const int ONE = n + m;
  const int ZERO = n + m + 1;
  const int N = n + m + 2;

  for (int i = m; i < n; ++i) {
    if (s[i] == '0')
      add_same(i, ZERO);
    if (s[i] == '1')
      add_same(i, ONE);
  }

  for (int i = 0; i < m; ++i)
    if (s[i] == '0')
      add_same(i, i + n);

  add_same(n + m - 1, ONE);

  for (int i = 0; i < m; ++i)
    if (s[i] == '1')
      add_diff(i, i + n);
  add_diff(ONE, ZERO);
  

  int last = 0;

  for (int v = 0; v < N; ++v)
    if (get(v) == v && comp[v] == -1) {
      dfs(v, 0, last);
      ++last;
    }

  if (!ok)
    return false;

  int one = get(ONE);
  int zero = get(ZERO);

  //cerr << "one = " << one << "\n";
  //cerr << "zero = " << zero << "\n";

  if (comp[one] == comp[zero]) {
    assert(last >= 1);
    return bin(2, last - 1);
  } else {
    assert(last >= 2);
    return bin(2, last - 2);
  }
}

void kill() {
  int ans = 0;
  for (int m = 1; m < n; ++m) {
    udd(ans, count(m));
    //cerr << m << " -> " << count(m) << "\n";
  }
  cout << ans << "\n";
}


int main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}