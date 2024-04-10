#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define fi first
#define se second
bool Mbe;
constexpr int N = 1e5 + 5;
constexpr int mod = 998244353;
void add(int &x, int y) {x += y, x >= mod && (x -= mod);}
int n, a[N];
void solve() {
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  vector<pii> cur, nw;
  cur.push_back({a[n], 1});
  int ans = 0;
  for(int i = n - 1; i; i--, cur = nw) {
    nw.clear(), reverse(cur.begin(), cur.end());
    for(int l = 1, r; l <= N; l = r + 1) {
      int split = (a[i] - 1) / l + 1;
      r = split > 1 ? (a[i] - 1) / (split - 1) : N;
      int val = split == 1;
      while(!cur.empty() && cur.back().fi <= r) add(val, cur.back().se), cur.pop_back();
      add(ans, 1ll * val * (split - 1) % mod * i % mod);
      nw.push_back({a[i] / split, val});
    }
  }
  cout << ans << "\n";
}
bool Med;
int main() {
  fprintf(stderr, "%.4lf\n", (&Mbe - &Med) / 1048576.0);
#ifdef ALEX_WEI
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);
#endif
  int T;
  cin >> T;
  while(T--) solve();
  return cerr << "Time: " << clock() << "\n", 0;
}
/*
2022/7/2
start coding at 19:27
finish debugging at 19:42
*/