#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
bool Mbe;
constexpr int coef = 1e7 + 19;
constexpr int mod = 1e9 + 7;
constexpr int N = 3e4 + 5;
constexpr int K = 1e3 + 5;
void cmax(int &x, int y) {x = x > y ? x : y;}
int n, k, q, type[N], mp[N];
struct knapsack {
  int f[K];
  void add(int w, int v) {for(int i = k; i >= w; i--) cmax(f[i], f[i - w] + v);}
  int calc() {
    int ans = 0;
    for(int i = k; i; i--) {
      // cout << i << " " << f[i] << endl;
      ans = (1ll * ans * coef + f[i]) % mod;
    }
    return ans;
  }
} w[15];
pii item[N]; // make_pair(weight, value)
vector<pii> buc[N << 2];
void modify(int l, int r, int ql, int qr, int x, const pii &v) {
  if(ql > qr) return; // add this line
  if(ql <= l && r <= qr) return buc[x].push_back(v), void();
  int m = l + r >> 1;
  if(ql <= m) modify(l, m, ql, qr, x << 1, v);
  if(m < qr) modify(m + 1, r, ql, qr, x << 1 | 1, v);
}
void query(int l, int r, int x, int dep) {
  w[dep] = w[dep - 1];
  for(auto it : buc[x]) w[dep].add(it.first, it.second);
  if(l == r) {
    if(type[l] == 3) printf("%d\n", w[dep].calc());
  }
  else {
    int m = l + r >> 1;
    query(l, m, x << 1, dep + 1);
    query(m + 1, r, x << 1 | 1, dep + 1);
  }
}
bool Med;
int main() {
  fprintf(stderr, "%.4lf\n", (&Mbe - &Med) / 1048576.0);
#ifdef ALEX_WEI
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);
#endif
  cin >> n >> k;
  for(int i = 1; i <= n; i++)
    cin >> item[i].second >> item[i].first, mp[i] = 1;
  cin >> q;
  int tot = n;
  for(int i = 1; i <= q; i++) {
    cin >> type[i];
    if(type[i] == 1) {
      mp[++tot] = i;
      cin >> item[tot].second >> item[tot].first;
    }
    if(type[i] == 2) {
      int id;
      cin >> id;
      modify(1, q, mp[id], i - 1, 1, item[id]);
      mp[id] = 0;
    }
  }
  for(int i = 1; i <= tot; i++)
    if(mp[i])
      modify(1, q, mp[i], q, 1, item[i]);
  query(1, q, 1, 1);
  return 0;
}
/*
2022/6/16
start coding at 14:36
finish debugging at 14:56
*/