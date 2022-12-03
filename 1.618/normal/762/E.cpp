/*


Q.E.D.

 Implicit Trees.

start coding: 15:10
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

#define maxf 10005
#define maxn 100005
mt19937 rng;
int chi[maxn][2], siz[maxn], pri[maxn], val[maxn], V;

struct fhqTreap {
  int root;
  
  fhqTreap() {
    root = 0;
  }
  
  void up(int id) {
    siz[id] = siz[chi[id][0]] + siz[chi[id][1]] + 1;
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
  
  int newNode(int key) {
    val[++V] = key;
    pri[V] = rng();
    siz[V] = 1;
    chi[V][0] = chi[V][1] = 0;
    return V;
  }
  
  void insert(int key) {
    int x, y;
    split(root, key, x, y);
    root = merge(merge(x, newNode(key)), y);
  }
  
  void remove(int key) {
    int x, y, z;
    split(root, key - 1, x, y);
    split(y, key, y, z);
    root = merge(merge(x, merge(chi[y][0], chi[y][1])), z);
  }
  
  int rank(int key) { // [<x] + 1
    int x, y;
    split(root, key - 1, x, y);
    int res = siz[x] + 1;
    root = merge(x, y);
    return res;
  }
} tr[maxf];

int n, k;
struct Station {
  int x, r, f;
  bool operator < (const Station &b) const {
    return x < b.x;
  }
} a[maxn];

#define mp make_pair
typedef pair<int, int> P;
set<P> S;

int main() {
  rng.seed(time(0));
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &a[i].x, &a[i].r, &a[i].f);
  }
  sort(a + 1, a + n + 1);
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    while (S.size() && S.begin()->first < a[i].x) {
      int j = S.begin()->second;
      tr[a[j].f].remove(a[j].x);
      S.erase(S.begin());
    }
    for (int j = max(a[i].f - k, 1); j <= min(a[i].f + k, 10000); j++) {
      ans += siz[tr[j].root] - tr[j].rank(a[i].x - a[i].r) + 1;
    }
    S.insert(mp(a[i].x + a[i].r, i));
    tr[a[i].f].insert(a[i].x);
  }
  printf("%lld\n", ans);
  return 0;
}