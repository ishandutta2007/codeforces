#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
  ll n, x;
  cin >> n >> x;
  ll T[n], sum=0, ans=0;
  rep(i, n) {
    cin >> T[i];
    sum+=T[i];
  }
  sort(T, T+n);
  for(ll i=n-1; i>=0; --i) {
    if(sum<=x) ans+=(x-sum)/(i+1)+1;
    sum-=T[i];
  }
  cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int _=1;
  cin >> _;
  while(_--) solve();
}