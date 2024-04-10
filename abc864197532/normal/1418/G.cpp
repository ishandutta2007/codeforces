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
const int mod = 1e9 + 7, x = 864197532, N = 50087, logN = 17, K = 222;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  vector <lli> ha1(n), pre1(n + 1, 0), ha2(n), pre2(n + 1, 0);
  fop (i,0,n) ha1[i] = uniform_int_distribution(1 << 10, 1 << 30)(rng);
  fop (i,0,n) ha2[i] = uniform_int_distribution(1 << 10, 1 << 30)(rng);
  vector <int> cnt(n, 0);
  fop (i,0,n) {
    cin >> a[i], a[i]--;
    cnt[a[i]]++;
    if (cnt[a[i]] % 3) pre1[i + 1] = pre1[i] + ha1[a[i]], pre2[i + 1] = pre2[i] + ha2[a[i]];
    else pre1[i + 1] = pre1[i] - ha1[a[i]] * 2, pre2[i + 1] = pre2[i] - ha2[a[i]] * 2;
  }
  map <pll, int> m1;
  deque <int> dq[n];
  int j = 0, mx = 0;
  m1[{0, 0}]++;
  lli ans = 0;
  fop (i,0,n) {
    dq[a[i]].pb(i);
    if (dq[a[i]].size() == 6) mx = max(mx, dq[a[i]].front() + 2), dq[a[i]].pop_front();
    while (j < mx) m1[{pre1[j], pre2[j++]}]--;
    ans += m1[{pre1[i + 1], pre2[i + 1]}];
    m1[{pre1[i + 1], pre2[i + 1]}]++;
  }
  cout << ans << endl;
}