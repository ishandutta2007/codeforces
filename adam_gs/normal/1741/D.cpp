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
  int m;
  cin >> m;
  vector<int>T(m);
  rep(i, m) {
    cin >> T[i]; --T[i];
  }
  int ans=0;
  while(T.size()>1) {
    rep(i, T.size()/2) if(abs(T[2*i]-T[2*i+1])>1) {
      cout << -1 << '\n';
      return;
    }
    vector<int>tmp;
    rep(i, T.size()/2) {
      if(T[2*i]>T[2*i+1]) {
        swap(T[2*i], T[2*i+1]);
        ++ans;
      }
      if(T[2*i]%2==1) {
        cout << -1 << '\n';
        return;
      }
      tmp.pb(T[2*i]/2);
    }
    T=tmp;
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _=1;
  cin >> _;
  while(_--) solve();
}