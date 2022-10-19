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
 
mt19937 rg;

int rnd() {
  int t = rg();
  if (t < 0)
    t = -t;
  return t % mod;
}

const int M = 10100;

int n, m;
int l[M], r[M], x[M], w[M];
int a[M];
bool u[M];
vector<pair<int, int>> put[M], rem[M];

void read() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> l[i] >> r[i] >> x[i];
    --l[i];
    w[i] = rnd();
    //cerr << w[i] << endl;
  }
}

void kill() {
  for (int i = 0; i < m; ++i) {
    put[l[i]].emplace_back(x[i], w[i]);
    rem[r[i]].emplace_back(x[i], w[i]);
  }

  a[0] = 1;

  for (int i = 0; i < n; ++i) {
    for (auto p : put[i]) {
      int x = p.first;
      int w = p.second;
      for (int i = n; i >= x; --i)
        udd(a[i], mul(a[i - x], w));
    }

    for (auto p : rem[i]) {
      int x = p.first;
      int w = p.second;
      for (int i = x; i <= n; ++i)
        a[i] = sub(a[i], mul(a[i - x], w));
    }

    for (int i = 0; i <= n; ++i)
      u[i] |= (a[i] != 0);
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i)
    if (u[i])
      ++ans;
  cout << ans << "\n";
  for (int i = 1; i <= n; ++i)
    if (u[i])
      cout << i << " ";
  cout << "\n";
}


int main() {
#ifdef LOCAL
  //assert(freopen("e.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}