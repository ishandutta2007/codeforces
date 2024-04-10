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

int d[M][M], e[M][M];
bool u[M][M];

int pa, pb, k;
int ans = 0;

void read() {
  cin >> k >> pa >> pb;
  int s = inv(add(pa, pb));
  pa = mul(pa, s);
  pb = mul(pb, s);
}

void rec(int x, int y) {
  if (x + y >= k) {
    assert(y < k);
    udd(ans, mul(d[x][y], add(x, y, sub(inv(pb), 1))));
    //cerr << x << " " << y << endl;
    //cerr << d[x][y] << endl;
    //cerr << e[x][y] << endl;
    //cerr << endl;
    return;
  }

  udd(d[x + 1][y], mul(pa, d[x][y]));
  //udd(e[x + 1][y], mul(pa, add(e[x][y], d[x][y])));
  u[x + 1][y] = true;

  udd(d[x][x + y], mul(pb, d[x][y]));
  //udd(e[x][x + y], mul(pb, add(e[x][y], d[x][y])));
  u[x][x + y] = true;
}

void kill() {
  d[1][0] = 1;
  e[1][0] = inv(pa);
  u[1][0] = true;

  for (int x = 0; x <= k; ++x)
    for (int y = 0; y < k; ++y)
      if (u[x][y])
        rec(x, y);

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
#ifdef LOCAL
  freopen("d.in", "r", stdin);
#endif

  read();
  kill();
    
  return 0;
}