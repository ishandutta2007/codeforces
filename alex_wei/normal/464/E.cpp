#include <bits/stdc++.h>
using namespace std;
bool Mbe;
constexpr int N = 1e5 + 50;
constexpr int K = N * 57;
constexpr int mod = 1e9 + 7;
int n, m, pw[N];
int cnt, ls[K], rs[K], num[K], val[K];
void cpy(int &x, int y) {val[x = ++cnt] = val[y], num[x] = num[y], ls[x] = ls[y], rs[x] = rs[y];}
void push(int x) {num[x] = num[ls[x]] + num[rs[x]], val[x] = (val[ls[x]] + val[rs[x]]) % mod;}
void modify(int pre, int &x, int l, int r, int ql, int qr) {
  cpy(x, pre);
  if(ql <= l && r <= qr) return x = 0, void();
  int m = l + r >> 1;
  if(ql <= m) modify(ls[pre], ls[x], l, m, ql, qr);
  if(m < qr) modify(rs[pre], rs[x], m + 1, r, ql, qr);
  push(x);
}
void insert(int pre, int &x, int l, int r, int p) {
  cpy(x, pre);
  if(l == r) return num[x] = 1, val[x] = pw[p], void();
  int m = l + r >> 1;
  if(p <= m) insert(ls[pre], ls[x], l, m, p);
  else insert(rs[pre], rs[x], m + 1, r, p);
  push(x);
}
int query(int l, int r, int p, int x) {
  if(num[x] == r - l + 1) return -1;
  if(l == r) return l;
  int m = l + r >> 1;
  if(p <= m) {
    int res = query(l, m, p, ls[x]);
    if(res != -1) return res;
  }
  return query(m + 1, r, p, rs[x]);
}
bool larger(int x, int y) {
  if(val[x] == val[y]) return 0;
  int l = 1, r = N;
  while(l < r) {
    int m = l + r >> 1;
    if(val[rs[x]] ^ val[rs[y]]) l = m + 1, x = rs[x], y = rs[y];
    else r = m, x = ls[x], y = ls[y];
  }
  return num[x];
}
struct node {
  int R, id;
  bool operator < (const node &rhs) const {return larger(R, rhs.R);}
};
vector<pair<int, int>> e[N];
int st, ed, pre[N], dis[N];
bool Med;
int main() {
  fprintf(stderr, "%.4lf\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
  #endif
  ios::sync_with_stdio(0);
  cin >> n >> m;
  for(int i = pw[0] = 1; i < N; i++) pw[i] = pw[i - 1] * 2 % mod;
  for(int i = 1; i <= m; i++) {
    int u, v, x;
    cin >> u >> v >> x;
    e[u].push_back({v, x});
    e[v].push_back({u, x});
  }
  cin >> st >> ed;
  priority_queue<node> q;
  q.push({0, st});
  while(!q.empty()) {
    node t = q.top();
    q.pop();
    int id = t.id, R = t.R;
    if(dis[id] != R) continue;
    if(t.id == ed) {
      cout << val[R] << "\n";
      vector<int> ans;
      int cur = ed;
      while(cur != st) ans.push_back(cur), cur = pre[cur];
      ans.push_back(st);
      reverse(ans.begin(), ans.end());
      cout << ans.size() << "\n";
      for(int it : ans) cout << it << " ";
      cout << "\n", exit(0);
    }
    for(auto _ : e[id]) {
      int it = _.first, x = _.second;
      int p = query(0, N, x, R), nR = R;
      if(x < p) modify(nR, nR, 0, N, x, p - 1);
      insert(nR, nR, 0, N, p);
      if(!dis[it] || larger(dis[it], nR)) pre[it] = id, q.push({dis[it] = nR, it});
    }
  }
  cout << "-1\n";
  return cerr << "Time: " << clock() << "\n", 0;
}
/*
2022/7/9
start coding at 9:29
finish debugging at 10:04
*/