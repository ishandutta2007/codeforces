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
const int mod = 998244353, x = 864197532, N = 2000007, logN = 17;

int main () {
  int n;
  cin >> n;
  vector <int> a(n);
  fop (i,0,n) cin >> a[i];
  a.pb(0);
  sort(all(a));
  a.resize(unique(all(a)) - a.begin());
  vector <int> b(N);
  fop (i,1,N) b[i] = a[upper_bound(all(a), i) - a.begin() - 1];
  int ans = 0, now = 1;
  fop (i,1,N) if (now < a.size() && a[now] == i) {
    for (int j = i + i; j < N; j += i) {
      if (b[j - 1] > i) ans = max(ans, b[j - 1] % i);
    }
    now++;
  }
  cout << ans << endl;
}