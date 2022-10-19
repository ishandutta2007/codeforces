#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 1e6 + 10; //CORLKAjdsfas
const int mod = 1e9 + 7;

int add(int x, int y) {
  x += y;
  if (x >= mod)
    x -= mod;
  return x;
}

int sub(int x, int y) {
  return add(x, mod - y);
}

int mul(ll x, ll y) {
  return x * y % mod;
}

int inv[M];
int ifc[M];
int phi[M];
int b[M], c[M];
int sum = 0;
int n, k, q;
vector<int> a[M];

void pre() {
  inv[1] = 1;
  for (int i = 2; i < M; ++i) {
    inv[i] = mul(sub(0, mod / i), inv[mod % i]);
    assert(mul(i, inv[i]) == 1);
  }

  ifc[0] = 1;
  for (int i = 1; i < M; ++i) {
    ifc[i] = mul(inv[i], ifc[i - 1]);
  }

  for (int i = 1; i < M; ++i)
    phi[i] = i;

  for (int i = 1; i < M; ++i)
    for (int j = i; j < M; j += i) {
      a[j].push_back(i);
      if (j > i)
        phi[j] -= phi[i];
    }

  int mx = 0;
  for (int i = 0; i < M; ++i)
    mx = max(mx, (int) a[i].size());

  //cerr << mx << endl;
}

void updc(int at, int x) {
  sum = sub(sum, mul(c[at], phi[at]));
  c[at] = x;
  sum = add(sum, mul(c[at], phi[at]));
}

void add(int x) {
  ++b[x];
  if (b[x] == k) {
    updc(x, 1);
  } else if (b[x] > k) {
    int y = c[x];
    y = mul(y, b[x]);
    y = mul(y, inv[b[x] - k]);
    updc(x, y);
  }
}

void push(int x) {
  for (int d : a[x])
    add(d);
}

void read() {
  cin >> n >> k >> q;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    push(x);
  }
}


void kill() {
  for (int i = 0; i < q; ++i) {
    int x;
    cin >> x;
    push(x);
    cout << sum << endl;
  } 
}

int main() {
  ios_base::sync_with_stdio(false);
  pre();
  read();
  kill();
}