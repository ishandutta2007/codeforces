#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
void solve() {
  int n, T[4];
  cin >> n;
  rep(i, 4) cin >> T[i];
  rep(i, 1<<4) {
    int P[4];
    rep(j, 4) if(i&(1<<j)) P[j]=1; else P[j]=0;
    bool ok=true;
    rep(j, 4) if(T[j]<P[j]+P[(j+1)%4] || P[j]+P[(j+1)%4]+n-2<T[j]) ok=false;
    if(ok) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _;
  cin >> _;
  while(_--) solve();
}