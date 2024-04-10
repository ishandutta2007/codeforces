#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> pii;

const int MAXN = 1e5 + 5;
const int offset = 1 << 17;
const int MAXPRIMES = 9;
const int LOG = 16;

class Mint {
  int value;
  int ex[MAXPRIMES];
public: 
  static int mod, len;
  static int primes[MAXPRIMES][MAXN * LOG];
  Mint(int _value, bool spec = false) {
    value = _value;
    memset(ex, 0, sizeof ex);
    if (!value || !spec)
      return;
    for (int i = 0; i < len; i++)
      while (!(value % primes[i][1])) {
        value /= primes[i][1];
        ex[i]++;
      }
  }
  static int add(int x, int y) {
    x += y;
    if (x >= mod)
      return x - mod;
    return x;
  }
  static void mul(int &x, int y) {
    x = (ll)x * y % mod;
  }
  pii extgcd(int a, int b) {
    if (!b)
      return {1, 0};
    pii tmp = extgcd(b, a % b);
    return {tmp.second, tmp.first - a / b * tmp.second};
  }
  int operator [](int x) const {
    return ex[x];
  }
  int eval() const {
    int res = value;
    for (int i = 0; i < len; i++)
      mul(res, primes[i][ex[i]]);
    return res;
  }
  Mint invert() {
    value = extgcd(value, mod).first % mod;
    if (value < 0)
      value += mod;
    for (int i = 0; i < len; i++)
      ex[i] = -ex[i];
    return *this;
  }
  Mint operator +(const Mint &rhs) const {
    return add(eval(), rhs.eval());
  }
  void operator *=(const Mint &rhs) {
    mul(value, rhs.value);
    for (int i = 0; i < len; i++)
      ex[i] += rhs[i];
  }
};

struct Node {
  Mint sum, lazy;
  Node(Mint _sum) : sum(_sum), lazy(1) {}
  Node() : sum(0), lazy(1) {}
  Node operator +(const Node &rhs) const {
    return sum + rhs.sum;
  }
  void output() const {
    printf("%d\n", sum.eval());
  }
};

int N, Q;
int a[MAXN];
int Mint::len, Mint::mod;
int Mint::primes[MAXPRIMES][MAXN * LOG]; 
Node t[2 * offset];

void load() {
  scanf("%d%d", &N, &Mint::mod); 
  for (int i = 1; i <= N; i++)
    scanf("%d", a + i);
}

void push(int x, const Mint &val) {
  if (x < offset) {
    t[2 * x].lazy *= val;
    t[2 * x + 1].lazy *= val;
  }
}

void prop(int x) {
  t[x].sum *= t[x].lazy;
  push(x, t[x].lazy);
  t[x].lazy = 1;
}

void update(int x, int lo, int hi, int from, int to, const Mint &val) {
  prop(x);
  if (lo >= to || hi <= from)
    return;
  if (lo >= from && hi <= to) {
    t[x].sum *= val;
    push(x, val);
    return;
  }
  int mid = (lo + hi) / 2;
  update(2 * x, lo, mid, from, to, val);
  update(2 * x + 1, mid, hi, from, to, val);
  t[x] = t[2 * x] + t[2 * x + 1];
}

void update(int from, int to, const Mint &val) {
  update(1, 0, offset, from, to, val);
}

Node query(int x, int lo, int hi, int from, int to) {
  prop(x);
  if (lo >= to || hi <= from)
    return Node();
  if (lo >= from && hi <= to)
    return t[x];
  int mid = (lo + hi) / 2;
  return query(2 * x, lo, mid, from, to) + query(2 * x + 1, mid, hi, from, to);
}

void init() {
  int tmp = Mint::mod;
  for (int i = 2; i * i <= tmp; i++) 
    if (!(tmp % i)) {
      Mint::primes[Mint::len++][1] = i;
      while (!(tmp % i))
        tmp /= i;
    }
  if (tmp > 1)
    Mint::primes[Mint::len++][1] = tmp;
  for (int i = 0; i < Mint::len; i++) {
    Mint::primes[i][0] = 1;
    for (int j = 2; j < MAXN * LOG; j++) {
      Mint::primes[i][j] = Mint::primes[i][j - 1];
      Mint::mul(Mint::primes[i][j], Mint::primes[i][1]);
    }
  }
}

void solve() {
  for (int i = 0; i < 2 * offset; i++)
    t[i] = Node();
  for (int i = 1; i <= N; i++) 
    t[i + offset] = Mint(a[i], true);
  for (int i = offset - 1; i >= 0; i--) 
    t[i] = t[2 * i] + t[2 * i + 1];
  scanf("%d", &Q);
  while (Q--) {
    int t, l, r, p, x;
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d%d%d", &l, &r, &x);
      update(l, r + 1, Mint(x, true));
    }
    else if (t == 2) {
      scanf("%d%d", &p, &x);
      update(p, p + 1, Mint(x, true).invert());
    }
    else {
      scanf("%d%d", &l, &r);
      query(1, 0, offset, l, r + 1).output();
    }
  }
}

int main() {
  load();
  init();
  solve();
  return 0;
}