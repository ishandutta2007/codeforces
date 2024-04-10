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
const int mod = 1e9 + 7, x = 864197532, N = 300087, logN = 17, K = 500;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  if (n == 4) {
    if (k == 3) {
      cout << "3\n1 2\n2 3\n3 4\n";
    } else {
      cout << -1 << endl;
    }
    return 0;
  }
  if (n <= 3 || k >= n - 1 || k == 1) {
    cout << -1 << endl;
    return 0;
  }
  if (k == 2) {
    cout << 3 + (n - 2) * (n - 3) / 2 << endl;
    for (int i = 0; i < 4; ++i) {
      cout << i + 1 << ' ' << (i + 1) % 4 + 1 << endl;
    }
    for (int i = 2; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (i == 2 && j == 3) continue;
        cout << i + 1 << ' ' << j + 1 << endl;
      }
    }
    return 0;
  }
  if (k == 3) {
    cout << n - 1 << endl;
    for (int i = 1; i < n - 1; ++i) {
      cout << 1 << ' ' << i + 1 << endl;
    }
    cout << n << ' ' << 2 << endl;
    return 0;
  }
  cout << -1 << endl;
}