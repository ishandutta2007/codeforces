#include <bits/stdc++.h>
using namespace std;
bool Mbe;
constexpr int N = 2e5 + 5;
int n, a[N], occ[N], val[N << 1], ans;
vector<int> buc[N];
int P(int v, int p) {return p == buc[v].size() ? n + 1 : buc[v][p];}
bool Med;
int main() {
  fprintf(stderr, "%.4lf\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
  #endif
  ios::sync_with_stdio(0);
  memset(val, 0x3f, sizeof(val)), val[N] = 0;
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i], buc[a[i]].push_back(i);
  int mx = 0, oc = 0, id;
  for(int i = 1; i <= n; i++)
    if(buc[i].size() > mx) mx = buc[i].size(), oc = 1, id = i;
    else oc += buc[i].size() == mx;
  if(oc >= 2) cout << n << endl, exit(0);
  for(int it : buc[id]) occ[it] = 1;
  for(int i = 1; i <= n + 1; i++) occ[i] += occ[i - 1];
  for(int i = 1; i <= n; i++) {
    if(i == id) continue;
    if(buc[i].empty()) continue;
    static int w[N], suf[N], modi[N];
    int cnt = 0;
    for(int p = 0; p < buc[i].size(); p++) w[p] = occ[buc[i][p]] - p - 1;
    suf[buc[i].size()] = w[buc[i].size()] = buc[id].size() - buc[i].size();
    for(int p = buc[i].size() - 1; ~p; p--) suf[p] = min(w[p], suf[p + 1]);
    auto upd = [&](int v, int p, int q) {
      if(val[N + v] > N) modi[++cnt] = N + v, val[N + v] = p;
      ans = max(ans, q - val[N + v]);
    };
    for(int p = 0; p <= buc[i].size(); p++) {
      int pre = p ? buc[i][p - 1] : 0, cur = p < buc[i].size() ? buc[i][p] : n + 1;
      int pos = occ[pre], num = occ[cur] - occ[pre], acc = p ? w[p - 1] : 0;
      int skip = max(0, suf[p] - acc - 1);
      for(int q = 1; q <= skip; q++) {
        if(val[N + acc + q] > N) break;
        upd(acc + q, buc[id][pos + q - 1], min(cur, P(id, pos + q)) - 1);
      }
      for(int q = skip + 1; q <= num; q++) upd(acc + q, buc[id][pos + q - 1], min(cur, P(id, pos + q)) - 1);
      if(p < buc[i].size()) upd(acc + num - 1, cur, min(P(id, pos + num), P(i, p + 1)) - 1);
    }
    for(int p = 1; p <= cnt; p++) val[modi[p]] = 1e9;
  }
  cout << ans << endl;
  return cerr << "Time: " << clock() << "\n", 0;
}
/*
2022/7/10
start coding at
finish debugging at 10:19
*/