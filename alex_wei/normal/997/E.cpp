#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool Mbe;
constexpr int N = 1.2e5 + 5;
ll ans[N];
int n, q, p[N], l[N];
vector<int> buc[N];
struct tag {
  int hmin, num, cur;
  tag operator + (const tag &rhs) const {
    tag res = {min(hmin, cur + rhs.hmin), 0, cur + rhs.cur};
    if(hmin == res.hmin) res.num += num;
    if(cur + rhs.hmin == res.hmin) res.num += rhs.num;
    return res;
  }
} laz[N << 2];
struct dat {
  int mn, num;
  ll ans;
  dat operator + (const dat &rhs) const {
    dat res = {min(mn, rhs.mn), 0, ans + rhs.ans};
    if(mn == res.mn) res.num += num;
    if(rhs.mn == res.mn) res.num += rhs.num;
    return res;
  }
  dat operator + (const tag &rhs) const {
    dat res = {mn + rhs.cur, num, ans};
    if(!(mn + rhs.hmin)) res.ans += 1ll * rhs.num * num;
    return res;
  }
} val[N << 2];
void tag(int x, tag v) {
  val[x] = val[x] + v;
  if(laz[x].num == -1) laz[x] = v;
  else laz[x] = laz[x] + v;
}
void down(int x) {
  if(laz[x].num != -1) {
    tag(x << 1, laz[x]);
    tag(x << 1 | 1, laz[x]);
    laz[x].num = -1;
  }
}
void build(int l, int r, int x) {
  if(l == r) return val[x] = {0, 1, 1}, void();
  int m = l + r >> 1;
  build(l, m, x << 1), build(m + 1, r, x << 1 | 1);
  val[x] = val[x << 1] + val[x << 1 | 1];
}
void modify(int l, int r, int ql, int qr, int x, int v) {
  if(ql > qr) return;
  if(ql <= l && r <= qr) return tag(x, {v, 1, v});
  int m = l + r >> 1;
  down(x);
  if(ql <= m) modify(l, m, ql, qr, x << 1, v);
  if(m < qr) modify(m + 1, r, ql, qr, x << 1 | 1, v);
  val[x] = val[x << 1] + val[x << 1 | 1];
}
ll query(int l, int r, int ql, int qr, int x) {
  if(ql <= l && r <= qr) return val[x].ans;
  int m = l + r >> 1;
  ll ans = 0;
  down(x);
  if(ql <= m) ans = query(l, m, ql, qr, x << 1);
  if(m < qr) ans += query(m + 1, r, ql, qr, x << 1 | 1);
  return ans;
}
bool Med;
int main() {
  fprintf(stderr, "%.4lf\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
  #endif
  ios::sync_with_stdio(0);
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> p[i];
  build(1, n, 1);
  cin >> q;
  for(int i = 1; i <= q; i++) {
    int r;
    cin >> l[i] >> r;
    buc[r].push_back(i);
  }
  static int mns[N], mnt, mxs[N], mxt;
  mns[mnt = 1] = mxs[mxt = 1] = 0;
  for(int i = 1; i <= n; i++) {
    while(mnt > 1 && p[mns[mnt]] > p[i]) {
      modify(1, n, mns[mnt - 1] + 1, mns[mnt], 1, p[mns[mnt]] - p[i]);
      mnt--;
    }
    while(mxt > 1 && p[mxs[mxt]] < p[i]) {
      modify(1, n, mxs[mxt - 1] + 1, mxs[mxt], 1, p[i] - p[mxs[mxt]]);
      mxt--;
    }
    modify(1, n, 1, i - 1, 1, -1);
    mns[++mnt] = mxs[++mxt] = i;
    for(int it : buc[i]) ans[it] = query(1, n, l[it], i, 1);
  }
  for(int i = 1; i <= q; i++) cout << ans[i] << "\n";
  return cerr << "Time: " << clock() << "\n", 0;
}
/*
2022/7/8
start coding at 19:52
finish debugging at 21:14
*/