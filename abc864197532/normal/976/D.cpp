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
#define pdd pair<ld,ld>
typedef long double ld;
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<lli,null_type,less<lli>,rb_tree_tag,tree_order_statistics_node_update>
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 100087, logN = 17, K = 500;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  fop (i,0,n) cin >> a[i];
  int m = a[n - 1] + 1;
  int pre = 0, ans[1001][1001], has = 0;
  fop (i,0,m) fop (j,0,m) ans[i][j] = 0;
  function<void(vector<int>)> solve = [&](vector <int> a) {
    int k = a.back(); a.pop_back();
    if (a.empty()) {
      fop (i,m - k - 1,m) fop (j,i + 1,m) ans[i][j] = 1;
    } else {
      for (int &i : a) i = k - i;
      reverse(all(a));
      solve(a);
      fop (i,m - k - 1,m) fop (j,i + 1,m) ans[i][j] ^= 1;
    }
  };
  solve(a);
  int cnt = 0;
  fop (i,0,m) fop (j,0,m) if (ans[i][j]) {
    cnt++;
  }
  cout << cnt << endl;
  fop (i,0,m) fop (j,0,m) if (ans[i][j]) {
    cout << i + 1 << ' ' << j + 1 << endl;
  }
}