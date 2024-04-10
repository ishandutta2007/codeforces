#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

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

int bin(int x, ll to) { 
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

const int M = 1010;

int n, m;
ll a[M];

int c[M][M];
int b[M];

void pre() {
  for (int i = 0; i < M; ++i)
    c[i][0] = 1;
  for (int i = 1; i < M; ++i)
    for (int j = 1; j < M; ++j)
      c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);

  b[0] = 1;
  for (int i = 1; i < M; ++i)
    for (int k = 0; k < i; ++k)
      udd(b[i], mul(b[i - 1 - k], c[i - 1][k]));
}

void read() {
  cin >> m >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char c;
      cin >> c;
      if (c == '1')
        a[j] |= (1ll << i);
    }
  }
}

void kill() {
  int ans = 1;
  sort(a, a + m);
  for (int i = 0, j = 0; i < m; i = j) {
    while (j < m && a[i] == a[j])
      ++j;
    ans = mul(ans, b[j - i]);
  }
  cout << ans << endl;
}


int main() {
  ios_base::sync_with_stdio(0);
#ifdef LOCAL
  freopen("e.in", "r", stdin);
#endif

  pre();
  read();
  kill();
    
  return 0;
}