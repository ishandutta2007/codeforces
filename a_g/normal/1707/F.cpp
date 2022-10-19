#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;
const int K = __lg(N);
int c[N], s[2<<K], f[2<<K], rev[1<<K], bad[2<<K];
int tot, tot_bad, P, t;

int expmod(long long a, long long b, int m) {
  int ans = 1;
  a %= m;
  while (b) {
    if (b&1) ans = 1LL*ans*a % m;
    b >>= 1;
    a = 1LL*a*a % m;
  }
  return ans;
}

void merge(int v) {
  tot_bad -= bad[v];
  if (v == 1 && f[v]) tot--;
  if ((t>>__lg(v))&1) {
    // constraint: s[2*v] == s[2*v+1]
    f[v] = (f[2*v] > 0 && f[2*v+1] > 0);
    bad[v] = (f[2*v] == 0 && f[2*v+1] == 0 && s[2*v] != s[2*v+1]);
    if (f[2*v] == 0) s[v] = s[2*v];
    else s[v] = s[2*v+1];
  }
  else {
    // s[v] = s[2*v]^s[2*v+1]
    tot -= (f[v] == 2);
    f[v] = (f[2*v] > 0)+(f[2*v+1] > 0);
    s[v] = (f[v] ? 0 : s[2*v]^s[2*v+1]);
    tot += (f[v] == 2);
  }
  if (v == 1 && f[v]) tot++;
  tot_bad += bad[v];
}

void upd(int i, int x) {
  int v = P+rev[i&(P-1)];
  tot -= max(f[v]-1, 0);
  tot_bad -= bad[v];
  s[v] ^= (x == -1 ? 0 : x)^(c[i] == -1 ? 0 : c[i]);
  f[v] += (x == -1)-(c[i] == -1);
  c[i] = x;
  bad[v] = (t == P && f[v] == 0 && s[v] != 0);
  tot_bad += bad[v];
  tot += max(f[v]-1, 0);

  if (t != P) {
    v >>= 1;
    while (v) {
      merge(v);
      v >>= 1;
    }
  }
}

void debug() {
  for (int v = 1; v < 2*P; v++) {
    cout << v << " " << s[v] << " " << f[v] << " " << bad[v] << endl;
  }
  cout << tot_bad << " " << tot << endl;
  cout << endl;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m, w;
  cin >> n >> m >> t >> w;
  P = 1<<__builtin_ctz(n);
  for (int i = 0; i < P; i++) {
    rev[i] = rev[i>>1]>>1;
    if (i&1) rev[i] |= P>>1;
  }
  t = min(t, P);

  fill(c, c+n, -1);
  fill(f+P, f+2*P, n/P);
  tot = P*(n/P-1);
  if (t != P) {
    for (int v = P-1; v >= 1; v--) {
      merge(v);
    }
  }

  while (m--) {
    int i, x;
    cin >> i >> x;
    upd(i-1, x);
  }

  const int base = 1<<w;
  int q;
  cin >> q;
  while (q--) {
    int i, x, p;
    cin >> i >> x >> p;
    upd(i-1, x);
    cout << (tot_bad ? 0 : expmod(base, tot, p)) << '\n';
  }
}