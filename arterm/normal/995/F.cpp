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
 

const int M = 3030;
typedef array<int, M> Array;

Array operator*(const Array &A, const Array &B) {
  Array C;
  for (int i = 0; i < M; ++i)
    C[i] = mul(A[i], B[i]);
  return C;
}

Array s(const Array &A) {
  Array B(A);
  for (int i = 1; i < M; ++i)
    udd(B[i], B[i - 1]);
  return B;
}

Array I;

int n, d;
vector<int> g[M];

void read() {
  cin >> n >> d;
  for (int i = 1; i < n; ++i) {
    int x;
    cin >> x;
    --x;
    g[x].push_back(i);
  }
}

Array dfs(int v) {
  Array ans = I;
  for (int u : g[v])
    ans = ans * dfs(u);
  return s(ans);
}

void kill() {
  Array A = dfs(0);
  int ans = 0;
  int cur = 1;
  d = sub(d, 1);

  //for (int i = 0; i < 10; ++i)
    //cout << A[i] << endl;
  
  int f = 1;
  for (int i = 0; i <= n; ++i) {
    udd(ans, mul(cur, A[0], inv(f)));

    //cerr << i << ": " << mul(inv(f), A[0]) << endl;

    f = mul(f, add(i, 1));
    cur = mul(cur, d);
    d = sub(d, 1);

    for (int j = 0; j <= n; ++j)
      A[j] = sub(A[j + 1], A[j]);
  }

  cout << ans << endl;
}

int main() {
#ifdef LOCAL
  assert(freopen("f.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  for (int i = 0; i < M; ++i)
    I[i] = 1;

  read();
  kill();
}