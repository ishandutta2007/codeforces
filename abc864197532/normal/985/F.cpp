#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto y : a) cout << y << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 500001, logN = 17, K = 350, y = 899030292;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  string s;
  cin >> n >> q >> s;
  lli p1[n + 1], p2[n + 1];
  p1[0] = p2[0] = 1;
  fop (i,0,n) p1[i + 1] = p1[i] * x % mod, p2[i + 1] = p2[i] * y % mod;
  lli preha1[n + 1][26], preha2[n + 1][26];
  fop (i,0,26) preha1[0][i] = preha2[0][i] = 0;  
  fop (i,0,n) {
    fop (j,0,26) {
      preha1[i + 1][j] = (preha1[i][j] * x + (s[i] - 'a' == j)) % mod;
      preha2[i + 1][j] = (preha2[i][j] * y + (s[i] - 'a' == j)) % mod;
    }
  }
  while (q--) {
    int x, y, len;
    cin >> x >> y >> len;
    x--; y--;
    vector <pll> aa(26), bb(26);
    fop (i,0,26) {
      aa[i].X = (preha1[x + len][i] + mod - (preha1[x][i] * p1[len] % mod)) % mod;
      aa[i].Y = (preha2[x + len][i] + mod - (preha2[x][i] * p2[len] % mod)) % mod;
      bb[i].X = (preha1[y + len][i] + mod - (preha1[y][i] * p1[len] % mod)) % mod;
      bb[i].Y = (preha2[y + len][i] + mod - (preha2[y][i] * p2[len] % mod)) % mod;
    }
    sort(all(aa));
    sort(all(bb));
    cout << (aa == bb ? "YES\n" : "NO\n");
  }
}