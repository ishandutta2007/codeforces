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

set <int> s;
multiset <int> d;

void out() {
  if (s.size() <= 2) cout << 0 << endl;
  else cout << *--s.end() - *s.begin() - *--d.end() << endl;
}

void eras(int x) {
  d.erase(d.lower_bound(x));
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector <int> a(n);
  fop (i,0,n) cin >> a[i], s.insert(a[i]);
  sort(all(a));
  fop (i,1,n) d.insert(a[i] - a[i - 1]);
  out();
  while (q--) {
    int t, x;
    cin >> t >> x;
    if (t) {
      if (s.empty()) {
        s.insert(x);
      } else if (x < *s.begin()) {
        d.insert(*s.begin() - x);
        s.insert(x);
      } else if (*--s.end() < x) {
        d.insert(x - *--s.end());
        s.insert(x);
      } else {
        auto it = s.lower_bound(x);
        int b = *it, a = *--it;
        eras(b - a);
        d.insert(x - a);
        d.insert(b - x);
        s.insert(x);
      }
    } else {
      if (s.size() == 1) {
        s.erase(x);
      } else if (x == *s.begin()) {
        s.erase(x);
        eras(*s.begin() - x);
      } else if (*--s.end() == x) {
        s.erase(x);
        eras(x - *--s.end());
      } else {
        s.erase(x);
        auto it = s.lower_bound(x);
        int b = *it, a = *--it;
        d.insert(b - a);
        eras(x - a);
        eras(b - x);
      }
    }
    out();
  }
}