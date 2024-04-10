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
 

int bit(int mask, int i) {
  assert(i >= 0);
  return (mask >> i) & 1;
}

const int M = 40;

int d[M][2][2][2];
int h[M][2][2][2];

int fun(int A, int B, int K) {
  for (int i = 0; i < M; ++i)
    for (int ea = 0; ea < 2; ++ea)
      for (int eb = 0; eb < 2; ++eb)
        for (int ek = 0; ek < 2; ++ek) {
          d[i][ea][eb][ek] = 0;
          h[i][ea][eb][ek] = 0;
        }

  const int n = 31;
  d[0][1][1][1] = 1;

  for (int i = 0; i <= n; ++i) {
    int no = n - i;
    for (int ea = 0; ea < 2; ++ea)
      for (int eb = 0; eb < 2; ++eb)
          for (int ek = 0; ek < 2; ++ek) {
            int cnt = d[i][ea][eb][ek];
            int sum = h[i][ea][eb][ek];
            for (int ba = 0; ba < 2; ++ba)
              for (int bb = 0; bb < 2; ++bb) {
                int bk = ba ^ bb;
                if (ea && ba && !bit(A, no))
                  continue;
                if (eb && bb && !bit(B, no))
                  continue;
                if (ek && bk && !bit(K, no))
                  continue;

                int na = ea & (ba == bit(A, no) ? 1 : 0);
                int nb = eb & (bb == bit(B, no) ? 1 : 0);
                int nk = ek & (bk == bit(K, no) ? 1 : 0);

                udd(d[i + 1][na][nb][nk], cnt);
                udd(h[i + 1][na][nb][nk], add(sum, bk ? mul(cnt, bin(2, no)) : 0));
              }
          }
  }

  //return h[n + 1][0][0][0];
  return add(h[n + 1][0][0][0], d[n + 1][0][0][0]);
}

int main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  //int t;
  //cin >> t;
  //while (t--) {
    //int a, b, k;
    //cin >> a >> b >> k;
    //cerr << fun(a, b, k) << endl;
  //}
  //return 0;

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int xl, xr, yl, yr, k;
    cin >> xl >> yl >> xr >> yr >> k;
    --xl, --yl;

    int ans = 0;
    udd(ans, fun(xr, yr, k));
    udd(ans, fun(xl, yl, k));
    ans = sub(ans, fun(xr, yl, k));
    ans = sub(ans, fun(xl, yr, k));
    cout << ans << "\n";
  }
}