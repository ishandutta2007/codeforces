/*


Q.E.D.

BULB: Instant.
result of thinking: Pure.

start coding: 09:55
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

#define maxV 400005
int n, q, m;

mt19937 rng;
namespace fhqTreap {
  int chi[maxV][2], val[maxV], pri[maxV], siz[maxV], V, root;
  bool rev[maxV];
  
  void init() {
    V = root = 0;
  }
  
  void up(int id) {
    siz[id] = siz[chi[id][0]] + siz[chi[id][1]] + 1;
  }
  
  void down(int id) {
    if (rev[id]) {
      swap(chi[id][0], chi[id][1]);
      if (chi[id][0])
        rev[chi[id][0]] ^= 1;
      if (chi[id][1])
        rev[chi[id][1]] ^= 1;
      rev[id] ^= 1;
    }
  }
  
  void split(int id, int rk, int &x, int &y) {
    if (!id) {
      x = y = 0;
    } else {
      down(id);
      if (rk > siz[chi[id][0]]) {
        x = id;
        split(chi[x][1], rk - siz[chi[id][0]] - 1, chi[x][1], y);
      } else {
        y = id;
        split(chi[y][0], rk, x, chi[y][0]);
      }
      up(id);
    }
  }
  
  int merge(int x, int y) {
    if (!x || !y)
      return x ^ y;
    if (pri[x] < pri[y]) {
      down(x);
      chi[x][1] = merge(chi[x][1], y);
      up(x);
      return x;
    } else {
      down(y);
      chi[y][0] = merge(x, chi[y][0]);
      up(y);
      return y;
    }
  }
  
  int kth(int id, int k) {
    down(id);
    int lefSiz = siz[chi[id][0]];
    return k == lefSiz + 1 ? val[id] : (k <= lefSiz ?
           kth(chi[id][0], k) : kth(chi[id][1], k - lefSiz - 1));
  }
  
  int newNode(int va) {
    val[++V] = va;
    pri[V] = rng();
    siz[V] = 1;
    chi[V][0] = chi[V][1] = rev[V] = 0;
    return V;
  }
  
  void insert(int pos, int va) { // pos 
    int x, y;
    split(root, pos, x, y);
    root = merge(merge(x, newNode(va)), y);
  }
  
  int remove(int pos) { // return val(the_removed)
    int x, y, z;
    split(root, pos, y, z);
    split(y, pos - 1, x, y);
    root = merge(x, z);
    return val[y];
  }
  
  void reverse(int l, int r) {
    int x, y, z;
    split(root, r, y, z);
    split(y, l - 1, x, y);
    rev[y] ^= 1;
    root = merge(merge(x, y), z);
  }
}

int main() {
  rng.seed(time(0));
  scanf("%d%d%d", &n, &q, &m);
  fhqTreap::init();
  for (int i = 1; i <= n; i++) {
    int a;
    scanf("%d", &a);
    fhqTreap::insert(i - 1, a);
  }
  for (int i = 1; i <= q; i++) {
    int t, l, r;
    scanf("%d%d%d", &t, &l, &r);
    if (t == 1) {
      int tmp = fhqTreap::remove(r);
      fhqTreap::insert(l - 1, tmp);
    } else {
      fhqTreap::reverse(l, r);
    }
  }
  for (int i = 1; i <= m; i++) {
    int b;
    scanf("%d", &b);
    printf("%d ", fhqTreap::kth(fhqTreap::root, b));
  }
  puts("");
  return 0;
}