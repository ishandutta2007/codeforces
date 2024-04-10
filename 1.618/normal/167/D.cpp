/*


Q.E.D.

BULB: 30min.
result of thinking: Pure.

start coding: 15:40
AC: 17:10
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 100005
const int mod = 1000000009;
int n, k, m, x[maxn], y[maxn], a, b, c, d;

namespace fhqTreap {
  int chi[maxn][2], val[maxn], pri[maxn], f[maxn], V, root;
  // f[u]: u||.
  void init() {
    V = root = 0;
  }
  
  void up(int id) {
    int ls = chi[id][0], rs = chi[id][1];
    f[id] = f[ls] + f[rs];
    if (ls)
      chmax(f[id], f[chi[ls][0]] + f[chi[ls][1]] + f[rs] + 1);
    if (rs)
      chmax(f[id], f[ls] + f[chi[rs][0]] + f[chi[rs][1]] + 1);
  }
  
  void split(int id, int key, int &x, int &y) {
    if (!id) {
      x = y = 0;
    } else {
      if (val[id] <= key) {
        x = id;
        split(chi[x][1], key, chi[x][1], y);
      } else {
        y = id;
        split(chi[y][0], key, x, chi[y][0]);
      }
      up(id);
    }
  }
  
  int merge(int x, int y) {
    if (!x || !y)
      return x ^ y;
    if (pri[x] > pri[y]) {
      chi[x][1] = merge(chi[x][1], y);
      up(x);
      return x;
    } else {
      chi[y][0] = merge(x, chi[y][0]);
      up(y);
      return y;
    }
  }
  
  int newNode(int k, int p) {
    val[++V] = k;
    pri[V] = p;
    chi[V][0] = chi[V][1] = f[V] = 0;
    return V;
  }
  
  void insert(int k, int p) {
    int x, y;
    split(root, k, x, y);
    root = merge(merge(x, newNode(k, p)), y);
  }
  
  int query(int l, int r) {
    int x, y, z;
    split(root, r, y, z);
    split(y, l - 1, x, y);
    int res = f[y];
    root = merge(merge(x, y), z);
    return res;
  }
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= k; i++)
    scanf("%d%d", x + i, y + i);
  scanf("%d%d%d%d", &a, &b, &c, &d);
  for (int i = k + 1; i <= n; i++) {
    x[i] = ((ll)a * x[i - 1] + b) % mod;
    y[i] = ((ll)c * y[i - 1] + d) % mod;
  }
  fhqTreap::init();
  for (int i = 1; i <= n; i++)
    fhqTreap::insert(x[i], y[i]);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", fhqTreap::query(l, r));
  }
  return 0;
}