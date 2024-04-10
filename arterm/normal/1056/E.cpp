#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

int mod = 1e9 + 7;

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

const int M = 1000100;
string s, t;
int n, m;
int x, y;
int h[M];
int by;
int pwb[M];
bool ok[M];
int mods[] = {909090911, 909090179,  909884447};
int bys[] = {3, 5, 7};


void read() {
  cin >> s >> t;
  n = s.length();
  m = t.length();

  x = 0, y = 0;
  for (char c : s)
    if (c == '0')
      ++x;
    else
      ++y;
}

int subhash(int l, int r) {
  return sub(h[r], mul(pwb[r - l], h[l]));
}

void calc_hash() {
  h[0] = 0;
  for (int i = 0; i < m; ++i)
    h[i + 1] = add(mul(h[i], by), t[i] - 'a' + 3);
}

void check() {
  pwb[0] = 1;
  for (int i = 0; i < m; ++i)
    pwb[i + 1] = mul(by, pwb[i]);

  calc_hash();

  for (int lenx = 1; lenx * x <  m; ++lenx) {
    int leny = (m - lenx * x) / y;
    if (lenx * x + leny * y != m) {
      ok[lenx] = false;
      continue;
    }

    int cur = 0;
    int hx = -1, hy = -1;
    for (char c : s) {
      int hc;
      if (c == '0') {
        hc = subhash(cur, cur + lenx);
        cur += lenx;
      } else {
        hc = subhash(cur, cur + leny);
        cur += leny;
      }

      if (c == '0') {
        if (hx == -1)
          hx = hc;
        else if (hx != hc) {
          ok[lenx] = false;
          break;
        }
      } else {

        if (hy == -1)
          hy = hc;
        else if (hy != hc) {
          ok[lenx] = false;
          break;
        }
        
      }
    }

    if (hx == hy)
      ok[lenx] = false;
  }
}

void kill() {
  for (int lenx = 1; lenx * x < m; ++lenx) {
    ok[lenx] = true;
  }
  for (int i = 0; i < 3; ++i) {
    mod = mods[i];
    by = bys[i];
    check();
  }
  int ans = 0;
  for (int lenx = 1; lenx * x < m; ++lenx) {
    if (ok[lenx])
      ++ans;
  }
  cout << ans << "\n";
}

int main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}