#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
using pii = pair<int, int>;
bool Mbe;
constexpr int N = 2e5 + 5;
int n, fa[N], l[N], r[N], d[N], cnt;
int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
int op[N], x[N], y[N];
vector<int> buc[N];
multiset<int> S[N]; // set -> multiset
pii val[N << 2];
void modify(int l, int r, int p, int x, int v) {
  if(l == r) {
    if(v > 0) S[p].insert(v);
    else S[p].erase(S[p].find(-v)); // v -> -v
    val[x] = {S[p].empty() ? N : *S[p].begin(), p};
    return;
  }
  int m = l + r >> 1;
  if(p <= m) modify(l, m, p, x << 1, v);
  else modify(m + 1, r, p, x << 1 | 1, v);
  val[x] = min(val[x << 1], val[x << 1 | 1]);
}
pii query(int l, int r, int ql, int qr, int x) {
  if(ql <= l && r <= qr) return val[x];
  int m = l + r >> 1;
  pii ans = {N, N};
  if(ql > qr) return ans;
  if(ql <= m) ans = min(ans, query(l, m, ql, qr, x << 1));
  if(m < qr) ans = min(ans, query(m + 1, r, ql, qr, x << 1 | 1));
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
  memset(val, 0x3f, sizeof(val));
  cin >> n;
  for(int i = 1, qu = 0; i <= n; i++) {
    cin >> op[i] >> x[i] >> y[i];
    if(op[i] == 1) d[++cnt] = x[i], d[++cnt] = y[i];
  }
  sort(d + 1, d + cnt + 1);
  cnt = unique(d + 1, d + cnt + 1) - d - 1;
  map<pii, int> mp;
  for(int _ = 1, id = 0, cid = 0; _ <= n; _++) {
    if(op[_] == 1) {
      id++, fa[id] = id;
      int l = lower_bound(d + 1, d + cnt + 1, x[_]) - d;
      int r = lower_bound(d + 1, d + cnt + 1, y[_]) - d;
      ::l[id] = l, ::r[id] = r;
      auto deal = [&](pii res) {
        modify(1, cnt, res.se, 1, -res.fi);
        auto it = mp.find(res);
        assert(it != mp.end());
        for(int p : buc[it->se]) {
          assert(fa[p] == p);
          fa[p] = id;
          ::l[id] = min(::l[id], ::l[p]);
          ::r[id] = max(::r[id], ::r[p]);
        }
        mp.erase(it);
      };
      while(1) {
        pii res = query(1, cnt, r + 1, cnt, 1);
        if(res.fi < r) deal(res);
        else break;
      }
      while(1) {
        pii res = query(1, cnt, l + 1, r, 1);
        if(res.fi < l) deal(res);
        else break;
      }
      l = ::l[id], r = ::r[id];
      modify(1, cnt, r, 1, l);
      if(mp.find({l, r}) == mp.end()) mp[{l, r}] = ++cid;
      buc[mp[{l, r}]].push_back(id);
    }
    else {
      int a = find(x[_]), b = find(y[_]);
      if(a == b) puts("YES");
      else if(r[a] <= l[b] || r[b] <= l[a]) puts("NO");
      else if(l[a] == l[b] && r[a] == r[b]) puts(a < b ? "YES" : "NO");
      else if(r[a] - l[a] < r[b] - l[b]) puts("YES"); // > -> <
      else puts("NO");
    }
  }
  return cerr << "Time: " << clock() << "\n", 0;
}
/*
2022/7/10
start coding at 16:05
finish debugging at 17:10
*/