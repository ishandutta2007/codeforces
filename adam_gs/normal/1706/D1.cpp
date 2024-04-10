#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=3e3+7;
vector<pair<int,int>>V[LIM]; 
int T[LIM], P[LIM];
void solve() {
  rep(i, LIM) V[i].clear();
  int n, k, mi=LIM, ans=LIM;
  cin >> n >> k;
  rep(i, n) {
    cin >> P[i];
    T[P[i]]=1;
    mi=min(mi, P[i]);
  }
  for(int i=1; i<LIM; ++i) {
    if(!T[i]) continue;
    for(int j=2; j<=i+1; ++j) {
      if(i/(j-1)>i/j) V[i/(j-1)].pb({i, j});
    }
  }
  for(int i=LIM-1; i>=0; --i) {
    ans=min(ans, i-mi);
    for(auto j : V[i]) {
      mi=min(mi, j.st/j.nd);
      if(j.nd>k) {
        i=0;
        break;
      }
    }
  }
  cout << ans << '\n';
  rep(i, n) T[P[i]]=0;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _;
  cin >> _;
  while(_--) solve();
}