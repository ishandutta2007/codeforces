#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ll INF=1e18+7;
const int LIM=1e5+7;
vector<pair<ll,ll>>X, Y, V[LIM];
pair<ll,ll>T[LIM];
ll odl[LIM];
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  ll x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  rep(i, m) {
    cin >> T[i].st >> T[i].nd;
    X.pb({T[i].st, i});
    Y.pb({T[i].nd, i});
  }
  sort(all(X));
  sort(all(Y));
  if(X.size()) rep(i, X.size()-1) {
    V[X[i].nd].pb({X[i+1].nd, X[i+1].st-X[i].st});
    V[X[i+1].nd].pb({X[i].nd, X[i+1].st-X[i].st});
  }
  if(Y.size()) rep(i, Y.size()-1) {
    V[Y[i].nd].pb({Y[i+1].nd, Y[i+1].st-Y[i].st});
    V[Y[i+1].nd].pb({Y[i].nd, Y[i+1].st-Y[i].st});
  }
  priority_queue<pair<ll,int>>q;
  rep(i, m) {
    odl[i]=INF;
    q.push({-min(abs(x1-T[i].st), abs(y1-T[i].nd)), i});
  }
  ll ans=abs(x1-x2)+abs(y1-y2);
  while(!q.empty()) {
    ll o=-q.top().st, p=q.top().nd; q.pop();
    if(odl[p]<=o) continue;
    odl[p]=o;
    ans=min(ans, o+abs(x2-T[p].st)+abs(y2-T[p].nd));
    for(auto i : V[p]) if(odl[i.st]==INF) q.push({-o-i.nd, i.st});
  }
  cout << ans << '\n';
}