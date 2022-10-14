#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x;
#define print(a) {\
    for (auto i : a) cout << i << ' ';\
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
const int mod = 998244353, x = 864197532, N = 100087;

int main () {
  int n, m;
  cin >> n >> m;
  bool is = true;
  fop (i,0,m) {
    bool iss = false;
    vector <int> s(n + 1, 0);
    int k, tmp;
    cin >> k;
    fop (j,0,k) {
      cin >> tmp;
      if (tmp < 0) s[-tmp] |= 1;
      else s[tmp] |= 2;
    }
    fop (i,1,n+1) if (s[i] == 3) iss = true;
    is &= iss;
  }
  cout << (is ? "NO" : "YES") << endl;
}