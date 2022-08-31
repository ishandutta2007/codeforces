#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int N = 2e5 + 7;
const int M = 998244353;

int sum(int a, int b) {
  return (a + b) % M;
}

int mul(int a, int b) {
  return (a * (ll) b) % M;
}

int pw(int a, int n) {
  int res = 1;
  while (n) {
    if (n % 2 == 0) {
      a = mul(a, a);
      n /= 2;
    } else {
      res = mul(res, a);
      n--;
    }
  }
  return res;
}

int inv(int x) {
  return pw(x, M - 2);
}

int fact[N], rfact[N];

int C(int n, int k ){
  return mul(fact[n], mul(rfact[k], rfact[n - k]));
}

const int mod = 998244353;

void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

const int md = 998244353;

 
namespace faq{ 
const int md = 998244353;
 
inline void add(int &x, int y) {
  x += y;
  if (x >= md) {
    x -= md;
  }
}
 
inline void sub(int &x, int y) {
  x -= y;
  if (x < 0) {
    x += md;
  }
}
 
inline int mul(int x, int y) {
  return (long long) x * y % md;
}
 
inline int power(int x, int y) {
  int res = 1;
  for (; y; y >>= 1, x = mul(x, x)) {
    if (y & 1) {
      res = mul(res, x);
    }
  }
  return res;
}
 
inline int inv(int a) {
  a %= md;
  if (a < 0) {
    a += md;
  }
  int b = md, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  if (u < 0) {
    u += md;
  }
  return u;
}
 
namespace ntt {
int base = 1, root = -1, max_base = -1;
vector<int> rev = {0, 1}, roots = {0, 1};
 
void init() {
  int temp = md - 1;
  max_base = 0;
  while (temp % 2 == 0) {
    temp >>= 1;
    ++max_base;
  }
  root = 2;
  while (true) {
    if (power(root, 1 << max_base) == 1 && power(root, 1 << max_base - 1) != 1) {
      break;
    }
    ++root;
  }
}
 
void ensure_base(int nbase) {
  if (max_base == -1) {
    init();
  }
  if (nbase <= base) {
    return;
  }
  assert(nbase <= max_base);
  rev.resize(1 << nbase);
  for (int i = 0; i < 1 << nbase; ++i) {
    rev[i] = rev[i >> 1] >> 1 | (i & 1) << nbase - 1;
  }
  roots.resize(1 << nbase);
  while (base < nbase) {
    int z = power(root, 1 << max_base - 1 - base);
    for (int i = 1 << base - 1; i < 1 << base; ++i) {
      roots[i << 1] = roots[i];
      roots[i << 1 | 1] = mul(roots[i], z);
    }
    ++base;
  }
}
 
void dft(vector<int> &a) {
  int n = a.size(), zeros = __builtin_ctz(n);
  ensure_base(zeros);
  int shift = base - zeros;
  for (int i = 0; i < n; ++i) {
    if (i < rev[i] >> shift) {
      swap(a[i], a[rev[i] >> shift]);
    }
  }
  for (int i = 1; i < n; i <<= 1) {
    for (int j = 0; j < n; j += i << 1) {
      for (int k = 0; k < i; ++k) {
        int x = a[j + k], y = mul(a[j + k + i], roots[i + k]);
        a[j + k] = (x + y) % md;
        a[j + k + i] = (x + md - y) % md;
      }
    }
  }
}
 
vector<int> multiply(vector<int> a, vector<int> b) {
  int need = a.size() + b.size() - 1, nbase = 0;
  while (1 << nbase < need) {
    ++nbase;
  }
  ensure_base(nbase);
  int sz = 1 << nbase;
  a.resize(sz);
  b.resize(sz);
  bool equal = a == b;
  dft(a);
  if (equal) {
    b = a;
  } else {
    dft(b);
  }
  int inv_sz = inv(sz);
  for (int i = 0; i < sz; ++i) {
    a[i] = mul(mul(a[i], b[i]), inv_sz);
  }
  reverse(a.begin() + 1, a.end());
  dft(a);
  a.resize(need);
  return a;
}
 
vector<int> inverse(vector<int> a) {
  int n = a.size(), m = n + 1 >> 1;
  if (n == 1) {
    return vector<int>(1, inv(a[0]));
  } else {
    vector<int> b = inverse(vector<int>(a.begin(), a.begin() + m));
    int need = n << 1, nbase = 0;
    while (1 << nbase < need) {
      ++nbase;
    }
    ensure_base(nbase);
    int sz = 1 << nbase;
    a.resize(sz);
    b.resize(sz);
    dft(a);
    dft(b);
    int inv_sz = inv(sz);
    for (int i = 0; i < sz; ++i) {
      a[i] = mul(mul(md + 2 - mul(a[i], b[i]), b[i]), inv_sz);
    }
    reverse(a.begin() + 1, a.end());
    dft(a);
    a.resize(n);
    return a;
  }
}
}
}
 

vector <int> solve(vector <int> a) {
  if (a.size() == 1) {
    vector <int> t;
    for (int i = 0; i <= a[0]; i++) {
      t.push_back(1);
    }
    return t;
  } else {
    vector <int> l, r;
    for (int i = 0; i < (int) a.size() / 2; i++) {
      l.push_back(a[i]);
    }
    for (int i = (int) a.size() / 2; i < (int) a.size(); i++) {
      r.push_back(a[i]);
    }
    return faq::ntt::multiply(solve(l), solve(r));
  }
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  fact[0] =1 ;
  for (int i= 1; i <= n; i++) {
    fact[i] = mul(fact[i-1],i);
  }
  for (int i = 0; i <= n; i++) rfact[i] = inv(fact[i]);
  map <int, int> cnt;
  vector <int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    cnt[p[i]]++;
  }
  int need = n / 2;
  vector <int> mda;
  for (auto c : cnt) {
    mda.push_back(c.second);
  }
  cout << solve(mda)[need] << '\n';
}