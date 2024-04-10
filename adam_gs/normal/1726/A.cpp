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
  int ma=-INF, mi=INF, ans=-INF;
  int n;
  cin >> n;
  int T[n];
  rep(i, n) cin >> T[i];
  rep(i, n-1) {
    ma=max(ma, T[i+1]);
    mi=min(mi, T[i]);
  }
  rep(i, n) ans=max(ans, T[(i+n-1)%n]-T[i]);
  ans=max(ans, max(T[n-1]-mi, ma-T[0]));
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _=1;
  cin >> _;
  while(_--) solve();
}