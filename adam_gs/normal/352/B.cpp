#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=1e5+7;
vector<int>V[LIM];
void solve() {
  int n;
  cin >> n;
  rep(i, n) {
    int a;
    cin >> a; --a;
    V[a].pb(i);
  }
  vector<pair<int,int>>ans;
  rep(i, LIM) if(V[i].size()) {
    if(V[i].size()==1) {
      ans.pb({i, 0});
      continue;
    }
    int p=V[i][1]-V[i][0];
    bool ok=true;
    for(int j=2; j<V[i].size(); ++j) {
      if(V[i][j]-V[i][j-1]!=p) ok=false;
    }
    if(ok) ans.pb({i, p});
  }
  cout << ans.size() << '\n';
  for(auto i : ans) cout << i.st+1 << " " << i.nd << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _=1;
  //cin >> _;
  while(_--) solve();
}