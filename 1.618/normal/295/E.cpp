/*


Q.E.D.

BULB: Instant.
result of thinking: Pure.

#.
 
start coding:
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

#define maxV 200005
mt19937 rng;
namespace fhqTreap {
  int chi[maxV][2], val[maxV], pri[maxV], siz[maxV], V, root;
  ll sum[maxV], ans[maxV];
  
  void up(int id) {
    int ls = chi[id][0], rs = chi[id][1];
    siz[id] = siz[ls] + siz[rs] + 1;
    sum[id] = sum[ls] + sum[rs] + val[id];
    ans[id] = ans[ls] + ans[rs] + siz[ls] * (sum[rs] + val[id])
              - siz[rs] * (sum[ls] + val[id]) + sum[rs] - sum[ls];
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
  
  int newNode(int va) {
    val[++V] = va;
    pri[V] = rng();
    siz[V] = 1;
    sum[V] = va;
    return V;
  }
  
  void insert(int va) {
    int x, y;
    split(root, va, x, y);
    root = merge(merge(x, newNode(va)), y);
  }
  
  void remove(int va) {
    int x, y, z;
    split(root, va, y, z);
    split(y, va - 1, x, y);
    root = merge(x, z);
  }
  
  ll query(int l, int r) {
    int x, y, z;
    split(root, r, y, z);
    split(y, l - 1, x, y);
    ll res = ans[y];
    root = merge(merge(x, y), z);
    return res;
  }
}

#define maxn 100005
int n, x[maxn], m;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", x + i);
    fhqTreap::insert(x[i]);
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    int t, foo, bar;
    scanf("%d%d%d", &t, &foo, &bar);
    if (t == 1) {
      fhqTreap::remove(x[foo]);
      x[foo] += bar;
      fhqTreap::insert(x[foo]);
    } else {
      printf("%lld\n", fhqTreap::query(foo, bar));
    }
  }
  return 0;
}