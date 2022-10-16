/*
 tourist 
authorAlex_Wei
powered by c++14
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
map<pair<int, int>, int> mp;
int n, q, fa[N << 1], sz[N << 1], ok[N << 2];
int find(int x) {return fa[x] == x ? x : find(fa[x]);}
vector<pair<int, int>> buc[N << 2];
void modify(int l, int r, int ql, int qr, int x, auto v) {
  if(ql <= l && r <= qr) return buc[x].push_back(v), void();
  int m = l + r >> 1;
  if(ql <= m) modify(l, m, ql, qr, x << 1, v);
  if(m < qr) modify(m + 1, r, ql, qr, x << 1 | 1, v);
}
void query(int l, int r, int x) {
  vector<int> op;
  for(auto it : buc[x]) {
    int a = find(it.first), b = find(it.second);
    int c = find(it.first + n), d = find(it.second + n);
    if(a == b) {ok[x] = 0, assert(c == d); continue;}
    auto merge = [&](int u, int v) {
      if(u == v) return;
      if(sz[u] < sz[v]) swap(u, v);
      fa[v] = u, sz[u] += sz[v], op.push_back(v);
    };
    merge(a, d), merge(b, c);
  }
  if(l == r) puts(ok[x] ? "YES" : "NO");
  else {
    int m = l + r >> 1;
    ok[x << 1] = ok[x << 1 | 1] = ok[x];
    query(l, m, x << 1), query(m + 1, r, x << 1 | 1);
  }
  reverse(op.begin(), op.end());
  for(int it : op) sz[fa[it]] -= sz[it], fa[it] = it;
}
int main() {
  // freopen("1.in", "r", stdin);
  cin >> n >> q;
  for(int i = 1; i <= n << 1; i++) fa[i] = i, sz[i] = 1;
  for(int i = 1; i <= q; i++) {
    pair<int, int> p;
    scanf("%d%d", &p.first, &p.second);
    auto it = mp.find(p);
    if(it == mp.end()) mp[p] = i;
    else modify(1, q, it -> second, i - 1, 1, p), mp.erase(it);
  }
  for(auto it : mp) modify(1, q, it.second, q, 1, it.first);
  ok[1] = 1, query(1, q, 1);
  return 0;
}
/*
2022/5/13
start coding at ??:??
finish debugging at ??:??
*/