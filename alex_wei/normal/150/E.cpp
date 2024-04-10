#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
using pii = pair<int, int>;
bool Mbe;
constexpr int N = 1e5 + 5;
int n, V, L, R;
int x, y, found;
int rt, mx[N], vis[N], sz[N];
int cnt, hd[N], nxt[N << 1], to[N << 1], val[N << 1];
void add(int u, int v, int w) {nxt[++cnt] = hd[u], hd[u] = cnt, to[cnt] = v, val[cnt] = w;}
void findroot(int id, int ff, int tot) {
  mx[id] = sz[id] = 1;
  for(int i = hd[id]; i; i = nxt[i]) {
    int it = to[i];
    if(vis[it] || it == ff) continue;
    findroot(it, id, tot);
    sz[id] += sz[it];
    mx[id] = max(mx[id], sz[it]); 
  }
  mx[id] = max(mx[id], tot - sz[id]);
  if(mx[id] < mx[rt]) rt = id;
}
int mxd[N], f[N], f2[N], ind[N], ind2[N];
void finddep(int id, int ff) {
  mxd[id] = 1;
  for(int i = hd[id]; i; i = nxt[i]) {
    int it = to[i];
    if(vis[it] || it == ff) continue;
    finddep(it, id);
    mxd[id] = max(mxd[id], mxd[it] + 1);
  }
}
void findval(int id, int ff, int dep, int val) {
  if(f2[dep] < val) f2[dep] = val, ind2[dep] = id;
  for(int i = hd[id]; i; i = nxt[i]) {
    int it = to[i];
    if(vis[it] || it == ff) continue;
    findval(it, id, dep + 1, val + (::val[i] >= V ? 1 : -1));
  }
}
void divide(int id) {
  vis[id] = 1;
  ind[0] = id;
  finddep(id, 0);
  vector<pii> son;
  for(int i = hd[id]; i; i = nxt[i]) son.push_back({to[i], val[i]});
  sort(son.begin(), son.end(), [&](pii a, pii b) {return mxd[a.first] < mxd[b.first];});
  int limit = 0;
  for(pii _ : son) {
    int it = _.first;
    if(vis[it]) continue;
    if(found) break;
    findval(it, id, 1, _.second >= V ? 1 : -1);
    int cur = min(R, limit);
    static int d[N];
    int hd = 1, tl = 0;
    auto push = [&](int p) {
      while(hd <= tl && f[d[tl]] <= f[p]) tl--;
      d[++tl] = p;
    };
    for(int i = 1; i <= mxd[it]; i++) {
      while(cur >= 0 && cur + i >= L) push(cur--);
      while(hd <= tl && d[hd] + i > R) hd++;
      if(hd <= tl) {
        int val = f[d[hd]] + f2[i];
        if(val >= 0) found = 1, x = ind[d[hd]], y = ind2[i];
      }
    }
    for(int i = 1; i <= mxd[it]; i++) {
      if(f2[i] > f[i]) f[i] = f2[i], ind[i] = ind2[i];
      f2[i] = -1e9;
    }
    limit = mxd[it];
  }
  for(int i = 1; i <= mxd[id]; i++) f[i] = -1e9;
  if(found) return;
  for(int i = hd[id]; i; i = nxt[i]) {
    int it = to[i];
    if(found) return;
    if(vis[it]) continue;
    rt = 0, findroot(it, id, sz[it]);
    divide(rt);
  }
}
bool check(int mid) {
  V = mid, found = 0;
  memset(vis, 0, sizeof(vis));
  rt = 0, findroot(1, 0, n);
  divide(rt);
  // cout << mid << " " << found << endl;
  return found;
}
bool Med;
int main() {
  fprintf(stderr, "%.4lf\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
  #endif
  memset(f, 0xcf, sizeof(f)), f[0] = 0;
  memset(f2, 0xcf, sizeof(f2));
  mx[0] = N;
  ios::sync_with_stdio(0);
  cin >> n >> L >> R;
  static int w[N], cnt = 0;
  for(int i = 1; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    add(a, b, c);
    add(b, a, c);
    w[++cnt] = c;
  }
  sort(w + 1, w + cnt + 1);
  int l = 1, r = cnt;
  while(l < r) {
    int m = l + r + 2 >> 1;
    if(check(w[m])) l = m;
    else r = m - 1;
  }
  check(w[l]), cout << x << " " << y << "\n";
  return cerr << "Time: " << clock() << "\n", 0;
}
/*
2022/7/10
start coding at 14:03
finish debugging at 15:12
*/