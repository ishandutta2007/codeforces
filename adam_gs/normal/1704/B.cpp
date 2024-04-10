#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int INF=1e9+7;
void solve() {
  int n, x;
  cin >> n >> x;
  int ans=0, ma=-INF, mi=INF;
  rep(i, n) {
    int a;
    cin >> a;
    ma=max(ma, a);
    mi=min(mi, a);
    if((ma-mi+1)/2>x) {
      ma=a; mi=a;
      ++ans;
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _;
  cin >> _;
  while(_--) solve();
}