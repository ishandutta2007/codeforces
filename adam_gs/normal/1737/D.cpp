#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ll INF=1e18+7;
const int LIM=507;
vector<pair<ll,ll>>V[LIM];
pair<pair<ll,ll>,ll>kraw[LIM*LIM];
ll odl[LIM][LIM];
void solve() {
  int n, m;
  cin >> n >> m;
  rep(i, n) V[i].clear();
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c; --a; --b;
    kraw[i]={{a, b}, c};
    V[a].pb({b, c});
    V[b].pb({a, c});
  }
  rep(i, n) rep(j, n) odl[i][j]=INF;
  odl[0][n-1]=odl[n-1][0]=1;
  queue<pair<int,int>>q;
  q.push({0, n-1});
  q.push({n-1, 0});
  while(!q.empty()) {
    int a=q.front().st, b=q.front().nd; q.pop();
    for(auto i : V[b]) if(odl[a][i.st]==INF) {
      odl[a][i.st]=odl[a][b]+1;
      q.push({a, i.st});
    }
    for(auto i : V[a]) if(odl[i.st][b]==INF) {
      odl[i.st][b]=odl[a][b]+1;
      q.push({i.st, b});
    }
    if(a==b) {
      rep(i, n) {
        if(odl[a][i]==INF) {
          odl[a][i]=odl[a][a]+1;
          q.push({a, i});
        } 
        if(odl[i][a]==INF) {
          odl[i][a]=odl[a][a]+1;
          q.push({i, a});
        }
      }
    }
  }
  ll ans=INF;
  rep(i, m) ans=min(ans, odl[kraw[i].st.st][kraw[i].st.nd]*kraw[i].nd);
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _=1;
  cin >> _;
  while(_--) solve();
}