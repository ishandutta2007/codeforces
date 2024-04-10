#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ll INF=1e9+7;
void solve() {
  ll n, x, ma=-INF, mi=INF, ans=0;
  cin >> n >> x;
  ll T[n];
  rep(i, n) {
    cin >> T[i];
    ma=max(ma, T[i]);
    mi=min(mi, T[i]);
    if(i) ans+=abs(T[i]-T[i-1]);
  }
  ans+=min(min(T[0], T[n-1])-1, 2*(mi-1));
  if(ma<x) ans+=min(x-max(T[0], T[n-1]), 2*(x-ma));
  cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int _=1;
  cin >> _;
  while(_--) solve();
}