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
  int n, m;
  cin >> n >> m;
  vector<ll>V[n];
  rep(i, n) rep(j, m) {
    ll a;
    cin >> a;
    V[i].pb(a);
  }
  for(int i=1; i<n; ++i) {
    ll suma=0, sumb=0, akta=0, aktb=0;
    rep(j, m) {
      akta+=V[0][j];
      aktb+=V[i][j];
      suma+=akta;
      sumb+=aktb;
    }
    if(suma<sumb) {
      cout << 1 << " " << sumb-suma << '\n';
      return;
    } 
    if(suma>sumb) {
      cout << i+1 << " " << suma-sumb << '\n';
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _;
  cin >> _;
  while(_--) solve();
}