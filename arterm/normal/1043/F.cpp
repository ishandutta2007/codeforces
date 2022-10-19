#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int mod = 987654319;

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
const int T = 100;

int a[T];
int b[T];

bool np[M];
int rad[M];
vector<int> p[M];
int cnt[M];
bool u[M];

void sito() {
  fill(rad, rad + M, 1);

  for (int i = 2; i < M; ++i)
    if (!np[i]) {
      for (int j = i; j < M; j += i) {
        np[j] = true;
        p[j].push_back(i);
        rad[j] *= i;
      }
    }
}

void read() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    x = rad[x];
    u[x] = true;
  }
}

int bit(int mask, int i) {
  return (mask >> i) & 1;
}

int gcd(int x, int y) {
  while (x) {
    y %= x;
    swap(x, y);
  }
  return y;
}

int m;

bool check(int k) {
  int full = (1 << m) - 1;

  for (int mask = 0; mask < (1 << m); ++mask)
    b[full ^ mask] = a[mask];

  for (int i = 0; i < m; ++i) {
    for (int mask = 0; mask < (1 << m); ++mask)
      if (!bit(mask, i))
        udd(b[mask | (1 << i)], b[mask]);
  }

  for (int mask = 0; mask < (1 << m); ++mask)
      b[mask] = bin(b[mask], k);
  //cerr << "b0 = " << b[0] << "\n";
  //cerr << "full = " << full << "\n";

  for (int i = 0; i < m; ++i) {
    for (int mask = 0; mask < (1 << m); ++mask)
      if (!bit(mask, i))
        b[mask | (1 << i)] = sub(b[mask | (1 << i)], b[mask]);
  }

  return b[full] != 0;
}

void kill() {
  int g = 0;

  for (int x = 1; x < M; ++x)
    if (u[x]) {
      g = gcd(g, x);
      
      m = p[x].size();
      for (int mask = 0; mask < (1 << m); ++mask) {
        int prod = 1;
        for (int j = 0; j < m; ++j)
          if (bit(mask, j))
            prod *= p[x][j];
        cnt[prod]++;
      }
    }

  if (g != 1) {
    cout << "-1\n";
    return;
  }

  int ans = 100;

  for (int x = 1; x < M; ++x)
    if (u[x]) {
      m = p[x].size();
      for (int mask = 0; mask < (1 << m); ++mask) {
        int prod = 1;
        for (int j = 0; j < m; ++j)
          if (bit(mask, j))
            prod *= p[x][j];
        a[mask] = cnt[prod];
      }

      for (int i = 0; i < m; ++i)
        for (int mask = 0; mask < (1 << m); ++mask)
          if (bit(mask, i))
            a[mask ^ (1 << i)] -= a[mask];

      //for (int i = 0; i < (1 << m); ++i)
        //cerr << i << ": " << a[i] << "\n";
      //cerr << "\n";

      //cerr << "m = " << m << "\n";
      //cerr << x << ": " << check(0) << "\n";

      for (int mask = 0; mask < (1 << m); ++mask)
        a[mask] = a[mask] == 0 ? 0 : 1;

      int l = 0, r = 7;
      while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid))
          r = mid;
        else
          l = mid + 1;
      }

      ans = min(ans, l + 1);
    }

  cout << ans << "\n";
}

int main() {
#ifdef LOCAL
  assert(freopen("f.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  sito();
  read();
  kill();
}