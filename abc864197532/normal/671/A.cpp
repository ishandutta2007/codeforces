#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define print(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pdd pair<ld,ld> 
#define ld long double
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 500007, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  lli x1, y1, x2, y2, x0, y0;
  cin >> x1 >> y1 >> x2 >> y2 >> x0 >> y0;
  int n;
  cin >> n;
  vector <pll> v(n);
  auto dis = [&](lli a, lli b, lli c, lli d) {
    return sqrt((a - b) * (a - b) + (c - d) * (c - d));
  };
  ld now1, now2;
  int id, id2;
  now1 = now2 = -1ll << 60;
  fop (i,0,n) {
    cin >> v[i].X >> v[i].Y;
    ld aa = dis(v[i].X, x0, v[i].Y, y0) - dis(v[i].X, x1, v[i].Y, y1);
    if (now1 < aa) {
      now2 = now1;
      now1 = aa;
      id2 = id;
      id = i;
    } else if (now2 < aa) {
      now2 = aa;
      id2 = i;
    }
  }
  ld now = now1;
  fop (i,0,n) {
    if (id == i) now = max(now, now2 + dis(v[i].X, x0, v[i].Y, y0) - dis(v[i].X, x2, v[i].Y, y2));
    else now = max(now, now1 + dis(v[i].X, x0, v[i].Y, y0) - dis(v[i].X, x2, v[i].Y, y2));
  }
  now1 = -1ll << 60;
  fop (i,0,n) {
    cin >> v[i].X >> v[i].Y;
    ld aa = dis(v[i].X, x0, v[i].Y, y0) - dis(v[i].X, x2, v[i].Y, y2);
    if (now1 < aa) {
      now1 = aa;
    }
  }
  now = max(now, now1);
  now = -now;
  fop (i,0,n) now += dis(v[i].X, x0, v[i].Y, y0) * 2;
  cout << fixed << setprecision(10) << now << endl;
}