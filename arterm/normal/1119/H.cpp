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

const int A = 18;
const int N = 1 << A;
const int M = 100100;

int n, k, m;
int a[3][M];
int x[3];
int f[N];

void read() {
  cin >> m >> k;
  n = 1 << k; // HOBA

  for (int j = 0; j < 3; ++j) {
    cin >> x[j];
    x[j] %= mod;
  }

  for (int i = 0; i < m; ++i) { // OTSOSOANO
    for (int j = 0; j < 3; ++j)
      cin >> a[j][i];
  }
}

int bit(int mask, int i) {
  return (mask >> i) & 1;
}

void conv(int *a, int k) {
  for (int i = 0; i < k; ++i) {
    for (int mask = 0; mask < (1 << k); ++mask) {
      if (bit(mask, i) == 0) {
        int x = a[mask];
        int y = a[mask ^ (1 << i)];
        a[mask] = add(x, y);
        a[mask ^ (1 << i)] = sub(x, y);
      }
    }
  }
}

void iconv(int *a, int k) {
  conv(a, k);
  int by = inv(bin(2, k));
  for (int i = 0; i < (1 << k); ++i)
    a[i] = mul(a[i], by);
}

int comb[8];
int val[N][8];

void kill() {
  for (int uber = 0; uber < 8; ++uber) {
    for (int j = 0; j < 3; ++j) {
      if (bit(uber, j)) {
        comb[uber] = sub(comb[uber], x[j]);
      } else {
        comb[uber] = add(comb[uber], x[j]);
      }
    }
  }

  for (int uber = 0; uber < 8; ++uber) {
    fill(f, f + n, 0);

    for (int j = 0; j < m; ++j) {
      int cur = 0;
      for (int bt = 0; bt < 3; ++bt) {
        if (bit(uber, bt)) {
          cur ^= a[bt][j];
        }
      }
      f[cur]++;
    }

    conv(f, k);
    for (int mask = 0; mask < n; ++mask) {
      val[mask][uber] = f[mask];
    }
  }


  fill(f, f + n, 1);

  for (int mask = 0; mask < n; ++mask) {
    iconv(val[mask], 3);
    for (int j = 0; j < 8; ++j) {
      f[mask] = mul(f[mask], bin(comb[j], val[mask][j]));
      //cerr << val[mask][j] << " ";
    }
    //cerr << "\n";
  }

  iconv(f, k);
  for (int i = 0; i < n; ++i)
    cout << f[i] << " ";
  cout << "\n";
}
 

int main() {
#ifdef LOCAL
  assert(freopen("h.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}