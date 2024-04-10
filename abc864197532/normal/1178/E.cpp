#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
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
const int mod = 998244353, x = 864197532, N = 300000, logN = 17;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  string a;
  int i = 0, j = s.length() - 1;
  while (j - i > 2) {
    fop (ii,i,i+2) fop (jj,j-1,j+1) {
      if (s[ii] == s[jj]) {
        a.pb(s[ii]);
        goto end;
      }
    }
    end:
    i += 2;
    j -= 2;
  }
  string mid;
  if (i <= j) mid = s[i];
  cout << a << mid;
  reverse(all(a));
  cout << a << endl;
}