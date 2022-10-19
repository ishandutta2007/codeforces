#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
void solve() {
  int xa, ya, xb, yb, xf, yf;
  cin >> xa >> ya >> xb >> yb >> xf >> yf;
  int ans=abs(xa-xb)+abs(ya-yb);
  if(xa==xb && xa==xf) {
    if(ya<yf && yf<yb || ya>yf && yf>yb) ans+=2;
  } else if(ya==yb && ya==yf) {
    if(xa<xf && xf<xb || xa>xf && xf>xb) ans+=2;
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _;
  cin >> _;
  while(_--) solve();
}