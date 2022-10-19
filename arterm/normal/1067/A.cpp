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

const int M = 100100;
const int T = 204;

int n, a[M];
int d[T], h[T];
int nd[T], nh[T];

void read() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
}

void ini() {
  fill(d, d + T, 0);
  fill(h, h + T, 0);
  
  d[0] = 1;
}

void put(int x) {
  fill(nd, nd + T, 0);
  fill(nh, nh + T, 0);

  for (int i = 0; i < 200; ++i) {
    udd(h[i + 1], h[i]);
    udd(d[i + 1], d[i]);
  }
  
  int l = 1, r = 200;
  if (x != -1)
    l = x, r = x;

  for (int i = l; i <= r; ++i) {
    nd[i] = add(sub(d[200], d[i - 1]), sub(h[i], h[i - 1]));
    nh[i] = add(d[i - 1], h[i - 1]);
  }

  copy(nd, nd + T, d);
  copy(nh, nh + T, h);

  //for (int i = 0; i <= 10; ++i)
    //cout << d[i] << " ";
  //cout << "\n";
  //for (int i = 0; i <= 10; ++i)
    //cout << h[i] << " ";
  //cout << "\n";
  //cout << "\n";
}

void kill() {
  ini();
  for (int i = 0; i < n; ++i) put(a[i]);

  int ans = 0;
  for (int i = 1; i <= 200; ++i)
    udd(ans, d[i]);

  cout << ans << "\n";
}

int main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}