/*
 * @Author: Kaizyn
 * @Date: 2022-02-26 12:49:40
 * @LastEditTime: 2022-02-26 13:21:11
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
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 5e2 + 7;

int n, m;
char s[N], t[N];
int nex[N];
int dp[2][N][N], ans[N];
// dp[i][j][k] : match on s[i], gain j's match, match on t[k], the minimum cost

inline void get_next(const char *s, int nex[]) {
  nex[0] = nex[1] = 0;
  for (int i = 1, j = 0, l = strlen(s); i < l; ++i) {
    while (j && s[i] != s[j]) j = nex[j];
    nex[i+1] = s[i] == s[j] ? ++j : 0;
  }
}

inline void kmp(const char *s1, const char *s2, int nex[]) {
  for (int i = 0, j = 0, l1 = strlen(s1), l2 = strlen(s2); i < l1; ++i){
    while (j && s1[i] != s2[j]) j = nex[j];
    if (s1[i] == s2[j]) ++j;
    if (j == l2) {
      cout << i-l2+2 << endl;
      j = nex[j];
    }
  }
}

void update(int &x, int y) {
  if (x == -1 || y < x) x = y;
}

inline void solve() {
  cin >> n >> m >> s >> t;
  get_next(t, nex);
  dp[0][0][0] = 0;
  for (int i = 0; i < n; ++i) {
    memset(dp[~i & 1], -1, sizeof dp[0]);
    for (int j = 0; j <= n - m; ++j) {
      for (int k = 0; k < m; ++k) if (~dp[i & 1][j][k]) {
        for (char c : {'0', '1'}) {
          int nk = k, nj = j;
          while (nk && c != t[nk]) nk = nex[nk];
          if (c == t[nk]) ++nk;
          if (nk == m) {
            ++nj;
            nk = nex[nk];
          }
          update(dp[~i & 1][nj][nk], dp[i & 1][j][k] + (c != s[i]));
          #ifdef DEBUG
          printf("dp[%d][%d][%d](%d)=dp[%d][%d](%d)+%c\n",
              i + 1, nj, nk, dp[~i & 1][nj][nk], j, k, dp[i & 1][j][k], c);
          #endif
        }
      }
    }
  }
  memset(ans, -1, sizeof ans);
  for (int j = 0; j <= n - m + 1; ++j) {
    for (int k = 0; k < m; ++k) if (~dp[n & 1][j][k]) {
      update(ans[j], dp[n & 1][j][k]);
    }
  }
  for (int i = 0; i <= n - m + 1; ++i) {
    cout << ans[i] << " \n"[i == n - m + 1];
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  memset(dp, -1, sizeof dp);
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}