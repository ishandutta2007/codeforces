#include <bits/stdc++.h>
using namespace std;
bool Mbe;
constexpr int N = 1e5 + 5;
constexpr int mod = 1e9 + 7;
constexpr int L = 5e5;
constexpr int K = L << 5;
int n, m, pw[N * 5], lg[N];
vector<pair<int, int>> e[N];
int node, ls[K], rs[K];
struct dat {
  int val, len;
  dat operator + (const dat &rhs) const {
    dat res = {rhs.val, len + rhs.len};
    res.val = (res.val + 1ll * val * pw[rhs.len]) % mod;
    return res;
  }
} val[K];
void modify(int pre, int &x, int l, int r, int ql, int qr, int v) {
  x = ++node, ls[x] = ls[pre], rs[x] = rs[pre];
  if(l == r) return val[x] = {v / pw[qr - l] % 10, 1}, void();
  int m = l + r >> 1;
  if(ql <= m) modify(ls[pre], ls[x], l, m, ql, qr, v);
  if(m < qr) modify(rs[pre], rs[x], m + 1, r, ql, qr, v);
  val[x] = val[ls[x]] + val[rs[x]];
}
dat query(int l, int r, int ql, int qr, int x) {
  if(!x || ql <= l && r <= qr) return val[x];
  int m = l + r >> 1;
  dat ans = {0, 0};
  if(ql <= m) ans = query(l, m, ql, qr, ls[x]);
  if(m < qr) ans = ans + query(m + 1, r, ql, qr, rs[x]);
  return ans;
}
int binary(int l, int r, int x, int y) {
  if(val[x].val == val[y].val) return -1;
  if(l == r) return l;
  int m = l + r >> 1;
  int res = binary(l, m, ls[x], ls[y]);
  if(res != -1) return res;
  return binary(m + 1, r, rs[x], rs[y]);
}
int querybit(int p, int x) {
  int l = 1, r = L;
  while(l != r) {
    int m = l + r >> 1;
    if(p <= m) r = m, x = ls[x];
    else l = m + 1, x = rs[x];
  }
  return val[x].val;
}
struct dist {
  int id, R, len;
  bool operator > (const dist &rhs) const {
    if(len != rhs.len) return len > rhs.len;
    int v = binary(1, L, R, rhs.R);
    if(v == -1) return 0;
    return querybit(v, R) > querybit(v, rhs.R);
  }
} dis[N];
priority_queue<dist, vector<dist>, greater<dist>> q;
bool Med;
int main() {
  fprintf(stderr, "%.4lf\n", (&Mbe - &Med) / 1048576.0);
#ifdef ALEX_WEI
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);
#endif
  cin >> n >> m;
  for(int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    e[x].push_back({y, i});
    e[y].push_back({x, i});
  }
  for(int i = 10; i <= m; i++) lg[i] = lg[i / 10] + 1;
  for(int i = pw[0] = 1; i <= 5 * n; i++) pw[i] = pw[i - 1] * 10ll % mod;
  q.push(dis[1] = {1, 0, 0});
  while(!q.empty()) {
    dist t = q.top();
    q.pop();
    int id = t.id, le = t.len;
    if(dis[id].R != t.R) continue;
    for(auto it : e[id]) {
      int tmpR, to = it.first, eid = it.second;
      modify(t.R, tmpR, 1, L, le + 1, le + lg[eid] + 1, eid);
      dist d = {to, tmpR, le + lg[eid] + 1};
      if(to != 1 && (!dis[to].R || dis[to] > d)) q.push(dis[to] = d);
    }
  }
  for(int i = 2; i <= n; i++) printf("%d\n", query(1, n, 1, dis[i].len, dis[i].R));
  return cerr << "Time: " << clock() << endl, 0;
}
/*
2022/6/17
start coding at 20:09
finish debugging at 21:00
*/