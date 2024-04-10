#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int mod = 1e9 + 7;

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
 
ll gcd(ll x, ll y) {
  while (x) {
    y %= x;
    swap(x, y);
  }
  return y;
}

const int M = 100100;

int n;
vector<int> g[M];
ll x[M];
int ans = 0;

void read() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
}

void dfs(int v, int from, unordered_map<ll, int> mp) {
  unordered_map<ll, int> nw;
  for (auto elem : mp) {
    udd(nw[gcd(elem.first, x[v])], elem.second);
  }
  udd(nw[x[v]], 1);

  for (auto elem : nw) {
    udd(ans, mul(elem.first % mod, elem.second));
  }

  for (int to : g[v])
    if (to != from)
      dfs(to, v, nw);
}

void kill() {
  dfs(0, -1, unordered_map<ll, int>());
  cout << ans << "\n";
}


int main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();

}