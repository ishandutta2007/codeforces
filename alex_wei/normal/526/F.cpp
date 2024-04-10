#include <bits/stdc++.h>
using namespace std;
bool Mbe;
constexpr int N = 3e5 + 5;
long long ans;
int n, p[N], laz[N << 2];
struct dat {
  int mn, num;
  dat operator + (const dat &rhs) const {
    dat res = {min(mn, rhs.mn), 0};
    if(mn == res.mn) res.num += num;
    if(rhs.mn == res.mn) res.num += rhs.num;
    return res;
  }
} val[N << 2];
void tag(int x, int v) {val[x].mn += v, laz[x] += v;}
void down(int x) {
  if(laz[x]) {
    tag(x << 1, laz[x]);
    tag(x << 1 | 1, laz[x]);
    laz[x] = 0;
  }
}
void build(int l, int r, int x) {
  val[x] = {0, r - l + 1};
  if(l == r) return;
  int m = l + r >> 1;
  build(l, m, x << 1), build(m + 1, r, x << 1 | 1);
}
void modify(int l, int r, int ql, int qr, int x, int v) {
  if(ql > qr) return;
  if(ql <= l && r <= qr) return tag(x, v);
  int m = l + r >> 1;
  down(x);
  if(ql <= m) modify(l, m, ql, qr, x << 1, v);
  if(m < qr) modify(m + 1, r, ql, qr, x << 1 | 1, v);
  val[x] = val[x << 1] + val[x << 1 | 1];
}
dat query(int l, int r, int ql, int qr, int x) {
  if(ql <= l && r <= qr) return val[x];
  int m = l + r >> 1;
  down(x);
  dat ans = {N, 1};
  if(ql <= m) ans = query(l, m, ql, qr, x << 1);
  if(m < qr) ans = ans + query(m + 1, r, ql, qr, x << 1 | 1);
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
  for(int i = 1; i <= n; i++) {
    int r, c;
    cin >> r >> c, p[r] = c;
  }
  build(1, n, 1);
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
    mns[++mnt] = mxs[++mxt] = i;
    modify(1, n, 1, i - 1, 1, -1);
    dat res = query(1, n, 1, i, 1);
    if(!res.mn) ans += res.num;
  }
  cout << ans << endl;
  return cerr << "Time: " << clock() << "\n", 0;
}
/*
2022/7/8
start coding at 15:59
finish debugging at 16:13
*/