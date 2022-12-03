/*
start thinking:
BULB:
result of thinking:

start coding:
AC:
*/
#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template <class T1, class T2> bool chmin(T1 &x, const T2 &y) {
  return x > y ? (x = y, true) : false;
}
template <class T1, class T2> bool chmax(T1 &x, const T2 &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 500005
mt19937 rng;
int n, a[maxn];
ll s[maxn];

namespace Treap {
  int chi[maxn][2], pri[maxn], val[maxn], maxi[maxn], V, root;
  ll key[maxn];

  void init() {
    root = V = 0;
    maxi[0] = -inf;
  }

  void up(int u) {
    maxi[u] = val[u];
    if (chi[u][0])
      chmax(maxi[u], maxi[chi[u][0]]);
    if (chi[u][1])
      chmax(maxi[u], maxi[chi[u][1]]);
  }

  // key < k, key >= k.
  void split(int u, ll k, int &x, int &y) {
    if (!u) {
      x = y = 0;
      return;
    }
    if (key[u] < k) {
      x = u;
      split(chi[u][1], k, chi[x][1], y);
      up(x);
    } else {
      y = u;
      split(chi[u][0], k, x, chi[y][0]);
      up(y);
    }
  }

  int merge(int x, int y) {
    if (!x || !y)
      return x ^ y;
    if (pri[x] < pri[y]) {
      chi[x][1] = merge(chi[x][1], y);
      up(x);
      return x;
    } else {
      chi[y][0] = merge(x, chi[y][0]);
      up(y);
      return y;
    }
  }

  int newNode(ll _key, int _val) {
    pri[++V] = rng();
    key[V] = _key;
    maxi[V] = val[V] = _val;
    chi[V][0] = chi[V][1] = 0;
    return V;
  }

  void insert(ll _key, int _val) {
    int x, y;
    split(root, _key, x, y);
    root = merge(merge(x, newNode(_key, _val)), y);
  }

  int qmax(ll _key) {
    int x, y;
    split(root, _key, x, y);
    auto ret = maxi[x];
    root = merge(x, y);
    return ret;
  }
}

map<ll, int> eq;
int f[maxn];

void solve() {
  Treap::init();
  eq.clear();
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    s[i] = s[i - 1] + a[i];
  }
  Treap::insert(s[0], 0);
  chmax(eq[0], 0);
  for (int i = 1; i <= n; i++) {
    f[i] = max(f[i - 1] - 1, Treap::qmax(s[i]) + i);

    // cout << f[i] << endl;
    // system("pause");

    if (eq.count(s[i]))
      chmax(f[i], eq[s[i]]);
    else
      eq[s[i]] = -inf;
    Treap::insert(s[i], f[i] - i);
    chmax(eq[s[i]], f[i]);

    // cout << f[i] << endl;
    // system("pause");

  }

  // cout << endl;
  // system("pause");

  printf("%d\n", f[n]);
}

bool Med;
int main() {
  rng.seed(time(0));
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}
/*
1
4
-1 0 0 0
*/