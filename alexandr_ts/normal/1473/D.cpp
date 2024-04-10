#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

struct S {
  int mn, mx, sum;

  void print() {
    cout << "mn: " << mn << ", mx: " << mx << ", sum: " << sum << endl;
  }
} t[N];

S get_sum(const S& a, const S& b) {
  return {
    max(a.mn, -a.sum + b.mn),
    max(a.mx, a.sum + b.mx),
    a.sum + b.sum
  };
}

void recalc(int v) {
  t[v] = get_sum(t[2 * v], t[2 * v + 1]);
}

void build(int v, int tl, int tr, const string& s) {
  if (tl == tr) {
    t[v].mn = t[v].mx = t[v].sum = 0;
    if (s[tl] == '-') {
      t[v].mn = 1;
      t[v].sum = -1;
    } else {
      t[v].mx = 1;
      t[v].sum = 1;
    }
    return;
  }

  int tm = (tl + tr) / 2;
  build(2 * v, tl, tm, s);
  build(2 * v + 1, tm + 1, tr, s);
  recalc(v);
}

S get(int v, int tl, int tr, int l, int r) {
  if (l > tr || tl > r) {
    return {0, 0, 0};
  }
  if (l <= tl && tr <= r) {
    return t[v];
  }
  int tm = (tl + tr) / 2;
  auto v1 = get(2 * v, tl, tm, l, r);
  auto v2 = get(2 * v + 1, tm + 1, tr, l, r);
  return get_sum(v1, v2);
}

void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  build(1, 0, n - 1, s);

  while (m--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    auto v1 = get(1, 0, n - 1, 0, l - 1);
    auto v2 = get(1, 0, n - 1, r + 1, n - 1);
    //v1.print();
    //v2.print();
    auto res = get_sum(v1, v2);
    cout << 1 + res.mn + res.mx << "\n";
  }
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
  cin >> t;
	while (t--) {
		solve();
	}
}