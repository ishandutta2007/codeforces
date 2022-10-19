#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
  ll n, k;
  cin >> n >> k;
  ll T[n];
  rep(i, n) cin >> T[i];
  sort(T, T+n);
  ll ans=0;
  rep(i, n) {
    while(k*2<T[i]) {
      k*=2;
      ++ans;
    }
    k=max(k, T[i]);
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _=1;
  //cin >> _;
  while(_--) solve();
}