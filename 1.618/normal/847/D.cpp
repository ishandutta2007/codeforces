/*


Q.E.D.

start thinking: 13:09
BULB: 13:20
result of thinking: Pure.

.

start coding: 13:30
AC:
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

#define maxn 200005
const int inf = 0x3f3f3f3f;

mt19937 rng;
namespace fhqTreap {
  int chi[maxn][2], val[maxn], pri[maxn], V, root, siz[maxn];
  
  void init() {
    V = root = 0;
  }
  
  void up(int id) {
    siz[id] = siz[chi[id][0]] + siz[chi[id][1]] + 1;
  }
  
  void split(int id, int k, int &x, int &y) { // by key.
    if (!id) {
      x = y = 0;
    } else {
      if (val[id] <= k) {
        x = id;
        split(chi[x][1], k, chi[x][1], y);
      } else {
        y = id;
        split(chi[y][0], k, x, chi[y][0]);
      }
      up(id);
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
  
  int newNode(int k) {
    val[++V] = k;
    siz[V] = 1;
    pri[V] = rng();
    return V;
  }
  
  void insert(int k) {
    int x, y;
    split(root, k, x, y);
    root = merge(merge(x, newNode(k)), y);
  }
  
  int rank(int k) { // <= k  
    int x, y;
    split(root, k, x, y);
    int res = siz[x];
    root = merge(x, y);
    return res;
  }
}

int n, T, t[maxn];

int main() {
  rng.seed(time(0));
  fhqTreap::init();
  int ans = 0;
  scanf("%d%d", &n, &T);
  for (int i = 1; i <= n && i < T; i++) {
    scanf("%d", t + i);
    fhqTreap::insert(t[i] - i);
    chmax(ans, fhqTreap::rank(T - i - 1));
  }
  printf("%d\n", ans);
  return 0;
}