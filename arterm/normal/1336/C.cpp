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

const int M = 3030;

string s, t;
int n, m;
int f[M][M];
int d[M][M];

void read() {
  cin >> s >> t;
  n = s.length();
  m = t.length();
}

void kill() {
  for (int i = n; i >= 0; --i)
    f[i][0] = n - i + 1;

  for (int i = n - 1; i >= 0; --i) {
    for (int j = 1; j <= m; ++j) {
      f[i][j] = f[i + 1][j];

      if (s[i] == t[j - 1])
        udd(f[i][j], f[i + 1][j - 1]);
    }
  }


  for (int k = 0; k < m; ++k)
    if (t[k] == s[0])
      d[1][k] = 2;

  for (int i = 1; i < m; ++i) {
    for (int k = 0; k + i <= m; ++k) {
      if (k + i < m && s[i] == t[k + i])
        udd(d[i + 1][k], d[i][k]);

      if (k > 0 && s[i] == t[k - 1])
        udd(d[i + 1][k - 1], d[i][k]);
    }
  }

  int ans = 0;

  for (int i = 1; i < n; ++i)
    if (s[i] == t[m - 1])
      udd(ans, mul(bin(2, i), f[i + 1][m - 1]));

  udd(ans, mul(d[m][0], n - m + 1));

  for (int k = 1; k < m; ++k) {
    int bon = mul(d[k][m - k], f[k + 1][m - k]);
    udd(ans, bon);
  }


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