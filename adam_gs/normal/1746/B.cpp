#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
  int n;
  cin >> n;
  int T[n], zer[n+2], jed[n+2];
  rep(i, n+2) zer[i]=jed[i]=0;
  rep(i, n) cin >> T[i];
  rep(i, n) {
    zer[i+1]=zer[i]+T[i];
  }
  for(int i=n-1; i>=0; --i) {
    jed[i]=jed[i+1]+1-T[i];
  }
  int ans=n;
  rep(i, n+1) ans=min(ans, max(zer[i], jed[i]));
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _=1;
  cin >> _;
  while(_--) solve();
}