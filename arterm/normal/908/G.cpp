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

const int A = 12;
const int M = 807;

string s;
int cnt[A];
int a[M];
int ans = 0;
int c[M][M];
int mem[M];
int d[M][M][A];

void pre() {
  //cnk[0][0][0] = 1;
  //for (int i = 0; i < M; ++i)
    //for (int j = 0; j < M; ++j)
      //for (int k = 0; k < M; ++k) {
        //if (i)
          //udd(cnk[i][j][k], cnk[i - 1][j][k]);
        //if (j)
          //udd(cnk[i][j][k], cnk[i][j - 1][k]);
        //if (k)
          //udd(cnk[i][j][k], cnk[i][j][k - 1]);
      //}
      //
  for (int i = 0; i < M; ++i)
    c[i][0] = 1;
  
  for (int i = 1; i < M; ++i)
    for (int j = 1; j < M; ++j)
      c[i][j] = add(c[i - 1][j - 1], c[i - 1][j]);

  for (int i = 0; i < M; ++i)
    mem[i] = mul(sub(bin(10, i), 1), inv(9));

  for (int m = 0; m < M; ++m)
    for (int x = 0; x <= m; ++x)
      for (int t = 1; t <= 9; ++t)
        d[m][x][t] = mul(c[m][x], bin(t, x), bin(10 - t, m - x));
}

void read() {
  cin >> s;
  s = "0" + s;
  int i = s.length() - 1;
  while (s[i] == '9') {
    s[i] = '0';
    --i;
  }
  ++s[i];
  //cerr << s << endl;

  for (int i = 0; i < (int) s.length(); ++i)
    a[i] = s[i] - '0';
}

void calc(int m) {
  for (int c = 1; c <= 9; ++c) {
    int b = 0;
    for (int i = c; i <= 9; ++i)
      b += cnt[i];
    for (int x = 0; x <= m; ++x) {
      //int na = a + x;
      int nb = b + (m - x);
      int ways = d[m][x][c];
      udd(ans, mul(ways, mem[nb]));
    }
  }
}

void kill() {
  int n = s.length();
  for (int i = 0; i < n; ++i) {
    for (int c = 0; c < a[i]; ++c) {
      ++cnt[c];
      calc(n - 1 - i);
      --cnt[c];
    }
    ++cnt[a[i]];
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
#ifdef LOCAL
  freopen("g.in", "r", stdin);
#endif

  pre();
  read();
  kill();
    
  return 0;
}