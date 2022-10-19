#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ll INF=1e9+7;
ll ile(ll x) {
  ll po=0, ko=INF;
  while(po<ko) {
    ll sr=(po+ko+1)/2;
    if(sr*(sr+1)<=x) po=sr; else ko=sr-1;
  }
  ll p=0, k=INF;
  while(p<k) {
    ll sr=(p+k+1)/2;
    if(sr*sr<=x) p=sr; else k=sr-1;
  }
  ll p2=0, k2=INF;
  while(p2<k2) {
    ll sr=(p2+k2+1)/2;
    if(sr*(sr+2)<=x) p2=sr; else k2=sr-1;
  }
  return po+p+p2;
}
void solve() {
  ll l, r;
  cin >> l >> r;
  cout << ile(r)-ile(l-1) << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _=1;
  cin >> _;
  while(_--) solve();
}