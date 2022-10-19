#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 100100;
const int ROOT = 0;

int n, mod, ph, i10;
ll ans = 0;
vector<int> g[M], h[M];
bool used[M];

int add(int x, int y) {
  x += y;
  if (x >= mod)
    x -= mod;
  return x;
}

int sub(int x, int y) {
  x -= y;
  if (x < 0)
    x += mod;
  return x;
}

int mul(ll x, ll y) {
  return x * y % mod;
}

int phi(int m) {
  int ans = 1;
  for (int p = 2; p * p <= m; ++p)
    if (m % p == 0) {
      ans *= p - 1;
      m /= p;
      while (m % p == 0) {
        m /= p;
        ans *= p;
      }
    }
  
  if (m > 1)
    ans *= m - 1;
  return ans;
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
  //assert(x != 0);
  return bin(x, ph - 1);
}

struct Sub {
  map<int, int> s;
  int a, b, ia;

  Sub():
    a(1),
    b(0),
    ia(1) { 
    s[0] = 1;
  }

  void apply(int A, int B) {
    a = mul(a, A);
    ia = inv(a);
    b = add(mul(A, b), B);
  }

  int get(int x) {
    x = sub(x, b);
    x = mul(x, ia);
    return s[x];
  }

  void norm() {
    map<int, int> nw;
    for (auto p : s) {
      int x = p.first;
      int y = p.second;
      nw[add(mul(x, a), b)] = y;
    }

    s = nw;
    a = 1;
    b = 0;
    ia = 1;
  }
};

struct Pair {
  Sub L, R;

  void upd(int d) {
    L.apply(10, mul(10, d));
    R.apply(i10, sub(0, d));
  }

  void norm() {
    L.norm();
    R.norm();
  }

  int sz() {
    return L.s.size();
  }
};

ll count(Sub &A, Sub &B) {
  ll ans = 0;

  for (auto p : B.s) {
    int x = p.first;
    int y = p.second;

    x = add(B.b, mul(B.a, x));

    ans += 1ll * y * A.get(x);
  }

  return ans;
}

void add(Sub &A, Sub &B) {
  for (auto p : B.s) {
    int x = p.first;
    int y = p.second;

    x = add(B.b, mul(B.a, x));
    
    x = sub(x, A.b);
    x = mul(x, A.ia);
    A.s[x] += y;
  }

}


Pair *merge(Pair *A, Pair *B) {
  if (A->sz() < B->sz())
    swap(A, B);

  B->norm();

  ans += count(A->L, B->R);
  ans += count(A->R, B->L);

  add(A->L, B->L);
  add(A->R, B->R);

  delete B;
  return A;
}

void read() {
  cin >> n >> mod;
  ph = phi(mod);
  i10 = inv(10);

  for (int i = 0; i < n - 1; ++i) {
    int x, y, d;
    cin >> x >> y >> d;

    g[x].push_back(y);
    g[y].push_back(x);

    h[x].push_back(d);
    h[y].push_back(d);
  }

}


Pair *dfs(int v) {
  used[v] = true;

  Pair *cur = new Pair;

  for (int i = 0; i < (int) g[v].size(); ++i) {
    int u = g[v][i];
    int d = h[v][i];

    if (used[u])
      continue;

    Pair *to = dfs(u);
    to->upd(d);

    cur = merge(cur, to);
  }

  return cur;
}


void kill() {
  int s = ROOT % n;
  delete dfs(s);
  cout << ans << endl;
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}