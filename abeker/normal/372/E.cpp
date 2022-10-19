#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;

const int MAXN = 1005;
const int MOD = 1000000007;

struct frac {
  ll a, b;
  frac(ll _a, ll _b) {
    a = _a;
    b = _b;
    if (b < 0) {
      a = -a;
      b = -b;
    }
    if (b) {
      ll g = __gcd(abs(a), b);
      a /= g;
      b /= g;
    }
    else
      a = 1;
  }
  frac() {}
  bool operator <(const frac &rhs) const {
    if (a != rhs.a)
      return a < rhs.a;
    return b < rhs.b;
  }
};

frac operator +(const frac &L, const frac &R) {
  return frac(L.a * R.b + L.b * R.a, L.b * R.b);
}

frac operator -(const frac &L, const frac &R) {
  return frac(L.a * R.b - L.b * R.a, L.b * R.b);
}

frac operator *(const frac &L, const frac &R) {
  return frac(L.a * R.a, L.b * R.b);
}

frac operator /(const frac &L, const frac &R) {
  return frac(L.a * R.b, L.b * R.a);
}

typedef pair <frac, frac> point;
#define x first
#define y second

point operator +(const point &L, const point &R) {
  return point(L.x + R.x, L.y + R.y);
}

point invert(point P) {
  return point(P.x / (P.x * P.x + P.y * P.y), P.y / (P.x * P.x + P.y * P.y));
}

int N;
map <point, vector <frac> > M;
point p[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    p[i] = invert(point(frac(a, b), frac(c, d)));
  }
}

frac slope(point A, point B) {
  return (A.y - B.y) / (A.x - B.x);
}

inline int add(int x, int y) {
  x += y;
  if (x >= MOD)
    x -= MOD;
  else if (x < 0)
    x += MOD;
  return x;
}

inline int mul(int x, int y) {
  return (ll)x * y % MOD;
}

int calc(vector <frac> V) {
  map <frac, int> cnt;
  for (int i = 0; i < V.size(); i++)
    cnt[V[i]]++;
  
  int res = 1;
  for (map <frac, int> :: iterator it = cnt.begin(); it != cnt.end(); it++)
    res = mul(res, (it -> second) + 1);
    
  return add(res, -(V.size() + 1));
}

int solve() {
  for (int i = 0; i < N; i++)
    for (int j = 0; j < i; j++)
      M[p[i] + p[j]].push_back(slope(p[i], p[j]));
  
  int sol = 0;
  for (map <point, vector <frac> > :: iterator it = M.begin(); it != M.end(); it++)
    sol = add(sol, calc(it -> second));
  
  return sol;
}

int main() {
  load();
  printf("%d\n", solve());
  return 0;
}