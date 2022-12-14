/*
 * @Author: Kaizyn
 * @Date: 2022-04-13 16:12:00
 * @LastEditTime: 2022-04-13 16:21:06
 */
#include <bits/stdc++.h>

#define DEBUG

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
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
// const int N = ;

pii a[3];
vector<array<int, 4>> ans;

inline void solve() {
  for (int i : {0, 1, 2}) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a, a + 3);
  if (a[0].second == a[1].second && a[1].second == a[2].second) {
    cout << "1\n";
    int y = a[0].second;
    cout << a[0].first << ' ' << y << ' ' << a[2].first << ' ' << y << '\n';
    return;
  }
  int yl = min({a[0].second, a[1].second, a[2].second});
  int yr = max({a[0].second, a[1].second, a[2].second});
  if (yl < yr) ans.push_back({a[1].first, yl, a[1].first, yr});
  if (a[0].first < a[1].first) ans.push_back({a[0].first, a[0].second, a[1].first, a[0].second});
  if (a[2].first > a[1].first) ans.push_back({a[1].first, a[2].second, a[2].first, a[2].second});

  cout << ans.size() << '\n';
  for (auto arr : ans) {
    for (int i : arr) cout << i << ' ';
    cout << '\n';
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}