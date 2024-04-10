#include <bits/stdc++.h>
#define LOG(FMT...) fprintf(stderr, FMT);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
// typedef long double db;
typedef unsigned int uint;
typedef unsigned long long ull;
mt19937 mt(std::chrono::system_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> ran(0, 1ll << 62);
void ucin() { ios::sync_with_stdio(0); cin.tie(0); }
// uniform_real_distribution<double> dbran;
template<class T> inline void chkmax(T &x, const T &y) { if(x < y) x = y; }
template<class T> inline void chkmin(T &x, const T &y) { if(x > y) x = y; }
inline ll sqr(ll x) { return x * x; }
inline ll cub(ll x) { return x * x * x; }

const int N = 1e5 + 10;
int n, d, a[N], p[N][10];
db f[N][10];
bool use[N][10], vis[N][10];
vector<int> ans;
void F(int n, int d) {
  if(n == 0) return ;
  if(use[n][d]) ans.pb(a[n]);
  F(n - 1, p[n][d]);
}
int main() {
  scanf("%d%d", &n, &d);
  rep(i, 1, n) scanf("%d", a + i);
  f[0][1] = log(1);
  vis[0][1] = 1;
  rep(i, 1, n) {
    db r = log(a[i]);
    rep(j, 0, 9) if(vis[i - 1][j]) {
      vis[i][j] = 1;
      f[i][j] = f[i - 1][j];
      p[i][j] = j;
      use[i][j] = 0;
    }
    rep(j, 0, 9) if(vis[i - 1][j]) {
      int nxt = j * a[i] % 10;
      vis[i][nxt] = 1;
      if(f[i - 1][j] + r >= f[i][nxt]) {
        f[i][nxt] = f[i - 1][j] + r;
        p[i][nxt] = j;
        use[i][nxt] = 1;
      }
    }
  }
  if(!vis[n][d]) { puts("-1"); return 0; }
  F(n, d);
  if(!ans.size()) {
    rep(i, 1, n) if(a[i] == 1) ans.pb(1);
    if(d == 1 && ans.size()) {
      goto out;
    }
    puts("-1"); return 0;
  }
  out:
  printf("%lu\n", ans.size());
  for(int v : ans) {
    printf("%d ", v);
  }
  puts("");
  return 0;
}