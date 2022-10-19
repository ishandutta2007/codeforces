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

const int M = 300300;

int n, x[M];

void read() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> x[i];
}

void kill() {
  int ans = 0;
  sort(x, x + n);
  for (int i = 0; i + 1 < n; ++i) {
    int d = x[i + 1] - x[i];
    int bon = mul(sub(bin(2, i + 1), 1), sub(bin(2, n - i - 1), 1));
    udd(ans, mul(d, bon));
  }
  cout << ans << endl;
}

int main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);
  
  read();
  kill();

}