/*
 * @Author: Kaizyn
 * @Date: 2022-04-13 16:38:37
 * @LastEditTime: 2022-04-13 17:09:08
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;
namespace hjt {
template<typename A,typename B>
std::ostream &operator<<(std::ostream &o,const std::pair<A,B> &x){
  return o<<'('<<x.first<<','<<x.second<<')';
}
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define qwq [&]{cerr<<"qwq"<<endl;}()
#define orz(x) [&]{cerr<<#x": "<<x<<endl;}()
#define orzarr(a,n) [&]{cerr<<#a": "; repeat(__,0,n)cerr<<(a)[__]<<" "; cerr<<endl;}()
#define orzeach(a) [&]{cerr<<#a": "; for(auto __:a)cerr<<__<<" "; cerr<<endl;}()
#define pause [&]{system("pause");}()
} using namespace hjt;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
const int N = 2e2 + 7;

int n;
int c[N][N], fa[N], rt[N][N];
ll s[N][N], dp[N][N];

void build_tree(int l, int r, int root) {
  if (l > r) return;
  int k = rt[l][r];
  #ifdef DEBUG
  printf("build_tree(%d,%d,%d),k=%d\n", l, r, root, k);
  #endif
  // if (!k) return;
  fa[k] = root;
  build_tree(l, k - 1, k);
  build_tree(k + 1, r, k);
}

ll sum_rec(int xl, int xr, int yl, int yr) {
  // if (xl > xr) return 0;
  return s[xr][yr] - s[xl - 1][yr] - s[xr][yl - 1] + s[xl - 1][yl - 1];
}

ll calc(int l, int r) {
  if (l > r) return 0;
  return s[r][n] - s[l - 1][n] - sum_rec(l, r, l, r);
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> c[i][j];
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + c[i][j];
    }
  }
  for (int len = 1; len <= n; ++len) {
    for (int l = 1, r; (r = l + len - 1) <= n; ++l) {
      dp[l][r] = inf<ll>;
      for (int k = l; k <= r; ++k) {
        ll val = dp[l][k - 1] + calc(l, k - 1)
               + dp[k + 1][r] + calc(k + 1, r);
        if (val < dp[l][r]) {
          dp[l][r] = val;
          rt[l][r] = k;
        }
      }
    }
  }
  build_tree(1, n, 0);
  for (int i = 1; i <= n; ++i) {
    cout << fa[i] << " \n"[i == n];
  }
  #ifdef DEBUG
  orz(dp[1][n]);
  #endif
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}